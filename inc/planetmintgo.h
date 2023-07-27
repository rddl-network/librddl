#ifndef _PLANETMINT_GO_H_
#define _PLANETMINT_GO_H_

#define PUBKEY_SIZE 35
#define ADDRESS_TAIL 20

void pubkey2address( const uint8_t* pubkey, size_t key_length, uint8_t* address);
int getAddressString( const uint8_t* address, char* stringbuffer);
void attestMachine(uint8_t *priv_key, uint8_t *pub_key, char *public_address, uint8_t* signature, uint8_t** tx_bytes, size_t* tx_size);
#endif