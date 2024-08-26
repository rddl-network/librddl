
#include <stdint.h> 
#include <stdbool.h>
#include <string.h>
#include "curves.h"  
#include "secp256k1.h"

#include "rddl.h"
#include "keys.h"
#include "planetmintgo.h"

uint8_t priv_key_planetmint[32+1] = {0};
uint8_t priv_key_liquid[32+1] = {0};
uint8_t pub_key_planetmint[33+1] = {0};
uint8_t pub_key_liquid[33+1] = {0};
uint8_t sdk_machineid_public_key[33+1]={0}; 

char plmnt_address[64] = {0};
char ext_pub_key_planetmint[EXT_PUB_KEY_SIZE+1] = {0};
char ext_pub_key_liquid[EXT_PUB_KEY_SIZE+1] = {0};
char machineid_public_key_hex[33*2+1] = {0};





const char* getRDDLAddress()          { return (const char*) plmnt_address; }
const char* getExtPubKeyLiquid()      { return (const char*)ext_pub_key_liquid; }
const char* getExtPubKeyPlanetmint()  { return (const char*)ext_pub_key_planetmint; }
const uint8_t* getPrivKeyLiquid()     { return (const uint8_t*)priv_key_liquid; }
const uint8_t* getPrivKeyPlanetmint() { return (const uint8_t*)priv_key_planetmint; }
const char* getMachinePublicKey()     { return (const char*) machineid_public_key_hex; }





bool getPlntmntKeys(){
  
  /* Seedden Priv key ve diger seyleri elde et */
  HDNode node_planetmint;
  hdnode_from_seed( secret_seed, SEED_SIZE, SECP256K1_NAME, &node_planetmint);
  hdnode_private_ckd_prime(&node_planetmint, 44);
  hdnode_private_ckd_prime(&node_planetmint, 8680);
  hdnode_private_ckd_prime(&node_planetmint, 0);
  hdnode_private_ckd(&node_planetmint, 0);
  hdnode_private_ckd(&node_planetmint, 0);
  hdnode_fill_public_key(&node_planetmint);
  /* Global e kopyaliyor pub ve priv keyi */
  memcpy(priv_key_planetmint, node_planetmint.private_key, 32);
  memcpy(pub_key_planetmint, node_planetmint.public_key, PUB_KEY_SIZE);


  /* Seedden Priv key ve diger seyleri elde et */
  HDNode node_rddl;
  hdnode_from_seed( secret_seed, SEED_SIZE, SECP256K1_NAME, &node_rddl);
  hdnode_private_ckd_prime(&node_rddl, 44);
  hdnode_private_ckd_prime(&node_rddl, 1776);
  hdnode_private_ckd_prime(&node_rddl, 0);
  hdnode_private_ckd(&node_rddl, 0);
  hdnode_private_ckd(&node_rddl, 0);
  hdnode_fill_public_key(&node_rddl);
  /* Global e kopyaliyor pub ve priv keyi */
  memcpy(priv_key_liquid, node_rddl.private_key, 32);
  memcpy(pub_key_liquid, node_rddl.public_key, PUB_KEY_SIZE);

  uint8_t address_bytes[ADDRESS_TAIL] = {0};
  pubkey2address( pub_key_planetmint, PUB_KEY_SIZE, address_bytes );
  getAddressString( address_bytes, plmnt_address);
  uint32_t fingerprint = hdnode_fingerprint(&node_planetmint);
  hdnode_serialize_public( &node_planetmint, fingerprint, PLANETMINT_PMPB, ext_pub_key_planetmint, EXT_PUB_KEY_SIZE);
  hdnode_serialize_public( &node_rddl, fingerprint, VERSION_PUBLIC, ext_pub_key_liquid, EXT_PUB_KEY_SIZE);

  ecdsa_get_public_key33(&secp256k1, private_key_machine_id, sdk_machineid_public_key);
  toHexString( machineid_public_key_hex, sdk_machineid_public_key, 33*2);
  return true;
}