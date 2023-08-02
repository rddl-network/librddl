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
  free( txbytes );
  size_t length = p - tx_bytes_b64;

  TEST_ASSERT_EQUAL_MEMORY( expected_tx_b64_bytes, tx_bytes_b64, length );
}

void test_attest_machine_generic()
{
  char * expected_tx_b64_bytes_generic = "CogECoUECiYvcGxhbmV0bWludGdvLm1hY2hpbmUuTXNnQXR0ZXN0TWFjaGluZRLaAwotY29zbW9zMTljbDA1enRndDhleTZ2ODZoampqbjN0aGZtcHU2cTJ4cW1zdXl4EqgDCgdtYWNoaW5lEg5tYWNoaW5lX3RpY2tlchoPbGFiLnIzYy5uZXR3b3JrIAEo6AcwCDpCMDIzMjhkZTg3ODk2YjljYmI1MTAxYzMzNWY0MDAyOWU0YmU4OTg5ODhiNDcwYWJiZjY4M2YxYTBiMzE4ZDczNDcwQm94cHViNjYxTXlNd0FxUmJjRWlnUlNHTmp6cXNVYmtveFJIVERZWERRNm81a3E2RVFUU1l1WHh3RDV6TmJFWEZqQ0czaERtWVpxQ0U0SEZ0Y1BBaTNWM01XOXRUWXdxekxEVXQ5Qm1IdjdmUGNXYUJKQjAyMzI4ZGU4Nzg5NmI5Y2JiNTEwMWMzMzVmNDAwMjllNGJlODk4OTg4YjQ3MGFiYmY2ODNmMWEwYjMxOGQ3MzQ3MFJ8CjN7IkxhdGl0dWRlIjoiLTQ4Ljg3NjY2NyIsIkxvbmdpdHVkZSI6Ii0xMjMuMzkzMzMzIn0SLHsiTWFudWZhY3R1cmVyIjogIlJEREwiLCJTZXJpYWwiOiJBZG5UMnV5dCJ9GhJ7IlZlcnNpb24iOiAiMC4xIn0iA0NJRBJiCk4KRgofL2Nvc21vcy5jcnlwdG8uc2VjcDI1NmsxLlB1YktleRIjCiECMo3oeJa5y7UQHDNfQAKeS+iYmItHCrv2g/GgsxjXNHASBAoCCAESEAoKCgV0b2tlbhIBMhDAmgwaQMKTmzKJM1S+uh4VzblDKlSTp2Dx7log+/mq7RsFt0tHbSedwppW9KJjedhWDbx/3rFXuuYDqKuD6L/vnEEYkvM=";
  Google__Protobuf__Any anyMsg = GOOGLE__PROTOBUF__ANY__INIT;
  generateAnyAttestMachineMsg(&anyMsg, expected_address);

  Cosmos__Base__V1beta1__Coin coin = COSMOS__BASE__V1BETA1__COIN__INIT;
  coin.denom = "token";
  coin.amount = "2";
  
  uint8_t* txbytes = NULL;
  size_t tx_size = 0;
  uint64_t sequence = 0;
  prepareTx( &anyMsg, &coin, reference_private_key +2, reference_pubkey+2, 
      sequence, "planetmintgo", 8, &txbytes, &tx_size);
  free(anyMsg.value.data);
  char tx_bytes_b64[1000] = {0};
  char * p = bintob64( tx_bytes_b64, txbytes, tx_size);
  size_t length = p - tx_bytes_b64;

  free( txbytes );
  TEST_ASSERT_EQUAL_MEMORY( expected_tx_b64_bytes_generic, tx_bytes_b64, length );
}

void test_attest_asset_generic()
{
  char * expected_tx_b64_bytes_generic = "CsEBCr4BCiQvcGxhbmV0bWludGdvLmFzc2V0Lk1zZ05vdGFyaXplQXNzZXQSlQEKLWNvc21vczE5Y2wwNXp0Z3Q4ZXk2djg2aGpqam4zdGhmbXB1NnEyeHFtc3V5eBIDY2lkGj5DNEE2RTQzMTVBRDc1QTMzRjJDRTlCMzQ1QTEzQzU3RDc4RDJFREI0NEVCMzk4NjRBMDA4OTFDM0VGNjBFMSIfMDIzMjhERTg3ODk2QjlDQkI1MTAxQzMzNUY0MDAyORJkClAKRgofL2Nvc21vcy5jcnlwdG8uc2VjcDI1NmsxLlB1YktleRIjCiECMo3oeJa5y7UQHDNfQAKeS+iYmItHCrv2g/GgsxjXNHASBAoCCAEYARIQCgoKBXRva2VuEgEyEMCaDBpAbGUfFVnXobP99n4miN9wE7KiqbqN84cUSIJ8z9nCviUrG2QyeOEg/Tbzb+HWk7d/QOK7Y1gORKHi+5aCAsmwfg==";

  Google__Protobuf__Any anyMsg = GOOGLE__PROTOBUF__ANY__INIT;

  gnerateAnyCIDAttestMsgGeneric(& anyMsg, "cid", reference_private_key +2, reference_pubkey+2, expected_address );

  Cosmos__Base__V1beta1__Coin coin = COSMOS__BASE__V1BETA1__COIN__INIT;
  coin.denom = "token";
  coin.amount = "2";
  
  uint8_t* txbytes = NULL;
  size_t tx_size = 0;
  uint64_t sequence = 1;
  char* chain_id = "planetmintgo";
  uint64_t account_id = 8;
  prepareTx( &anyMsg, &coin, reference_private_key +2, reference_pubkey+2, 
      sequence, chain_id, account_id, &txbytes, &tx_size);
  free(anyMsg.value.data);
  char tx_bytes_b64[1000] = {0};
  char * p = bintob64( tx_bytes_b64, txbytes, tx_size);
  size_t length = p - tx_bytes_b64;

  free( txbytes );
  TEST_ASSERT_EQUAL_MEMORY( expected_tx_b64_bytes_generic, tx_bytes_b64, length );

}

extern uint8_t secret_seed[SEED_SIZE];
void private2public_key()
{

uint8_t reference_private_key_8680[34] = {10,32,203,100,215,232,29,78,103,123,94,137,110,235,33,88,220,0,201,95,59,32,98,73,204,29,144,234,24,67,129,108,170,160};
uint8_t reference_pubkey_8680[35] = {10,33,2,28,210,165,156,111,148,2,206,9,239,251,168,155,61,235,107,181,134,55,51,230,37,242,44,6,32,73,24,6,29,180,240};

  uint8_t priv_key[32]= {0};
  uint8_t pub_key[33] = {0};
  if( !mnemonic_check( mnemonic ) )
    return "";

  mnemonic_to_seed(mnemonic, "", secret_seed, 0);

  HDNode node;
  hdnode_from_seed( secret_seed, SEED_SIZE, SECP256K1_NAME, &node);
  hdnode_private_ckd_prime(&node, 44);
  hdnode_private_ckd_prime(&node, 8680);
  hdnode_private_ckd_prime(&node, 0);
  hdnode_private_ckd(&node, 0);
  hdnode_private_ckd(&node, 0);
  hdnode_fill_public_key(&node);
  memcpy(priv_key, node.private_key, 32);
  memcpy(pub_key, node.public_key, 33);

  TEST_ASSERT_EQUAL_MEMORY( reference_private_key_8680+2, priv_key, 32 );   
  TEST_ASSERT_EQUAL_MEMORY( reference_pubkey_8680+2, pub_key, 33 );
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
  RUN_TEST(test_attest_asset_generic);
  //RUN_TEST(test_attest_machine);
  RUN_TEST(test_attest_machine_generic);
  RUN_TEST(private2public_key);
  RUN_TEST(test_pubkey2address_convertion);
  RUN_TEST(test_from_address_to_address_string);

  return UNITY_END();
}
