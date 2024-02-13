#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdint.h> 
#include <stdlib.h>
#include <stdarg.h>
#include "rddl.h"
#include "rddl_types.h"
#include "configFile.h"
#include "rddlSDKAbst.h"
#include "planetmintgo.h"
#include <pb_encode.h>
#include <planetmintgo/machine/machine.pb.h>
#include <planetmintgo/machine/tx.pb.h>
#include <planetmintgo/asset/tx.pb.h>
#include <planetmintgo/dao/challenge.pb.h>
#include <planetmintgo/dao/tx.pb.h>
#include <google/protobuf/any.pb.h>
#include <cosmos/base/v1beta1/coin.pb.h>
#include <cosmos/tx/v1beta1/tx.pb.h>
#include <cosmos/crypto/secp256k1/keys.pb.h>


char msgAttestMachine_url[] = "/planetmintgo.machine.MsgAttestMachine";
char daoMsgReportPopR_url[] = "/planetmintgo.dao.MsgReportPopResult";


typedef struct call_back_contexts_s{
    int         len;
    char*       data;
}call_back_contexts;


bool encode_array(pb_ostream_t* stream, const pb_field_t* field, void* const* arg)
{
    // ...and you always cast to the same pointer type, reducing
    // the chance of mistakes
    call_back_contexts * ctx = (call_back_contexts *)(*arg);
    
    if (!pb_encode_tag_for_field(stream, field))
        return false;

    return pb_encode_string(stream, (uint8_t*)ctx->data, ctx->len);
}


bool encode_string(pb_ostream_t* stream, const pb_field_t* field, void* const* arg)
{
    
    if (!pb_encode_tag_for_field(stream, field))
        return false;

    return pb_encode_string(stream, (uint8_t*)*arg, strlen(*arg));
}

void* Create_AnyMsg(){
    google_protobuf_Any* anyMsg = (google_protobuf_Any*)getStack( sizeof(google_protobuf_Any) );
    *anyMsg = (google_protobuf_Any) google_protobuf_Any_init_zero;

    return (void*)anyMsg;
}


void* fullfill_planetmintgo_machine_metadata(char* cid, char* gps, char* assetdef, char* device){
    planetmintgo_machine_Metadata* metadata = (planetmintgo_machine_Metadata*)getStack( sizeof(planetmintgo_machine_Metadata) );
    *metadata = (planetmintgo_machine_Metadata) planetmintgo_machine_Metadata_init_zero;

    metadata->additionalDataCID.arg          = (void *)cid;
    metadata->assetDefinition.arg            = (void *)assetdef;
    metadata->device.arg                     = (void *)device;
    metadata->gps.arg                        = (void *)gps;
    //metadata->additionalDataCID.funcs.encode = &encode_string;
    //metadata->gps.funcs.encode               = &encode_string;
    metadata->assetDefinition.funcs.encode     = &encode_string;  
    metadata->device.funcs.encode              = &encode_string; 
    // if(gps[0] != 0)
    //     metadata->gps.funcs.encode          = &encode_string;

    return (void *)metadata;
}


void* fullfill_planetmintgo_machine_machine(void* metadata_ptr, char* signature_hex, char* name, char* issuePlanetmint, 
                                            char* issuerLiquid, char* machineID, uint32_t type){
    planetmintgo_machine_Machine* machine = (planetmintgo_machine_Machine*)getStack( sizeof(planetmintgo_machine_Machine) );
    *machine = (planetmintgo_machine_Machine) planetmintgo_machine_Machine_init_zero;

    machine->name.arg               = name;
    machine->issuerPlanetmint.arg   = issuePlanetmint;
    machine->issuerLiquid.arg       = issuerLiquid;
    machine->machineId.arg          = machineID;
    machine->machineIdSignature.arg = signature_hex;
    machine->address.arg            = name;
    machine->type                   = type;
    machine->has_metadata           = true;
    memcpy(&machine->metadata, metadata_ptr, sizeof(planetmintgo_machine_Metadata));

    machine->name.funcs.encode               = &encode_string;
    machine->issuerPlanetmint.funcs.encode   = &encode_string;
    machine->issuerLiquid.funcs.encode       = &encode_string;
    machine->machineId.funcs.encode          = &encode_string;
    machine->machineIdSignature.funcs.encode = &encode_string;
    machine->address.funcs.encode            = &encode_string;

    return (void *)machine;
}


void* fullfill_planetmintgo_machine_msgAttestMachine(void* machine_ptr, char* creator){
    planetmintgo_machine_MsgAttestMachine* machineMsg = (planetmintgo_machine_MsgAttestMachine*)getStack( sizeof(planetmintgo_machine_MsgAttestMachine));
    *machineMsg = (planetmintgo_machine_MsgAttestMachine) planetmintgo_machine_MsgAttestMachine_init_zero;

    machineMsg->creator.arg          = creator;
    machineMsg->creator.funcs.encode = &encode_string;
    machineMsg->has_machine          = true;
    memcpy(&machineMsg->machine, machine_ptr, sizeof(planetmintgo_machine_Machine));

    return (void *)machineMsg;
}


int bind_msgAttestMachine_to_anyMsg(void* anyMsg, void* machineMsg){    
    int  ret = 0;
    char* tempBuff = (char*)getStack(1024);

    pb_ostream_t machineMsg_stream = pb_ostream_from_buffer((pb_byte_t *)tempBuff, 1024);
    if (!pb_encode(&machineMsg_stream, planetmintgo_machine_MsgAttestMachine_fields, machineMsg))
        ret = -1;

    google_protobuf_Any* anyMsg_ptr    = (google_protobuf_Any*)anyMsg;
    
    call_back_contexts* value_context  = (call_back_contexts*)getStack(sizeof(call_back_contexts));
    value_context->len                 = machineMsg_stream.bytes_written;
    value_context->data                = tempBuff;
    anyMsg_ptr->value.arg              = value_context;
    anyMsg_ptr->type_url.arg           = msgAttestMachine_url;
    anyMsg_ptr->value.funcs.encode     = &encode_array;
    anyMsg_ptr->type_url.funcs.encode  = &encode_string;

    return ret;
}


void* fullfill_cosmos_base_v1beta1_coin(char* denom, char* tokenAmount){
    cosmos_base_v1beta1_Coin* coin = (cosmos_base_v1beta1_Coin*)getStack( sizeof(cosmos_base_v1beta1_Coin));
    *coin = (cosmos_base_v1beta1_Coin) cosmos_base_v1beta1_Coin_init_zero;
    coin->amount.arg          = tokenAmount;
    coin->denom.arg           = denom;
    coin->amount.funcs.encode = &encode_string;
    if(denom[0] != 0)
        coin->denom.funcs.encode  = &encode_string;

    return (void*)coin;
}


void* fullfill_cosmos_tx_v1beta1_txBody(void** msg, int msg_len, int timeout){
    google_protobuf_Any* anyMsg_ptr    = (google_protobuf_Any*)msg[0];
    char* tempBuff = (char*)getStack(1024);

    pb_ostream_t anyMsg_stream = pb_ostream_from_buffer((pb_byte_t *)tempBuff, 1024);
    if (!pb_encode(&anyMsg_stream, google_protobuf_Any_fields, anyMsg_ptr))
        return NULL;

    cosmos_tx_v1beta1_TxBody* body = (cosmos_tx_v1beta1_TxBody*)getStack( sizeof(cosmos_tx_v1beta1_TxBody));
    *body = (cosmos_tx_v1beta1_TxBody) cosmos_tx_v1beta1_TxBody_init_zero;
    call_back_contexts* value_context  = (call_back_contexts*)getStack(sizeof(call_back_contexts));
    value_context->len                 = anyMsg_stream.bytes_written;
    value_context->data                = tempBuff;
    body->messages.arg                 = value_context;
    body->messages.funcs.encode        = &encode_array; 
    body->timeout_height               = timeout;

    return (void*)body;
}


int bind_cosmos_sec256k1_pk_to_anyMsg(void* anyMsg, unsigned char* pubkey, int pubkey_len, char* url){
    int ret = 0;
    cosmos_crypto_secp256k1_PubKey* cosmos_pubkey = (cosmos_crypto_secp256k1_PubKey*)getStack( sizeof(cosmos_crypto_secp256k1_PubKey));
    *cosmos_pubkey = (cosmos_crypto_secp256k1_PubKey) cosmos_crypto_secp256k1_PubKey_init_zero;
    call_back_contexts* key_context = (call_back_contexts*)getStack(sizeof(call_back_contexts));
    key_context->len                = pubkey_len;
    key_context->data               = (char*)pubkey;
    cosmos_pubkey->key.arg          = key_context;
    cosmos_pubkey->key.funcs.encode = &encode_array;

    char* streamBuff = (char*)getStack(128);
    pb_ostream_t pkStream = pb_ostream_from_buffer((pb_byte_t *)streamBuff, 128);
    if (!pb_encode(&pkStream, cosmos_crypto_secp256k1_PubKey_fields, cosmos_pubkey))
        ret = -1;

    google_protobuf_Any* anyMsg_ptr   = (google_protobuf_Any*)anyMsg;
    call_back_contexts* value_context = (call_back_contexts*)getStack(sizeof(call_back_contexts));
    value_context->len                = pkStream.bytes_written;
    value_context->data               = streamBuff;
    anyMsg_ptr->value.arg             = value_context;
    anyMsg_ptr->type_url.arg          = url;
    anyMsg_ptr->value.funcs.encode    = &encode_array;
    anyMsg_ptr->type_url.funcs.encode = &encode_string;
    
    return ret;
}


void* fullfill_cosmos_tx_v1beta1_signerInfo(void* anyMsg, uint64_t sequence){
    cosmos_tx_v1beta1_SignerInfo* signer_info = (cosmos_tx_v1beta1_SignerInfo*)getStack( sizeof(cosmos_tx_v1beta1_SignerInfo));
    *signer_info = (cosmos_tx_v1beta1_SignerInfo) cosmos_tx_v1beta1_SignerInfo_init_zero;
    signer_info->has_mode_info  = true;
    signer_info->has_public_key = true;
    signer_info->mode_info.sum.single.mode = cosmos_tx_signing_v1beta1_SignMode_SIGN_MODE_DIRECT;
    signer_info->mode_info.which_sum       = cosmos_tx_v1beta1_ModeInfo_single_tag;
    signer_info->sequence                  = sequence;
    memcpy((char*)&signer_info->public_key, (char*)anyMsg, sizeof(google_protobuf_Any));

    return (void*)signer_info;
}


void* fullfill_cosmos_tx_v1beta1_fee(void** coins, int gas_limit){
    cosmos_base_v1beta1_Coin* coin  = (cosmos_base_v1beta1_Coin*)coins[0];
    char* tempBuff         = (char*)getStack(128);

    pb_ostream_t fee_stream = pb_ostream_from_buffer((pb_byte_t *)tempBuff, 128);
    if (!pb_encode(&fee_stream, cosmos_base_v1beta1_Coin_fields, coin))
        return NULL;

    cosmos_tx_v1beta1_Fee* fee = (cosmos_tx_v1beta1_Fee*)getStack( sizeof(cosmos_tx_v1beta1_Fee));
    *fee = (cosmos_tx_v1beta1_Fee) cosmos_tx_v1beta1_Fee_init_zero;
    call_back_contexts* value_context = (call_back_contexts*)getStack(sizeof(call_back_contexts));
    value_context->len                = fee_stream.bytes_written;
    value_context->data               = tempBuff;
    fee->amount.arg          = value_context;
    fee->amount.funcs.encode = &encode_array;
    fee->gas_limit           = gas_limit;

    return (void*) fee;
}


void* fullfill_cosmos_tx_v1beta1_authInfo(void* fee, void** signer_infos){
    cosmos_tx_v1beta1_SignerInfo* signer    = (cosmos_tx_v1beta1_SignerInfo*)signer_infos[0];
    char* tempBuff                 = (char*)getStack(256);

    pb_ostream_t Sstream = pb_ostream_from_buffer((pb_byte_t *)tempBuff, 256);
    if (!pb_encode(&Sstream, cosmos_tx_v1beta1_SignerInfo_fields, signer))
        return NULL;

    cosmos_tx_v1beta1_AuthInfo* auth = (cosmos_tx_v1beta1_AuthInfo*)getStack( sizeof(cosmos_tx_v1beta1_AuthInfo));
    *auth = (cosmos_tx_v1beta1_AuthInfo) cosmos_tx_v1beta1_AuthInfo_init_zero; 
    auth->has_fee = true;
    memcpy((char*)&auth->fee, (char*)fee, sizeof(cosmos_tx_v1beta1_Fee));

    call_back_contexts* value_context = (call_back_contexts*)getStack(sizeof(call_back_contexts));
    value_context->len                = Sstream.bytes_written;
    value_context->data               = tempBuff;
    auth->signer_infos.arg            = value_context;
    auth->signer_infos.funcs.encode   = &encode_array;

    return (void*) auth;
}


void* fullfill_cosmos_tx_v1beta1_tx(void* body, void* auth){
    cosmos_tx_v1beta1_Tx* tx = (cosmos_tx_v1beta1_Tx*)getStack( sizeof(cosmos_tx_v1beta1_Tx));
    *tx = (cosmos_tx_v1beta1_Tx) cosmos_tx_v1beta1_Tx_init_zero; 
    tx->has_body      = true;
    tx->has_auth_info = true;
    memcpy((char*)&tx->body, (char*)body, sizeof(cosmos_tx_v1beta1_TxBody));
    memcpy((char*)&tx->auth_info, (char*)auth, sizeof(cosmos_tx_v1beta1_AuthInfo));

    return (void*) tx;
}


void* fullfill_cosmos_tx_v1beta1_txRaw(void* tx){
    cosmos_tx_v1beta1_Tx* txPtr = (cosmos_tx_v1beta1_Tx*)tx;
    cosmos_tx_v1beta1_TxRaw* txRaw = (cosmos_tx_v1beta1_TxRaw*)getStack( sizeof(cosmos_tx_v1beta1_TxRaw));
    *txRaw = (cosmos_tx_v1beta1_TxRaw) cosmos_tx_v1beta1_TxRaw_init_zero;

    cosmos_tx_v1beta1_TxBody* Body = &txPtr->body;
    char* tempBuff = (char*)getStack(1024);
    pb_ostream_t Bstream    = pb_ostream_from_buffer((pb_byte_t *)tempBuff, 1024);
     if (!pb_encode(&Bstream, cosmos_tx_v1beta1_TxBody_fields, Body))
        return NULL;

    char* tempBuff2 = (char*)getStack(1024);
    pb_ostream_t Astream     = pb_ostream_from_buffer((pb_byte_t *)tempBuff2, 1024);
    if (!pb_encode(&Astream, cosmos_tx_v1beta1_AuthInfo_fields, &txPtr->auth_info))
        return NULL;

    call_back_contexts* body_context = (call_back_contexts*)getStack(sizeof(call_back_contexts));
    body_context->len                = Bstream.bytes_written;
    body_context->data               = tempBuff;
    call_back_contexts* auth_context = (call_back_contexts*)getStack(sizeof(call_back_contexts));
    auth_context->len                = Astream.bytes_written;
    auth_context->data               = tempBuff2;

    txRaw->body_bytes.arg               = body_context;
    txRaw->auth_info_bytes.arg          = auth_context;
    txRaw->body_bytes.funcs.encode      = &encode_array;
    txRaw->auth_info_bytes.funcs.encode = &encode_array;

    /****/
    // pb_ostream_t anyMsg_streamm = pb_ostream_from_buffer((pb_byte_t *)mBuff, sizeof(mBuff));
    // if (!pb_encode(&anyMsg_streamm, cosmos_tx_v1beta1_TxRaw_fields, txRaw))
    // {
    //     printMsg("Encoding failed\n");   
    // }

    // sprintf(responseArr, "cosmos_tx_v1beta1_TxRaw Size: %0d \n\n", anyMsg_streamm.bytes_written);
    // printMsg(responseArr);
    // for(int i=0; i<anyMsg_streamm.bytes_written; ++i){
    //     sprintf(responseArr, "%02x ", mBuff[i]);
    //     printMsg(responseArr);
    // }
    // printMsg("\n\n");
    /****/

    return (void*)txRaw;
}


void* fullfill_binMessage(void* txRaw, const char *chain_id, uint64_t account_id, int* data_len){
    cosmos_tx_v1beta1_TxRaw* txRawPtr = (cosmos_tx_v1beta1_TxRaw*)txRaw;
    cosmos_tx_v1beta1_SignDoc* signDoc = (cosmos_tx_v1beta1_SignDoc*)getStack( sizeof(cosmos_tx_v1beta1_SignDoc));
    *signDoc = (cosmos_tx_v1beta1_SignDoc) cosmos_tx_v1beta1_SignDoc_init_zero;
    signDoc->body_bytes.arg               = txRawPtr->body_bytes.arg;
    signDoc->body_bytes.funcs.encode      = txRawPtr->body_bytes.funcs.encode;
    signDoc->auth_info_bytes.arg          = txRawPtr->auth_info_bytes.arg;
    signDoc->auth_info_bytes.funcs.encode = txRawPtr->auth_info_bytes.funcs.encode;
    signDoc->account_number               = account_id;
    signDoc->chain_id.arg                 = (char*)chain_id;
    if(chain_id[0] != 0)
        signDoc->chain_id.funcs.encode    = &encode_string;

    char* tempBuff = (char*)getStack(1024);
    pb_ostream_t Sstream    = pb_ostream_from_buffer((pb_byte_t *)tempBuff, 1024);
    if (!pb_encode(&Sstream, cosmos_tx_v1beta1_SignDoc_fields, signDoc))
        return NULL;
    
    *data_len = Sstream.bytes_written;
    return (void*)tempBuff;
}


void* prepare_txRaw_data(uint8_t** tx_bytes, size_t* tx_size, void* txRaw, unsigned char* signature, int signLen){
    cosmos_tx_v1beta1_TxRaw* txRawPtr = (cosmos_tx_v1beta1_TxRaw*)txRaw;
    call_back_contexts sign_context   = {.data = (char*)signature, .len = signLen};
    txRawPtr->signatures.arg          = &sign_context;
    txRawPtr->signatures.funcs.encode = &encode_array;

    *tx_bytes = (uint8_t*)getStack(1024);
    pb_ostream_t Sstream    = pb_ostream_from_buffer((pb_byte_t *)*tx_bytes, 1024);
    if (!pb_encode(&Sstream, cosmos_tx_v1beta1_TxRaw_fields, txRawPtr))
        return NULL;

    sprintf(responseArr, "DataSize: %d\n", Sstream.bytes_written);
    printMsg(responseArr);
    unsigned char* x = *tx_bytes;
    for(uint32_t i=0; i<Sstream.bytes_written; ++i){
        sprintf(responseArr, "%02x ", x[i]);
        printMsg(responseArr);
    }

    *tx_size = Sstream.bytes_written;
    return *tx_bytes;
}


void* fullfill_planetmintgo_asset_msgnotarizeasset(const char* cid, char* public_address){
    planetmintgo_asset_MsgNotarizeAsset* msg = (planetmintgo_asset_MsgNotarizeAsset*)getStack( sizeof(planetmintgo_asset_MsgNotarizeAsset));
    *msg = (planetmintgo_asset_MsgNotarizeAsset) planetmintgo_asset_MsgNotarizeAsset_init_zero;
    msg->cid.arg              = (char*)cid;
    msg->creator.arg          = public_address;
    msg->cid.funcs.encode     = &encode_string;
    msg->creator.funcs.encode = &encode_string;

    return (void*) msg;
}


int bind_planetmintgo_asset_notarizeMsg_to_anyMsg(void* anyMsg, void* msg){
    google_protobuf_Any* anyMsg_ptr    = (google_protobuf_Any*)anyMsg;
 
    char* tempBuff = (char*)getStack(512);
    pb_ostream_t Pstream    = pb_ostream_from_buffer((pb_byte_t *)tempBuff, 512);
    if (!pb_encode(&Pstream, planetmintgo_asset_MsgNotarizeAsset_fields, msg))
        return -1;
    
    call_back_contexts* value_context  = (call_back_contexts*)getStack(sizeof(call_back_contexts));
    value_context->len                 = Pstream.bytes_written;
    value_context->data                = tempBuff;
    anyMsg_ptr->value.arg              = value_context;
    anyMsg_ptr->type_url.arg           = "/planetmintgo.asset.MsgNotarizeAsset";
    anyMsg_ptr->value.funcs.encode     = &encode_array;
    anyMsg_ptr->type_url.funcs.encode  = &encode_string;

    return 0;
}


int bind_planetmintgo_dao_msgReport_to_anyMsg(void* anyMsg, bool PoPSuccess, char* creator){
    int  ret = 0;
    planetmintgo_dao_Challenge challenge = planetmintgo_dao_Challenge_init_zero;
    challenge.initiator.arg  = popParticipation.initiator;
    challenge.challenger.arg = popParticipation.challenger;
    challenge.challengee.arg = popParticipation.challengee;
    challenge.height         = popParticipation.blockHeight;
    challenge.success        = PoPSuccess;
    challenge.finished       = true;
    challenge.initiator.funcs.encode  = &encode_string;
    challenge.challenger.funcs.encode = &encode_string;
    challenge.challengee.funcs.encode = &encode_string;

    planetmintgo_dao_MsgReportPopResult popResultMsg = planetmintgo_dao_MsgReportPopResult_init_zero;
    popResultMsg.creator.arg            = creator;
    popResultMsg.creator.funcs.encode   = &encode_string;
    popResultMsg.has_challenge          = true;
    memcpy(&popResultMsg.challenge, (char*)&challenge, sizeof(planetmintgo_dao_Challenge));

    char* streamBuff = (char*)getStack(1024);
    pb_ostream_t pkStream    = pb_ostream_from_buffer((pb_byte_t *)streamBuff, 1024);
    if (!pb_encode(&pkStream, planetmintgo_dao_MsgReportPopResult_fields, &popResultMsg))
        ret = -1;

    google_protobuf_Any* anyMsg_ptr   = (google_protobuf_Any*)anyMsg;
    call_back_contexts* value_context = (char*)getStack(sizeof(call_back_contexts));
    value_context->len                = pkStream.bytes_written;
    value_context->data               = streamBuff;
    anyMsg_ptr->value.arg             = value_context;
    anyMsg_ptr->type_url.arg          = daoMsgReportPopR_url;
    anyMsg_ptr->value.funcs.encode    = &encode_array;
    anyMsg_ptr->type_url.funcs.encode = &encode_string;

    return ret;
}

