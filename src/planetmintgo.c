#include "sha2.h"
#include "ripemd160.h"

#include "planetmintgo.h"


void pubkey2address( const uint8_t* pubkey, uint8_t* address){
    SHA256_CTX ctx;
    uint8_t ripemd160_hash[RIPEMD160_DIGEST_LENGTH] = {0};

    uint8_t hash[SHA256_DIGEST_LENGTH+1] = {0};
    sha256_Init(&ctx);
    // Hash the string
    sha256_Update(&ctx,pubkey, 33);
    sha256_Final(&ctx, hash);

    ripemd160((const uint8_t *)pubkey, SHA256_DIGEST_LENGTH, ripemd160_hash );
    memcpy( address, ripemd160_hash, 20 );

}


