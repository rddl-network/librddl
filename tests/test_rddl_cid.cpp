#include "tests.h"
#include "rddl_cid.h"  

void test_cid_create_from_string() {
    // Create an instance of your Cid class
    unsigned int codec = 0x12;
    RDDL::Cid cid(1, codec);  // Assuming version 1 and sha2_256 codec

    // Call CreateFromString
    const std::string data = "{\"rddl\": \"rddl\"}";

    std::string result = cid.CreateFromString(data);

    // Validate the result (depends on how you define correctness)
    std::string expected = "bafkreienv4wtwnyu6l4kgfs3fxfamfxz6nawrophftrndbau6ubxjcwfaa";
    TEST_ASSERT_EQUAL_STRING(result.c_str(), expected.c_str());
}


int main(void) {

  UNITY_BEGIN();
  RUN_TEST(test_cid_create_from_string);
  return UNITY_END();
}

