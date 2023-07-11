#include <stdlib.h>
#include <string.h>
#include <stdio.h> 
#include "sha2.h"
#include "base32.h"
#include "rddl_cid.h"

char* create_from_string(int version, unsigned int codec, const char* data) {
    uint8_t hash[SHA256_DIGEST_LENGTH];
    sha256(data, strlen(data), hash);

    char pre_encoded_cid[SHA256_DIGEST_LENGTH + 10]; // 10 extra spaces for version and codec
    sprintf(pre_encoded_cid, "%d%d", version, codec);
    memcpy(pre_encoded_cid + 4, hash, SHA256_DIGEST_LENGTH);

    size_t buffer_size = (strlen(pre_encoded_cid) + 4) / 5 * 8 + 1;
    char* base32_cid = (char*)malloc(buffer_size);
    base32_encode((const uint8_t*)pre_encoded_cid, strlen(pre_encoded_cid), base32_cid, buffer_size, BASE32_ALPHABET_RFC4648);
    
    return base32_cid;
}

void sha256(const char* data, size_t data_size, uint8_t* hash) {
    sha256_Raw((const uint8_t*)data, data_size, hash);
}
