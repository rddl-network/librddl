#include "tests.h"
#include "rddl.h"

char pubkey[]  = {'\x51', '\x7f', '\xb7', '\x3e', '\x19', '\x00', '\x85', '\x5e', '\xbd', '\xbc', '\x0d', '\xd8', '\xc9', '\x14', '\xa8', '\x60', '\xc0', '\xeb', '\x57', '\x2e', '\xf8', '\xd6', '\x66', '\x11', '\x38', '\xee', '\xe7', '\xaa', '\x70', '\xd8', '\xa1', '\x46'};
char base58_pubkey[] = "6V8ycJdv7kPiXpAhCgk6YPrmc35yMnCCvxP4YnGzvhp9";


void test_key_derivation(){
  char * mnemonic = "hill romance angle pill differ primary task try pattern marriage someone strike fluid tomato life arch crowd pen gaze toast armed manual poverty guitar";

  uint8_t seed[64] = {0};
  uint8_t priv_key[33] = {0};
  uint8_t pub_key[34] = {0};
  
  
  mnemonic_to_seed(mnemonic, "TREZOR", seed, 0);
  TEST_ASSERT_TRUE( getKeyFromSeed(seed, priv_key, pub_key, ED25519_NAME) );
  printf("Private key: %s\n",priv_key);
  printf("Public key: %s\n",pub_key);

  char obj[200] = {0};
  size_t len = 200;
  bool result = b58enc( obj, &len, pub_key, 33);
  printf("Public key: %s\n",obj);

  TEST_ASSERT_EQUAL_MEMORY( "MxEUHGGRdM4Q94xSM8HDwUayuE4hQz3NboY29cDkk5mV", obj, 45);

}

void test_b58_encode_decode(){
  char obj[200] = {0};
  size_t len = 200;
  bool result = b58enc( obj, &len, pubkey, 32);
  printf("PUBKEY: %lu - %s\n", len, obj);
  printf("PUBKEY: %s\n", base58_pubkey);
  TEST_ASSERT_EQUAL_MEMORY( base58_pubkey, obj, 45);
}

#define FROMHEX_MAXLEN 512
const uint8_t *fromhexstring(const char *str) {
  static uint8_t buf[FROMHEX_MAXLEN];
  size_t len = strlen(str) / 2;
  if (len > FROMHEX_MAXLEN) len = FROMHEX_MAXLEN;
  for (size_t i = 0; i < len; i++) {
    uint8_t c = 0;
    if (str[i * 2] >= '0' && str[i * 2] <= '9') c += (str[i * 2] - '0') << 4;
    if ((str[i * 2] & ~0x20) >= 'A' && (str[i * 2] & ~0x20) <= 'F')
      c += (10 + (str[i * 2] & ~0x20) - 'A') << 4;
    if (str[i * 2 + 1] >= '0' && str[i * 2 + 1] <= '9')
      c += (str[i * 2 + 1] - '0');
    if ((str[i * 2 + 1] & ~0x20) >= 'A' && (str[i * 2 + 1] & ~0x20) <= 'F')
      c += (10 + (str[i * 2 + 1] & ~0x20) - 'A');
    buf[i] = c;
  }
  return buf;
}


void tohexstring(char *hexbuf, uint8_t *str, int strlen){
   // char hexbuf[strlen];
    for (int i = 0 ; i < strlen/2 ; i++) {
        sprintf(&hexbuf[2*i], "%02X", str[i]);
    }
  //hexbuf[strlen-2] = '\0';
}

void test_challenge_signing(){
  const char * challenge = "ce25c22581bb06841fabfa44bca29f55da7a466060166fdafed33be7b6affaf528c59f23fe10502ce0bf18fd933c15ce73de1144c1803919a0637541a260b584ee1eef85ad897cb9d5501f692e712fb11f0f00e9253a4dc8717b9252aa022ab545fa9b61ed521bc9c180c70e10927809f94f2f0eff00781142d14278c58256bb";
  size_t len = strlen( challenge );
  printf("challenge : %s\n", (char*)challenge );
  SHA256_CTX ctx;
  char hexbuf[68]={0};

  uint8_t hash[SHA256_DIGEST_LENGTH+1] = {0};
  sha256_Init(&ctx);
  sha256_Update(&ctx, (const uint8_t*) challenge, len);
  sha256_Final(&ctx, hash);
  tohexstring( hexbuf,(uint8_t*)hash, 66 );
  printf("hash in hex: %s\n", (char*)hexbuf );
//cde3378f62d6c86bf63cc5945664a0573b079933ce4344224e233db8da5c5b7f
//CDE3378F62D6C86BF63CC5945664A0573B079933CE4344224E233DB8DA5C5B7
}

void rddl_auth_test(){

  char * mnemonic = "column kick medal annual elegant history penalty zoo dish garbage left real practice afraid raw priority inner change cloth clean medal input garage gentle";

  uint8_t seed[64] = {0};
  uint8_t priv_key[33] = {0};
  uint8_t pub_key[34] = {0};
  
  
  mnemonic_to_seed(mnemonic, "TREZOR", seed, 0);
  TEST_ASSERT_TRUE( getKeyFromSeed(seed, priv_key, pub_key, ED25519_NAME) );
  
  printf("Public key: %s\n",pub_key);
  size_t len = 200;
  char obj[200] = {0};
  bool result = b58enc( obj, &len, pub_key+1, 32);
  printf("Public key: %s\n",obj);
  char pubkey_buf[200] = {0};
  tohexstring( pubkey_buf,(uint8_t*)pub_key+1, 64 );
  printf("Public key in hex: %s\n", (char*)pubkey_buf );

  len = 200;
  char obj2[200] = {0};
  result = b58enc( obj2, &len, priv_key, 32);
  printf("Private key: %s\n",priv_key);
  printf("Private key: %s\n",obj2);
  char privkey_buf[200] = {0};
  tohexstring( privkey_buf,(uint8_t*)priv_key, 64 );
  printf("Private key in hex: %s\n", (char*)privkey_buf );


  TEST_ASSERT_EQUAL_MEMORY( "3L5Pb63iWF4ifjNohoU6oFcanFRc1jLm5NXKj5ZXf7C6", obj, 45);

  const char * challenge = "5f965e52b20ec3ea2be4caf27e5c69b0aa62e94c69f005d157236c027c0f37b09178753aa85472ad62cd856bce33afc7b622e208710e4339608494f988a57801b244fdfe1ab5289d8e53434a355013a83066517b750a4b2b3bb82492f2aed94703c7d36258770b955adfa8549b35ba93452835adc451ff35d146335bb1e760f";
  len = strlen( challenge );
  printf("challenge : %s\n", (char*)challenge );
  SHA256_CTX ctx;
  char hexbuf[68]={0};

  uint8_t hash[SHA256_DIGEST_LENGTH+1] = {0};
  sha256_Init(&ctx);
  sha256_Update(&ctx, (const uint8_t*) challenge, len);
  sha256_Final(&ctx, hash);
  tohexstring( hexbuf,(uint8_t*)hash, 64 );
  printf("hash in hex: %s\n", (char*)hexbuf );
  TEST_ASSERT_EQUAL_MEMORY( "A00E49955384802BD942C7FDDB98564EA9FBD53C151D38B196BE27B947A9C3C7", hexbuf, 64);
  
  unsigned char signature[65] = {0};
  ed25519_sign( (const unsigned char*)hash, SHA256_DIGEST_LENGTH, (const unsigned char*)priv_key,(const unsigned char*)pub_key+1, signature);
  size_t sig_size = 200;
  char b58sig[200] = {0};
  b58enc( b58sig, &sig_size, signature, 64);
  TEST_ASSERT_EQUAL_MEMORY( "3LPsi2k3vP3AUBF1hNp8Ji7nthVpgM9kdjuEeVLDeYCfocLZ2bJxz64z3MKxo5aMRHSPRbejUmvo5734dnDAHVZ8", b58sig, sig_size);
  printf("sig in b58: %s\n", b58sig);
  int result_verify = ed25519_verify(signature,hash,SHA256_DIGEST_LENGTH,pub_key+1);
  TEST_ASSERT_EQUAL_INT( 0, result_verify);
  printf("verify sig: %i\n", result_verify);
}

void test_derivation(){
  uint8_t seed[64] = {0};
  char * mnemonic = "column kick medal annual elegant history penalty zoo dish garbage left real practice afraid raw priority inner change cloth clean medal input garage gentle";
  mnemonic_to_seed(mnemonic, "TREZOR", seed, 0);

  HDNode node;
  uint8_t priv_key[33] = {0};
  uint8_t pub_key[34] = {0};
  hdnode_from_seed( seed, 64, ED25519_NAME, &node);
    // [Chain m]
  hdnode_fill_public_key(&node);


  // [Chain m/0']
  hdnode_private_ckd_prime(&node, 0);
  hdnode_fill_public_key(&node);
 

  // [Chain m/0'/1']
  hdnode_private_ckd_prime(&node, 1);
  hdnode_fill_public_key(&node);

  
  memcpy(priv_key, node.private_key, 32);
  memcpy(pub_key, node.public_key, 33);  


  HDNode node2;  
  uint8_t priv_key2[33] = {0};
  uint8_t pub_key2[34] = {0}; 
  hdnode_from_seed( seed, 64, ED25519_NAME, &node2);
  // [Chain m/0']
  hdnode_private_ckd_prime(&node2, 0);
  hdnode_private_ckd_prime(&node2, 1);
  hdnode_fill_public_key(&node2);

  
  memcpy(priv_key2, node2.private_key, 32);
  memcpy(pub_key2, node2.public_key, 33);  

  TEST_ASSERT_EQUAL_MEMORY( priv_key2, priv_key, 32);
  TEST_ASSERT_EQUAL_MEMORY( pub_key2, pub_key, 33);

}

void test_mnemonic_creation(){

  #define SEED_SIZE 64
  #define SEED_SIZE_MNEMONIC_TO_SEED 32
  uint8_t secret_seed[SEED_SIZE] = {0};

  //esp_fill_random( secret_seed, SEED_SIZE_MNEMONIC_TO_SEED);
  for( int i = 0; i< 16; i++)
    secret_seed[i]= (uint8_t)random();
  // Generate a 12-word mnemonic phrase from the master seed
  const char * mnemonic_phrase = mnemonic_from_data(secret_seed, 16);

  TEST_ASSERT_NOT_NULL( mnemonic_phrase);
}



int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_key_derivation);
  RUN_TEST(test_b58_encode_decode);
  RUN_TEST(test_challenge_signing);
  RUN_TEST(rddl_auth_test);
  RUN_TEST(test_derivation);
  //RUN_TEST(test_mnemonic_creation);


  return UNITY_END();
}
