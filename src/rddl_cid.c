#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sha2.h"
#include "base32.h"
#include "rddl_cid.h"

char* create_from_string(int version, unsigned int codec, const char* data) {
    uint8_t hash[SHA256_DIGEST_LENGTH];
    sha256(data, strlen(data), hash);

    char pre_encoded_cid[SHA256_DIGEST_LENGTH * 2 + 10] = {0}; // 10 extra spaces for version and codec, *2 for hex representation
    sprintf(pre_encoded_cid, "%d%d", version, codec);

    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        sprintf(pre_encoded_cid + strlen(pre_encoded_cid), "%02x", hash[i]); // convert to hex string
    }

    size_t buffer_size = (strlen(pre_encoded_cid) + 4) / 5 * 8 + 1;
    char* base32_cid = (char*)malloc(buffer_size);
    base32_encode((const uint8_t*)pre_encoded_cid, strlen(pre_encoded_cid), base32_cid, buffer_size, BASE32_ALPHABET_RFC4648);

    return base32_cid;
}

void sha256(const char* data, size_t data_size, uint8_t* hash) {
    sha256_Raw((const uint8_t*)data, data_size, hash);
}


void decode(const char* base32_cid, int* version, unsigned int* codec, uint8_t* hash) {
    // Calculate the size of the buffer required to hold the decoded string.
    size_t buffer_size = (strlen(base32_cid) + 7) / 8 * 5 + 1; // +1 for null terminator
    char* pre_encoded_cid = (char*)malloc(buffer_size);
    
    // Decode the Base32-encoded string
    base32_decode((const uint8_t*)base32_cid, strlen(base32_cid), (uint8_t*)pre_encoded_cid, buffer_size, BASE32_ALPHABET_RFC4648);

    // Extract the version and codec
    sscanf(pre_encoded_cid, "%d%d", version, codec);

    // Extract the hash
    memcpy(hash, pre_encoded_cid + 4, SHA256_DIGEST_LENGTH);

    // Free the memory allocated for pre_encoded_cid
    free(pre_encoded_cid);
}