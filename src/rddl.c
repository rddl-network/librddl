#include <stdio.h>
#include <sys/random.h>

#include "address.h"
#include "options.h"
#include "aes/aes.h"
#include "base32.h"
#include "base58.h"
#include "bignum.h"
#include "bip32.h"
#include "bip39.h"
#include "blake256.h"
#include "blake2b.h"
#include "blake2s.h"
#include "curves.h"
#include "ecdsa.h"
#include "ed25519-donna.h"
#include "curve25519-donna-scalarmult-base.h"
#include "ed25519-keccak.h"
#include "ed25519.h"
#include "hmac.h"
#include "memzero.h"
#include "nist256p1.h"
#include "pbkdf2.h"
#include "rand.h"
#include "rc4.h"
#include "rfc6979.h"
#include "script.h"
#include "secp256k1.h"
#include "sha2.h"
#include "sha3.h"

#include "rddl.h"
#ifdef TASMOTA
#include "esp_random.h"
#endif



uint8_t secret_seed[SEED_SIZE] = {0};

// the below mentioned array contains 8 times RDDL: "RDDLRDDLRDDLRDDLRDDLRDDLRDDLRDDL";
uint8_t private_key_machine_id[32] = { 0x52, 0x44, 0x44, 0x4c, 0x52, 0x44, 0x44, 0x4c, 0x52, 0x44, 0x44, 0x4c,\
                                       0x52, 0x44, 0x44, 0x4c, 0x52, 0x44, 0x44, 0x4c, 0x52, 0x44, 0x44, 0x4c,\
                                       0x52, 0x44, 0x44, 0x4c, 0x52, 0x44, 0x44, 0x4c };

const uint8_t *fromHexString(const char *str) {
  static uint8_t buf[FROMHEX_MAXLEN] = {0};
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

// convert byte array  hexadeciaml values of length strlen into string represetning the hexv values (thus doubling the size)
void toHexString(char *hexbuf, uint8_t *str, int strlen){
   // char hexbuf[strlen];
    for (int i = 0 ; i < strlen/2 ; i++) {
        sprintf(&hexbuf[2*i], "%02X", str[i]);
    }
}

const char* getMnemonic()
{
#ifdef TASMOTA
  esp_fill_random( secret_seed, SEED_SIZE_MNEMONIC_TO_SEED);
#else
  random_buffer(secret_seed, SEED_SIZE_MNEMONIC_TO_SEED);
#endif
  // Generate a 12-word mnemonic phrase from the master seed
  const char * mnemonic_phrase = mnemonic_from_data(secret_seed, SEED_SIZE_MNEMONIC_TO_SEED);
  return mnemonic_phrase;
}

const char* setSeed( char* pMnemonic, size_t len )
{
  if( !mnemonic_check( pMnemonic ) )
    return "";

  mnemonic_to_seed(pMnemonic, "", secret_seed, 0);
  return (const char*)pMnemonic;
}

const char* getMnemonicFromSeed( const uint8_t* seed, size_t length )
{
  // Generate a 12-word mnemonic phrase from the master seed
  const char * mnemonic_phrase = mnemonic_from_data(seed, length);

  printf("%s\n", mnemonic_phrase);
  return mnemonic_phrase;
}

bool getSeedFromMnemonic( const char* pMnemonic, size_t len, uint8_t* seedbuffer )
{
  if( !mnemonic_check( pMnemonic ) )
    return false;
  
  mnemonic_to_seed(pMnemonic, "", seedbuffer, NULL);
  return true;  
}

bool getKeyFromSeed( const uint8_t* seed, uint8_t* priv_key, uint8_t* pub_key, const char* curve_name){
  // we expect curve name to be ED25519_NAME or SECP256K1_NAME
  HDNode node;
  hdnode_from_seed( seed, SEED_SIZE, curve_name, &node);
  hdnode_private_ckd_prime(&node, 0);
  hdnode_private_ckd_prime(&node, 1);
  hdnode_fill_public_key(&node);
  memcpy(priv_key, node.private_key, 32);
  memcpy(pub_key, node.public_key, 33);
  return true;
}

bool SignDataHash(const char* data_str, size_t data_length, char* pubkey_out, char* sig_out, char* hash_out)
{
  //uint8_t seed[64] = {0};
  uint8_t hash[32] = {0};
  uint8_t priv_key[32] = {0};
  uint8_t pub_key[33] = {0};
  uint8_t signature[64] = {0};
  HDNode node2;
  SHA256_CTX ctx;
  const ecdsa_curve *curve = &secp256k1;

  getKeyFromSeed( secret_seed, priv_key, pub_key, SECP256K1_NAME );

  // Initialize the SHA-256 hasher

  sha256_Init(&ctx);
  // Hash the string
  sha256_Update(&ctx, (const uint8_t*) data_str, data_length);
  sha256_Final(&ctx, hash);

  int res = ecdsa_sign_digest(curve, priv_key, hash, signature, NULL, NULL);
  int verified = ecdsa_verify_digest(curve, pub_key, signature, hash);

  // prepare and convert outputs to hex-strings
  toHexString( pubkey_out, pub_key, 66);
  toHexString( sig_out, signature, 128);
  toHexString( hash_out, hash, 64);

  return verified;
}

int SignDataHashWithPrivKey(const uint8_t* digest, const uint8_t* priv_key, char* sig_out)
{
  uint8_t signature[64] = {0};
  const ecdsa_curve *curve = &secp256k1;

  int res = ecdsa_sign_digest(curve, priv_key, digest, signature, NULL, NULL);

  // prepare and convert outputs to hex-strings
  toHexString( sig_out, signature, 128);

  return res;
}

bool verifyDataHash(const char* sig_str, const char* pub_key_str, const char* hash_str)
{
  uint8_t hash[32] = {0};
  uint8_t signature[64] = {0};
  uint8_t pub_key[33] = {0};
  const ecdsa_curve *curve = &secp256k1;

  memcpy(signature, fromHexString(sig_str), 64);
  memcpy(pub_key, fromHexString(pub_key_str), 33);
  memcpy(hash, fromHexString(hash_str), 32);

  int verified = ecdsa_verify_digest(curve, pub_key, signature, hash);
  return verified;
}

bool getMachineIDSignature(  uint8_t* priv_key,  uint8_t* pub_key, uint8_t* signature, uint8_t* hash)
{
  const ecdsa_curve *curve = &secp256k1;

  SHA256_CTX ctx;
  sha256_Init(&ctx);
  // Hash the string
  sha256_Update(&ctx, (const uint8_t*) pub_key, 33);
  sha256_Final(&ctx, hash);

  int res = ecdsa_sign_digest(curve, priv_key, hash, signature, NULL, NULL);
  int verified = ecdsa_verify_digest(curve, pub_key, signature, hash);
  if( res == 0 && verified == 0)
    return true;
  else
    return false;
}

bool getMachineIDSignaturePublicKey( uint8_t* priv_key,  uint8_t* pub_key, uint8_t* signature)
{
  ecdsa_get_public_key33(&secp256k1, priv_key, pub_key);

  uint8_t hash[32]={0};
  bool ret = getMachineIDSignature(  priv_key,  pub_key, signature, hash);
  return ret;
}

const uint8_t *rddl_fromhex(const char *str)
{
    static uint8_t buf[FROMHEX_MAXLEN];
    int len = strlen(str) / 2;
    if (len > FROMHEX_MAXLEN)
        len = FROMHEX_MAXLEN;
    for (int i = 0; i < len; i++)
    {
        uint8_t c = 0;
        if (str[i * 2] >= '0' && str[i * 2] <= '9')
            c += (str[i * 2] - '0') << 4;
        if ((str[i * 2] ) >= 'A' && (str[i * 2] ) <= 'F')
            c += (10 + (str[i * 2] ) - 'A') << 4;
        if ((str[i * 2] ) >= 'a' && (str[i * 2] ) <= 'f')
            c += (10 + (str[i * 2] ) - 'a') << 4;
        if (str[i * 2 + 1] >= '0' && str[i * 2 + 1] <= '9')
            c += (str[i * 2 + 1] - '0');
        if ((str[i * 2 + 1]) >= 'A' && (str[i * 2 + 1] ) <= 'F')
            c += (10 + (str[i * 2 + 1] ) - 'A');
        if ((str[i * 2 + 1] ) >= 'a' && (str[i * 2 + 1] ) <= 'f')
            c += (10 + (str[i * 2 + 1] ) - 'a');
        buf[i] = c;
    }
    return buf;
}


size_t rddl_toHex(const uint8_t *array, size_t arraySize, char *output, size_t outputSize)
{
    if (array == NULL || output == NULL)
    {
        return 0;
    }
    // uint8_t * array = (uint8_t *) arr;
    if (outputSize < 2 * arraySize)
    {
        return 0;
    }
    memzero(output, outputSize);

    for (size_t i = 0; i < arraySize; i++)
    {
        output[2 * i] = (array[i] >> 4) + '0';
        if (output[2 * i] > '9')
        {
            output[2 * i] += 'a' - '9' - 1;
        }

        output[2 * i + 1] = (array[i] & 0x0F) + '0';
        if (output[2 * i + 1] > '9')
        {
            output[2 * i + 1] += 'a' - '9' - 1;
        }
    }
    return 2 * arraySize;
}
