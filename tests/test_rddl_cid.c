#include "unity.h"
#include "rddl_cid.h"
#include "tests.h"
#include <string.h>
#include <stdio.h> // Include this for printf

const char* DATA = "{\"rddl\": \"rddl\"}";
const unsigned int CODEC = 0x12;
const int VERSION = 1;
const char* base32_cid = "AEJGIOBYGBSGGM3BGNTDAOJTG4ZTEYZXMEZWINRYG4ZTANZSGBSDSN3BMFRTCN3BGRSTKZJRGQYWCNLBHEYTCMDDHA2DKYZVMFSDSNLGMY";

// bafkreiglfbe7vxow2lladz7uwnmkm5qoctwb5qjjxtfd5bbmppny37cypu
// bafkreigfj22fcm7l2tofdpfdcgv6emqr373frhw2npf2ra2hgcifxxyjlu
// bafkreiczdg5vwojt6t55bfadj75w5hi4fnzbmycnvv4ob6zs6mek6impea
// bafkreid6r4khw3kfv6aoxymxuaz3bu3nczkzhb4ztrrz3z7wxd5q3hhpvu
// bafkreia4ztmef4dvinwidib36la53fzzkslyhvnotx6rnoqwrq2hrersou
// bafkrfwea3q5d6cjxgld2hvuhgbza3f5kyf5e4xqudjnjcegiixc23fp7

void test_cid_create_from_string(void) {
    // Call create_from_string
    char* result = create_from_string(VERSION, CODEC, DATA);

    // Copy the result into a temporary variable so we can free result before the assertion
    char* result_copy = strdup(result);
    
    // Free the result immediately after copying it
    free(result);

    // Then perform the test assertion
    TEST_ASSERT_EQUAL_STRING(base32_cid, result_copy);

    // Free the copy after the assertion
    free(result_copy);
}

void test_cid_create_from_string_2(void) {
    printf("test_cid_create_from_string_2\n");
    // Call create_from_string
    char* result = create_from_string_v2(DATA);

    // Then perform the test assertion
    TEST_ASSERT_EQUAL_STRING(base32_cid, result);

    // Free the result after the assertion
    free(result);
}


void test_decode(void) {
    // Call decode
    int version;
    unsigned int codec;
    uint8_t hash[SHA256_DIGEST_LENGTH];
    decode(base32_cid, &version, &codec, hash);

    uint8_t expected_hash[SHA256_DIGEST_LENGTH];
    sha256(DATA, strlen(DATA), expected_hash);

    // Perform the test assertions
    TEST_ASSERT_EQUAL_INT(VERSION, version);
    TEST_ASSERT_EQUAL_INT(CODEC, codec);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(expected_hash, hash, SHA256_DIGEST_LENGTH);
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_cid_create_from_string);
    RUN_TEST(test_cid_create_from_string_2);
    RUN_TEST(test_decode);
    return UNITY_END();
}
