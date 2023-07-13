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
    sprintf(pre_encoded_cid, "%c%c", version, codec);  // encode as single bytes

    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        sprintf(pre_encoded_cid + strlen(pre_encoded_cid), "%02x", hash[i]); // convert to hex string
    }

    size_t buffer_size = (strlen(pre_encoded_cid) + 4) / 5 * 8 + 1;
    char* base32_cid = (char*)malloc(buffer_size);
    base32_encode((const uint8_t*)pre_encoded_cid, strlen(pre_encoded_cid), base32_cid, buffer_size, BASE32_ALPHABET_RFC4648);

    return base32_cid;
}

char* create_from_string_v2(const char* data) {
    uint8_t hash[SHA256_DIGEST_LENGTH];
    sha256(data, strlen(data), hash);

    uint8_t pre_encoded_cid[SHA256_DIGEST_LENGTH + 3];  // 3 extra bytes for version and codec
    pre_encoded_cid[0] = 0x01;  // cidv1
    pre_encoded_cid[1] = 0x55;  // raw multicodec
    pre_encoded_cid[2] = 0x12;  // sha256
    memcpy(pre_encoded_cid + 3, hash, SHA256_DIGEST_LENGTH);  // copy the hash after the version and codec

    size_t input_length = SHA256_DIGEST_LENGTH + 3;  // calculate the length of the actual content to be encoded
    size_t buffer_size = (input_length + 4) / 5 * 8 + 1;  // calculate the buffer size for the base32-encoded string

    printf("input_length: %zu\n", input_length);
    printf("buffer_size: %zu\n", buffer_size);

    char* base32_cid = (char*)malloc(buffer_size + 2);  // Allocate 2 extra bytes: one for the 'b' prefix and one for the null terminator
    base32_cid[0] = 'b';  // Add 'b' prefix
    base32_encode(pre_encoded_cid, input_length, base32_cid + 1, buffer_size, BASE32_ALPHABET_RFC4648);
    base32_cid[buffer_size] = '\0';  // Null-terminate the string

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
    base32_decode((const char*)base32_cid, strlen(base32_cid), (uint8_t*)pre_encoded_cid, buffer_size, BASE32_ALPHABET_RFC4648);

    // Extract the version and codec
    *version = pre_encoded_cid[0];
    *codec = pre_encoded_cid[1];

    // Extract the hash
    char* hash_str = pre_encoded_cid + 2;  // change offset to 2
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        sscanf(hash_str + i * 2, "%2hhx", &hash[i]); // convert from hex string to bytes
    }

    // Free the memory allocated for pre_encoded_cid
    free(pre_encoded_cid);
}


