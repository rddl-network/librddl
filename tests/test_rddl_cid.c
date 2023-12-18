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



int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_cid_create_from_string);
    RUN_TEST(test_decode_cid_v1);
    return UNITY_END();
}
