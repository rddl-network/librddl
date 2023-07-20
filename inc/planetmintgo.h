#ifndef _PLANETMINT_GO_H_
#define _PLANETMINT_GO_H_

#define PUBKEY_SIZE 35
#define ADDRESS_TAIL 20

void pubkey2address( const uint8_t* pubkey, size_t key_length, uint8_t* address);
int getAddressString( const uint8_t* address, char* stringbuffer);

#endif