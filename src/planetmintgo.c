#include "sha2.h"
#include "ripemd160.h"
#include "base32.h"
#include "rddl.h"
#include "planetmintgo.h"


void pubkey2address( const uint8_t* pubkey, size_t key_length, uint8_t* address){
    SHA256_CTX ctx;
    uint8_t ripemd160_hash[RIPEMD160_DIGEST_LENGTH] = {0};

    uint8_t hash[SHA256_DIGEST_LENGTH] = {0};
    sha256_Init(&ctx);
    // Hash the string
    sha256_Update(&ctx,pubkey, key_length);
    sha256_Final(&ctx, hash);

    ripemd160((const uint8_t *)hash, SHA256_DIGEST_LENGTH, ripemd160_hash );
    memcpy( address, ripemd160_hash, 20 );
}

int getAddressString( const uint8_t* address, char* stringbuffer)
{
    const char* hrp = "cosmos";
    size_t data_len = 32;
    uint8_t paddingbuffer[32] = {0};
    uint8_t base32_enc[100] = {0};
    base32_encode_unsafe(address, 20, base32_enc);

    size_t len = strlen(base32_enc);
    return bech32_encode(stringbuffer, hrp, base32_enc, data_len);

}


