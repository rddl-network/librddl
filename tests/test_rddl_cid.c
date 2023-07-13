#include "unity.h"
#include "rddl_cid.h"
#include "tests.h"
#include <string.h>
#include <stdio.h> // Include this for printf

const char* DATA = "{\"rddl\": \"rddl\"}";
const unsigned int CODEC = 0x12;
const int VERSION = 1;
const char* expected_base32_cid = "bafkreigyqdodupyjg4zmpi6wq4yhedmxvlaxuts6cqnfveiqzbc4llmv74";


void test_cid_create_from_string(void) {

    // Call create_from_string
    char* result = create_from_string(DATA);
    // free(result);

    // printf("TEST /n");
    printf("Result: %s\n", result);
    fflush(stdout);
    // Then perform the test assertion
    // TEST_ASSERT_EQUAL_INT(strlen(result), 59);
    TEST_ASSERT_EQUAL_STRING(result, expected_base32_cid);

    // Free the result after the assertion
    free(result);
}


// void test_decode(void) {
//     // Call decode
//     int version;
//     unsigned int codec;
//     uint8_t hash[SHA256_DIGEST_LENGTH];
//     decode(expected_base32_cid, &version, &codec, hash);

//     uint8_t expected_hash[SHA256_DIGEST_LENGTH];
//     sha256(DATA, strlen(DATA), expected_hash);

//     // Perform the test assertions
//     TEST_ASSERT_EQUAL_INT(VERSION, version);
//     TEST_ASSERT_EQUAL_INT(CODEC, codec);
//     TEST_ASSERT_EQUAL_UINT8_ARRAY(expected_hash, hash, SHA256_DIGEST_LENGTH);
// }


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_cid_create_from_string);
    // RUN_TEST(test_decode);
    return UNITY_END();
}
