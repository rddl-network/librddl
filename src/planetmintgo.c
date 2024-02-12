#include <stdio.h>

#include "sha2.h"
#include "ripemd160.h"
#include "base32.h"
#include "rddl.h"
#include "rddl_cid.h"
#include "ecdsa.h"
#include "secp256k1.h"
#include "segwit_addr.h"

#include "planetmintgo.h"
#include "protobuf_abst.h"

#define COMPACT_SIG_MAGIC_OFFSET (27)

void pubkey2address(const uint8_t *pubkey, size_t key_length, uint8_t *address)
{
    SHA256_CTX ctx;
    uint8_t ripemd160_hash[RIPEMD160_DIGEST_LENGTH] = {0};

    uint8_t hash[SHA256_DIGEST_LENGTH] = {0};
    sha256_Init(&ctx);
    // Hash the string
    sha256_Update(&ctx, pubkey, key_length);
    sha256_Final(&ctx, hash);

    ripemd160((const uint8_t *)hash, SHA256_DIGEST_LENGTH, ripemd160_hash);
    memcpy(address, ripemd160_hash, 20);
}

int getAddressString(const uint8_t *address, char *stringbuffer)
{
    const char *hrp = "plmnt";
    size_t data_len = 32;
    uint8_t paddingbuffer[32] = {0};
    uint8_t base32_enc[100] = {0};
    base32_encode_unsafe(address, 20, base32_enc);

    size_t len = strlen((const char*)base32_enc);
    return bech32_encode(stringbuffer, hrp, base32_enc, data_len);
}

size_t roll_up_to_divisible_by_16(int num) {
    // Calculate the remainder when dividing num by 16
    size_t remainder = num % 16;
    
    // If remainder is non-zero, increase num to make it divisible by 16
    if (remainder != 0) {
        num += (16 - remainder);
    }
    
    return num;
}

size_t myStackSize = 0;
volatile uint8_t myStack[MY_STACK_LIMIT] = {0};

uint8_t* getStack( size_t gsize )
{
    size_t size = roll_up_to_divisible_by_16(gsize);
    if (myStackSize + size > MY_STACK_LIMIT)
        return NULL;

    uint8_t* current_ptr = (uint8_t*)&myStack[myStackSize];
    myStackSize += size;
    return current_ptr;
}

void clearStack()
{
    myStackSize = 0;
}


int prepareTx( void* anyMsg, void* coin, 
        uint8_t *priv_key, uint8_t *pub_key,
        uint64_t sequence, const char *chain_id, uint64_t account_id,
        uint8_t** tx_bytes, size_t* tx_size)
{
    void* messages[1] = {anyMsg};
    void* body = fullfill_cosmos_tx_v1beta1_txBody(messages, 1, 0);

    void* any_pub_key = Create_AnyMsg();
    if(bind_cosmos_sec256k1_pk_to_anyMsg(any_pub_key, pub_key, 33, "/cosmos.crypto.secp256k1.PubKey") == -1)
        return -1;

    void* signInfo = fullfill_cosmos_tx_v1beta1_signerInfo(any_pub_key, sequence);

    void* coins[1]        = {coin};
    void* fee = fullfill_cosmos_tx_v1beta1_fee(coins, 200000);

    void* signer_infos[1] = {signInfo};
    void* auth= fullfill_cosmos_tx_v1beta1_authInfo(fee, signer_infos);

    void* tx = fullfill_cosmos_tx_v1beta1_tx(body, auth);

    void*txRaw = fullfill_cosmos_tx_v1beta1_txRaw(tx);

    int binMessageLen = 0;
    void* binMessage  = fullfill_binMessage(txRaw, chain_id, account_id, &binMessageLen);
    if(binMessage == NULL)
        return -1; 

    uint8_t digest[SHA256_DIGEST_LENGTH] = {0};
    sha256_Raw((const uint8_t*)binMessage, binMessageLen, digest);

    unsigned char signature[64] = {0};
    const ecdsa_curve *curve = &secp256k1;
    ecdsa_sign_digest(curve, (const unsigned char *)priv_key, (const unsigned char *)digest, signature, NULL, NULL);

    if(prepare_txRaw_data(tx_bytes, tx_size, txRaw, signature, 64) == NULL)
        return -1;
    
    return 0;
}

// int generateAnyAttestMachineMsg(Google__Protobuf__Any* anyMsg, Planetmintgo__Machine__MsgAttestMachine* machineMsg)
// {
//     anyMsg->type_url = "/planetmintgo.machine.MsgAttestMachine";
//     anyMsg->value.len = planetmintgo__machine__msg_attest_machine__get_packed_size(machineMsg);
//     anyMsg->value.data = getStack(anyMsg->value.len);
//     if( !anyMsg->value.data )
//         return -1;
//     planetmintgo__machine__msg_attest_machine__pack(machineMsg, anyMsg->value.data);
//     return 0;
// }

// int generateAnyPoPResultMsg(Google__Protobuf__Any* anyMsg, Planetmintgo__Dao__MsgReportPopResult* popResultMsg)
// {
//     anyMsg->type_url = "/planetmintgo.dao.MsgReportPopResult";
//     anyMsg->value.len = planetmintgo__dao__msg_report_pop_result__get_packed_size( popResultMsg );
//     anyMsg->value.data = (uint8_t*)getStack(anyMsg->value.len);
//     if( !anyMsg->value.data )
//         return -1;
//     planetmintgo__dao__msg_report_pop_result__pack(popResultMsg, anyMsg->value.data);
//     return 0;
// }

int generateAnyCIDAttestMsg( void* anyMsg, const char* cid, uint8_t* priv_key, uint8_t* pub_key, char* public_address, const char* ext_pub_key)
{
    void* msg = fullfill_planetmintgo_asset_msgnotarizeasset(cid, public_address);

    if(bind_planetmintgo_asset_notarizeMsg_to_anyMsg(anyMsg, msg) == -1)
        return -1;

    return 0;
}

bool get_account_info( const char* json_obj, int* account_id, int* sequence)
{

    char* end_str = "\"";
    char* search_string = "\"account_number\":\"";

    char account_memory[10]= {0};
    char sequence_memory[10]= {0};

    char* ptr = strstr( json_obj, search_string);
    if( !ptr )
        return false;
    size_t len = strlen(search_string);
    char* endptr = strstr( ptr+ len, end_str );
    memcpy( (void*)account_memory, ptr+ len,endptr-(ptr+len) );


    search_string = "\"sequence\":\"";
    ptr = strstr( json_obj, search_string);
    if( !ptr )
        return false;
    len = strlen(search_string);
    endptr = strstr( ptr+ len, end_str );
    memcpy( (void*)sequence_memory, ptr+ len,endptr-(ptr+len) );

    *account_id = atoi( account_memory );
    *sequence = atoi( sequence_memory );
    return true;
}

bool removeIPAddr( char* gps_data )
{
    char* search_string = ",\"User-IP\":";
    char* substitution_str = "}";
    char* ptr = strstr( gps_data, search_string);
    if( !ptr )
        return false;
    ptr[0]= substitution_str[0];
    ptr[1]=0;
    return true;
}




