#ifndef RDDL_CID_H
#define RDDL_CID_H

#include <stddef.h>
#include <stdint.h>

/* SHA-256 constants */
#define SHA2_256_CODEC 0x12
#define CID_VERSION_1 0x01
#define SHA256_DIGEST_LENGTH 32

/* Function prototypes */
char* create_from_string(int version, unsigned int codec, const char* data);
void sha256(const char* data, size_t data_size, uint8_t* hash);
void decode(const char* base32_cid, int* version, unsigned int* codec, uint8_t* hash);

#endif /* RDDL_CID_H */
