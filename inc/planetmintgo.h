#ifndef _PLANETMINT_GO_H_
#define _PLANETMINT_GO_H_

#ifdef __cplusplus
extern "C" {
#endif

#define PUBKEY_SIZE 35
#define ADDRESS_TAIL 20
#include "planetmintgo/machine/machine.pb-c.h"
#include "planetmintgo/machine/tx.pb-c.h"
#include "planetmintgo/dao/tx.pb-c.h"
#include "cosmos/tx/v1beta1/tx.pb-c.h"
#include "google/protobuf/any.pb-c.h"
#include "cosmos/base/v1beta1/coin.pb-c.h"


#define PLANETMINT_PMPB 0x03E14247
#define PLANETMINT_PMPR 0x03E142B0

bool get_account_info( const char* json_obj, int* account_id, int* sequence );

void pubkey2address( const uint8_t* pubkey, size_t key_length, uint8_t* address);
int getAddressString( const uint8_t* address, char* stringbuffer);

int generateAnyCIDAttestMsg( Google__Protobuf__Any* anyMsg, const char* cid, 
        uint8_t* priv_key, uint8_t* pub_key,
        char *public_address, const char* ext_pub_key);

int generateAnyAttestMachineMsg(Google__Protobuf__Any* anyMsg, 
        Planetmintgo__Machine__MsgAttestMachine* machineMsg);

int generateAnyPoPResultMsg(Google__Protobuf__Any* anyMsg, 
        Planetmintgo__Dao__MsgReportPopResult* popResultMsg);

int generateAnyRedeemClaimMsg(Google__Protobuf__Any* anyMsg, 
        Planetmintgo__Dao__MsgCreateRedeemClaim* redeemClaimMsg);

int prepareTx( Google__Protobuf__Any* anyMsg, 
        Cosmos__Base__V1beta1__Coin* coin,
        uint8_t *priv_key, uint8_t *pub_key,
        uint64_t sequence, const char *chain_id, uint64_t account_id,
        uint8_t** tx_bytes, size_t* tx_size);

bool removeIPAddr( char* gps_data );

#define MY_STACK_LIMIT 7168

uint8_t* getStack( size_t size );
void clearStack();
extern volatile uint8_t myStack[MY_STACK_LIMIT];


#ifdef __cplusplus
}
#endif

#endif
