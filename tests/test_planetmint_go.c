#include "unity.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "rddl.h"
#include "planetmintgo.h"

#include "bip32.h"
#include "curves.h"
#include "base64.h"



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

uint8_t expected_sig[64]={35,187,131,58,5,149,242,90,22,45,245,9,148,237,110,120,133,138,248,12,97,190,2,174,109,183,114,221,43,115,189,226,66,31,36,129,225,104,149,101,100,4,158,205,171,76,54,47,152,121,186,252,209,215,98,183,73,71,222,159,35,48,233,217};

const char* expected_tx_b64_bytes = "CvcDCvQDCiYvcGxhbmV0bWludGdvLm1hY2hpbmUuTXNnQXR0ZXN0TWFjaGluZRLJAwotY29zbW9zMTljbDA1enRndDhleTZ2ODZoampqbjN0aGZtcHU2cTJ4cW1zdXl4EpcDCgdtYWNoaW5lEg5tYWNoaW5lX3RpY2tlchgBIOgHKAgyQjAyMzI4ZGU4Nzg5NmI5Y2JiNTEwMWMzMzVmNDAwMjllNGJlODk4OTg4YjQ3MGFiYmY2ODNmMWEwYjMxOGQ3MzQ3MDpveHB1YjY2MU15TXdBcVJiY0VpZ1JTR05qenFzVWJrb3hSSFREWVhEUTZvNWtxNkVRVFNZdVh4d0Q1ek5iRVhGakNHM2hEbVlacUNFNEhGdGNQQWkzVjNNVzl0VFl3cXpMRFV0OUJtSHY3ZlBjV2FCQkIwMjMyOGRlODc4OTZiOWNiYjUxMDFjMzM1ZjQwMDI5ZTRiZTg5ODk4OGI0NzBhYmJmNjgzZjFhMGIzMThkNzM0NzBKfAozeyJMYXRpdHVkZSI6Ii00OC44NzY2NjciLCJMb25naXR1ZGUiOiItMTIzLjM5MzMzMyJ9Eix7Ik1hbnVmYWN0dXJlciI6ICJSRERMIiwiU2VyaWFsIjoiQWRuVDJ1eXQifRoSeyJWZXJzaW9uIjogIjAuMSJ9IgNDSUQSZApQCkYKHy9jb3Ntb3MuY3J5cHRvLnNlY3AyNTZrMS5QdWJLZXkSIwohAjKN6HiWucu1EBwzX0ACnkvomJiLRwq79oPxoLMY1zRwEgQKAggBGAESEAoKCgVzdGFrZRIBMhDAmgwaQCO7gzoFlfJaFi31CZTtbniFivgMYb4Crm23ct0rc73iQh8kgeFolWVkBJ7Nq0w2L5h5uvzR12K3SUfenyMw6dk=";

void test_attest_machine()
{
  
  uint8_t* txbytes = NULL;
  size_t tx_size = 0;
  uint8_t signature[64] = {0};
  attestMachine( reference_private_key +2, reference_pubkey+2, expected_address, signature, &txbytes, &tx_size);
  TEST_ASSERT_EQUAL_MEMORY( expected_sig, signature, 64 );
  
  char tx_bytes_b64[3000] = {0};
  char * p = bintob64( tx_bytes_b64, txbytes, tx_size);
  size_t length = p - tx_bytes_b64;
  printf( "buffer %s\n" , tx_bytes_b64);
  TEST_ASSERT_EQUAL_MEMORY( expected_tx_b64_bytes, tx_bytes_b64, length );
  free( txbytes );
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
