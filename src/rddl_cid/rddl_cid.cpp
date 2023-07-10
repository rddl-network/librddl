#include <string>
#include <vector>
#include "libs/trezor-crypto/sha2.h"
#include "libs/trezor-crypto/base32.h"

namespace RDDL {
    const unsigned int sha2_256_codec = 0x12;
    const unsigned int cid_version_1 = 0x01;

    class Cid {
    public:
        // constructor
        Cid(int version, unsigned int codec)
                : version_(version), codec_(codec) {}

        // destructor
        ~Cid() {}

        // cast from bytes
        std::string CreateFromString(const std::string& data) const {
            std::string result = sha256(data);

            char base32_hash[BASE32_ENCODE_LENGTH(SHA256_DIGEST_LENGTH)];
            base32_encode((const uint8_t *)result.c_str(), result.size(), base32_hash, BASE32_FLAG_BASE32);

            std::string cid_hash = std::to_string(this->version_) +  std::to_string(this->codec_) + base32_hash;
            return cid_hash;
        }

        static std::string sha256(const std::string& data) {
            uint8_t hash[SHA256_DIGEST_LENGTH];
            sha256_Raw((const uint8_t *)data.c_str(), data.size(), hash);
            return std::string((char *)hash, SHA256_DIGEST_LENGTH);
        }

    private:
        int version_ = cid_version_1;
        unsigned int codec_ = sha2_256_codec;
    };

} // namespace CID
