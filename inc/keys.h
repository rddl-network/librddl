#ifndef _PLANETMINT_KEYS_H_
#define _PLANETMINT_KEYS_H_

#define PUB_KEY_SIZE 33
#define EXT_PUB_KEY_SIZE 112 

const char* getRDDLAddress();
const char* getExtPubKeyLiquid();
const char* getExtPubKeyPlanetmint();
const char* getMachinePublicKeyHex();

const uint8_t* getPrivKeyLiquid();
const uint8_t* getPrivKeyPlanetmint();
const uint8_t* getPubKeyLiquid();
const uint8_t* getPubKeyPlanetmint();
const uint8_t* getMachinePublicKey();


bool getPlntmntKeys();

#endif