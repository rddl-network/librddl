#include "unity.h"
#include "rddl_cid.h"
#include "tests.h"
#include <string.h>
#include <stdio.h> // Include this for printf

const char* DATA = "{\"rddl\": \"rddl\"}";
const unsigned int CODEC = 0x12;
const int VERSION = 1;
const char* EXPECTED_BASE32_CID = "bafkreigyqdodupyjg4zmpi6wq4yhedmxvlaxuts6cqnfveiqzbc4llmv74";


void test_cid_create_from_string(void) {

    // Call create_from_string
    char* result = create_cid_v1_from_string(DATA);

    TEST_ASSERT_EQUAL_INT(strlen(result), 59);
    TEST_ASSERT_EQUAL_STRING(result, EXPECTED_BASE32_CID);
}


void test_decode_cid_v1(void) {
    // Calculate the original hash
    uint8_t original_hash[SHA256_DIGEST_LENGTH];
    sha256(DATA, strlen(DATA), original_hash);

    // Call decode_from_string
    uint8_t* decoded_hash = decode_cid_v1(EXPECTED_BASE32_CID);

    // Check that the decoded hash matches the original hash
    TEST_ASSERT_EQUAL_UINT8_ARRAY(original_hash, decoded_hash, SHA256_DIGEST_LENGTH);

}


void test_pop_failure_cid_valid(void) {
    char expCIDRDDL [] = "bafkreiaxzxpf7aezpaqvzdxqvulpjclkh3gep4ji7g6fj6qm6mgxx3idna";
    char orgData []= "{\"Time\":\"2024-05-27T11:06:34\"}";
    uint8_t original_hash[SHA256_DIGEST_LENGTH];
    sha256(orgData, strlen(orgData), original_hash);

    char* cid = create_cid_v1_from_string( (const char*) orgData  );
        // Call decode_from_string

    TEST_ASSERT_EQUAL_STRING( expCIDRDDL, cid);

    uint8_t* expected_hash = decode_cid_v1(expCIDRDDL);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(original_hash, expected_hash, SHA256_DIGEST_LENGTH);
}

void test_pop_failure_cid2_valid(void) {
    char expCIDTasmota [] = "bafkreiau2g5f6svyy5jnqktmvbq547ovmzigkvjzg5mez6pwf3h3t5mf2m";
    char orgData []= "{\"Time\":\"2024-05-27T15:47:18\"}";
    uint8_t original_hash[SHA256_DIGEST_LENGTH];
    sha256(orgData, strlen(orgData), original_hash);

    char* cid = create_cid_v1_from_string( (const char*) orgData  );
        // Call decode_from_string

    TEST_ASSERT_EQUAL_STRING( expCIDTasmota, cid);
}



int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_cid_create_from_string);
    RUN_TEST(test_decode_cid_v1);
    RUN_TEST(test_pop_failure_cid_valid);
    RUN_TEST(test_pop_failure_cid2_valid);
    return UNITY_END();
}
