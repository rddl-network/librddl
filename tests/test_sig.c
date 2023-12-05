#include "tests.h"
#include "hmac_drbg.h"
#include "secp256k1.h"
#include "rddl.h"


char privkey[] = {'\x80', '\x8c', '\xeb', '\x78', '\x8f', '\x3e', '\x2b', '\xe7', '\x67', '\x7a', '\xd6', '\x5f', '\x96', '\x93', '\xb2', '\x3a', '\x64', '\xd7', '\x00', '\xb3', '\x4b', '\xcc', '\xad', '\xdd', '\x03', '\xf2', '\x2d', '\x3e', '\x32', '\x35', '\xf1', '\x1d'};
char pubkey[]  = {'\x51', '\x7f', '\xb7', '\x3e', '\x19', '\x00', '\x85', '\x5e', '\xbd', '\xbc', '\x0d', '\xd8', '\xc9', '\x14', '\xa8', '\x60', '\xc0', '\xeb', '\x57', '\x2e', '\xf8', '\xd6', '\x66', '\x11', '\x38', '\xee', '\xe7', '\xaa', '\x70', '\xd8', '\xa1', '\x46'};
char base58_pubkey[] = "6V8ycJdv7kPiXpAhCgk6YPrmc35yMnCCvxP4YnGzvhp9";

void test_b58tobin() {
  size_t binsz = 32 ;
  uint8_t pubkey_test[32] = {0};
  b58tobin( pubkey_test, &binsz, base58_pubkey);
  memcmp( pubkey, pubkey_test, 32 );
  //TEST_ASSERT_EQUAL( 0, memcmp( pubkey , pubkey_test , 32 ) );
  TEST_ASSERT_EQUAL_INT8_ARRAY( pubkey, pubkey_test, 32 );
}



void test_machineID_challenge_reponse()
{
  uint8_t seed[64];
  memcpy( seed, private_key_machine_id, 32);
  random_buffer(seed, 64);
// 
  // Initialize the HMAC-DRBG
  HMAC_DRBG_CTX ctx;
  hmac_drbg_init(&ctx, seed, 64, NULL, 0);
// 
  // Generate a private key (32 bytes for secp256k1)
  uint8_t private_key[32];
  hmac_drbg_generate(&ctx, private_key, 32);
    // Derive the public key from the private key
  uint8_t public_key[33];
  ecdsa_get_public_key33(&secp256k1, private_key, public_key);

  uint8_t signature[65]={0};
  uint8_t hash[33]={0};
  bool ret = getMachineIDSignature(  private_key,  public_key, signature, hash);

  TEST_ASSERT_TRUE( ret );
}

void test_machine_challenge_response_equal_to_planetmint()
{
  char* prvkey_hex = "874592600e01a36614b17734cf58764935c40a3c50b685f8951da545fdf11ca9";
  char* pubkey_hex = "03e695bb6787798460c0160f52ffbab09f409d9163ed49a1eecaf15d583d5be762";

  uint8_t sigbytes_expected[64] = {3,173,28,73,239,11,8,235,63,112,180,33,111,58,78,117,8,246,183,161,12,152,190,230,207,118,5,8,56,22,229,253,45,64,151,252,127,134,52,214,9,89,1,18,7,141,9,100,129,86,98,122,221,181,65,28,193,226,54,72,180,225,196,185};
  uint8_t privbytes[32] = {0};
  uint8_t pubbytes[33] = {0};
  
  const uint8_t* privatekey = fromHexString(prvkey_hex);
  memcpy(privbytes, privatekey, 32);
  const uint8_t* publickey = fromHexString(pubkey_hex);
  memcpy(pubbytes, publickey, 33);
  
  uint8_t signature[65]={0};
  uint8_t hash[33]={0};
  bool ret = getMachineIDSignature(  privbytes,  pubbytes, signature, hash);
  TEST_ASSERT_TRUE( ret );
  TEST_ASSERT_EQUAL_MEMORY( sigbytes_expected , signature , 64);
}

void test_machine_challenge_response_equal_to_planetmint_load_local_machine_id()
{
  uint8_t public_key[33];
  ecdsa_get_public_key33(&secp256k1, private_key_machine_id, public_key);
  
  uint8_t signature[65]={0};
  uint8_t hash[33]={0};
  bool ret = getMachineIDSignature(  private_key_machine_id,  public_key, signature, hash);
  TEST_ASSERT_TRUE( ret );
}

void test_getMachineIDSignaturePublicKey()
{
  uint8_t signature[64]={0};
  uint8_t public_key[33] = {0};
  bool ret = getMachineIDSignaturePublicKey( private_key_machine_id, public_key, signature );
  TEST_ASSERT_TRUE( ret );
}


int main(void) {

  UNITY_BEGIN();
  RUN_TEST(test_machineID_challenge_reponse);
  RUN_TEST(test_machine_challenge_response_equal_to_planetmint);
  RUN_TEST(test_machine_challenge_response_equal_to_planetmint_load_local_machine_id);
  RUN_TEST(test_getMachineIDSignaturePublicKey);

  RUN_TEST(test_b58tobin);
  return UNITY_END();
}
