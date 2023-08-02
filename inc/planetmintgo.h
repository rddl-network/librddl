#ifndef _PLANETMINT_GO_H_
#define _PLANETMINT_GO_H_

#define PUBKEY_SIZE 35
#define ADDRESS_TAIL 20
#include "planetmintgo/machine/machine.pb-c.h"
#include "cosmos/tx/v1beta1/tx.pb-c.h"


void pubkey2address( const uint8_t* pubkey, size_t key_length, uint8_t* address);
int getAddressString( const uint8_t* address, char* stringbuffer);

void gnerateAnyCIDAttestMsg( Google__Protobuf__Any* anyMsg, char *public_address );
void gnerateAnyCIDAttestMsgGeneric( Google__Protobuf__Any* anyMsg, const char* cid, 
        uint8_t* priv_key, uint8_t* pub_key,
        char *public_address );
void generateAnyAttestMachineMsg(Google__Protobuf__Any* anyMsg, char *public_address);
void prepareTx( Google__Protobuf__Any* anyMsg, 
        Cosmos__Base__V1beta1__Coin* coin,
        uint8_t *priv_key, uint8_t *pub_key,
        uint64_t sequence, const char *chain_id, uint64_t account_id,
        uint8_t** tx_bytes, size_t* tx_size);

void attestMachine(uint8_t *priv_key, uint8_t *pub_key, 
        char *public_address, uint8_t* signature,
        uint8_t** tx_bytes, size_t* tx_size);

#endif
