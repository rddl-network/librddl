#ifndef _PLANETMINT_KEYS_H_
#define _PLANETMINT_KEYS_H_

#define PUB_KEY_SIZE 33
#define EXT_PUB_KEY_SIZE 112 

const char* getRDDLAddress();
const char* getExtPubKeyLiquid();
const char* getExtPubKeyPlanetmint();
const uint8_t* getPrivKeyLiquid();
const uint8_t* getPrivKeyPlanetmint();
const char* getMachinePublicKey();

bool getPlntmntKeys();

#endif