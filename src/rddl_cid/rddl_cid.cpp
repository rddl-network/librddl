#include <string>
#include <vector>
#include "sha2.h"
#include "base32.h"

namespace RDDL {
    const unsigned int sha2_256_codec = 0x12;
    const unsigned int cid_version_1 = 0x01;

    class Cid {
    public:
        // constructor
        Cid(int version = cid_version_1, unsigned int codec = sha2_256_codec)
                : version_(version), codec_(codec) {}

        // destructor
        ~Cid() {}

        // cast from bytes
        std::string CreateFromString(const std::string& data) const {
            std::string result = sha256(data);

            std::string pre_encoded_cid = std::to_string(version_) + std::to_string(codec_) + result;

            // Calculate the size of the buffer required to hold the Base32-encoded string.
            // Base32 encoding expands the data by a factor of 8/5 (it requires 8 bytes of output for every 5 bytes of input).
            // We add 4 to the size before dividing by 5 to ensure that any remainder is included in the output size (this is equivalent to rounding up).
            // We then multiply by 8 to get the output size.
            // We add 1 to the calculated size to make room for the null-terminator ('\0') at the end of the string.
            size_t buffer_size = (pre_encoded_cid.size() + 4) / 5 * 8 + 1;
            char* base32_cid = new char[buffer_size];
            base32_encode((const uint8_t *)pre_encoded_cid.c_str(), pre_encoded_cid.size(), base32_cid, buffer_size, BASE32_ALPHABET_RFC4648);

            std::string encoded_cid(base32_cid);
            delete[] base32_cid;
            return encoded_cid;
        }

    private:
        int version_;
        unsigned int codec_;
        
        static std::string sha256(const std::string& data) {
            uint8_t hash[SHA256_DIGEST_LENGTH];
            sha256_Raw((const uint8_t *)data.c_str(), data.size(), hash);
            return std::string((char *)hash, SHA256_DIGEST_LENGTH);
        }
    };

} // namespace RDDL