#include "unity.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "rddl.h"
#include "planetmintgo.h"


#include "bip32.h"
#include "curves.h"



const char* planetmint_service="http://0.0.0.0:34331";

#define PUBKEY_SIZE 35
#define ADDRESS_TAIL 20

const char* mnemonic = "helmet hedgehog lab actor weekend elbow pelican valid obtain hungry rocket decade tower gallery fit practice cart cherry giggle hair snack glance bulb farm";

uint8_t reference_private_key[34] = {10,32,128,112,249,202,124,175,82,178,11,149,241,218,147,44,100,141,148,52,223,57,67,112,250,53,133,185,112,220,55,149,174,168};
uint8_t reference_pubkey[35] = {10,33,2,50,141,232,120,150,185,203, 181,16,28,51,95,64,2,158,75,232, 152,152,139,71,10,187,246,131,241,160, 179,24,215,52,112};
uint8_t reference_sha[32] ={31,236,15,94,16,55,101,147,213,70,37,62,34,135,62,56,157,191,178,240,110,222,141,80,27,60,48,71,151,21,141,234};

uint8_t reference_addressbytes[20] = {46,62,250,9,104,89,242,77,48,250, 188,165,41,197,119,78,195,205,1,70};

const char* expected_address = "cosmos19cl05ztgt8ey6v86hjjjn3thfmpu6q2xqmsuyx";
uint8_t sha_hash[32] = {31,236,15,94,16,55,101,147,213,70,37,62,34,135,62,56,157,191,178,240,110,222,141,80,27,60,48,71,151,21,141,234};


void test_attest_machine()
{
  attestMachine( reference_private_key +2, reference_pubkey+2, expected_address );
  //body_bytes =
  //[]uint8 len: 392, cap: 392, [10,133,3,10,38,47,112,108,97,110,101,116,109,105,110,116,103,111,46,109,97,99,104,105,110,101,46,77,115,103,65,116,116,101,115,116,77,97,99,104,105,110,101,18,218,2,10,45,99,111,115,109,111,115,49,57,99,108,48,53,122,116,103,116,...+328 more]
  //"\n\x85\x03\n&/planetmintgo.machine.MsgAttestMachine\x12\xda\x02\n-cosmos19cl05ztgt8ey6v86hjjjn3thfmpu6q2xqmsuyx\x12\xa8\x02\n\amachine\x12\x0emachine_ticker\x18\x01 \xe8\a(\b2,AjKN6HiWucu1EBwzX0ACnkvomJiLRwq79oPxoLMY1zRw:,AjKN6HiWucu1EBwzX0ACnkvomJiLRwq79oPxoLMY1zRwB,AjKN6HiWucu1EBwzX0ACnkvomJiLRwq79oPxoLMY1zRwJ|\n3{\"Latitude\":\"-48.876667\",\"Longitude\":\"-123.393333\"}\x12,{\"Manufacturer\": \"RDDL\",\"Serial\":\"AdnT2uyt\"}\x1a\x12{\"Version\": \"0.1\"}\"\x03CID"
  //auth_info_bytes =
  //[]uint8 len: 100, cap: 100, [10,80,10,70,10,31,47,99,111,115,109,111,115,46,99,114,121,112,116,111,46,115,101,99,112,50,53,54,107,49,46,80,117,98,75,101,121,18,35,10,33,2,50,141,232,120,150,185,203,181,16,28,51,95,64,2,158,75,232,152,152,139,71,10,...+36 more]


  /*
  	signDoc := types.SignDoc{
		BodyBytes:     bodyBytes,
		AuthInfoBytes: authInfoBytes,
		ChainId:       chainID,
		AccountNumber: accnum,
	}
  */
}



// current derivation path FullFundraiserPath = "m/44'/118'/0'/0/0"
extern uint8_t secret_seed[SEED_SIZE];
void private2public_key()
{
  uint8_t priv_key[32]= {0};
  uint8_t pub_key[33] = {0};
  if( !mnemonic_check( mnemonic ) )
    return "";

  mnemonic_to_seed(mnemonic, "", secret_seed, 0);

  HDNode node;
  hdnode_from_seed( secret_seed, SEED_SIZE, SECP256K1_NAME, &node);
  hdnode_private_ckd_prime(&node, 44);
  hdnode_private_ckd_prime(&node, 118);
  hdnode_private_ckd_prime(&node, 0);
  hdnode_private_ckd(&node, 0);
  hdnode_private_ckd(&node, 0);
  hdnode_fill_public_key(&node);
  memcpy(priv_key, node.private_key, 32);
  memcpy(pub_key, node.public_key, 33);

  TEST_ASSERT_EQUAL_MEMORY( reference_private_key+2, priv_key, 32 );   
  TEST_ASSERT_EQUAL_MEMORY( reference_pubkey+2, pub_key, 33 );
}


void test_pubkey2address_convertion()
{
    int offset = 2;
    uint8_t address_bytes[ADDRESS_TAIL] = {0};
    pubkey2address( reference_pubkey+offset, 35-offset, address_bytes );
    int result = memcmp( reference_addressbytes, address_bytes, ADDRESS_TAIL);
    TEST_ASSERT_EQUAL_MEMORY( reference_addressbytes, address_bytes, 20 );   
}


void test_from_address_to_address_string()
{
    char address_string[64]={0};
    int res = getAddressString( reference_addressbytes, address_string);
    TEST_ASSERT_EQUAL_MEMORY( expected_address, address_string, strlen(expected_address) );    
}


int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_attest_machine);
  RUN_TEST(private2public_key);
  RUN_TEST(test_pubkey2address_convertion);
  RUN_TEST(test_from_address_to_address_string);

  return UNITY_END();
}
