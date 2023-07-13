#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "sha2.h"
#include "base32.h"
#include "rddl_cid.h"

void string_to_lowercase(char* str) {
    for(int i = 0; str[i]; i++){
      str[i] = tolower(str[i]);
    }
}

char* create_from_string(const char* data) {
    uint8_t hash[SHA256_DIGEST_LENGTH];
    sha256(data, strlen(data), hash);

    uint8_t pre_encoded_cid[SHA256_DIGEST_LENGTH + 4];  // 4 extra bytes for version and codec and digest length
    pre_encoded_cid[0] = 0x01;  // cidv1
    pre_encoded_cid[1] = 0x55;  // raw multicodec
    pre_encoded_cid[2] = 0x12;  // sha256
    pre_encoded_cid[3] = 0x20;  // sha256 digest length
    memcpy(pre_encoded_cid + 4, hash, SHA256_DIGEST_LENGTH);  // copy the hash after the version and codec

    size_t input_length = SHA256_DIGEST_LENGTH + 4;  // calculate the length of the actual content to be encoded
    size_t buffer_size = (input_length + 4) / 5 * 8 + 1;  // calculate the buffer size for the base32-encoded string

    char* base32_cid = (char*)malloc(buffer_size + 2);  // Allocate 2 extra bytes: one for the 'b' prefix and one for the null terminator
    base32_cid[0] = 'b';  // Add 'b' prefix
    base32_encode(pre_encoded_cid, input_length, base32_cid + 1, buffer_size, BASE32_ALPHABET_RFC4648);
    string_to_lowercase(base32_cid);
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
