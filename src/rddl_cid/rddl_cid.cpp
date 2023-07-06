#include <string>
#include <vector>
#include "libs/multihash/multihash/multihash.h"
#include "libs/multihash/multihash/algorithm.h"
#include "libs/multibase/multibase/basic_algorithm.h"
#include "libs/multibase/multibase/encoding.h"
#include "libs/multibase/multibase/codec.h"

namespace IPFS {
    unsigned int undefined_codec = 0x00;
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
        std::string CreateFromString(const std::string& data) {
            std::string result = sha256(data);

            static constexpr auto encoding = multibase::encoding::base_32;
            std::string cid_hash = std::to_string(this->version_) +  std::to_string(this->codec_) + result;
            return multibase::encode(cid_hash, encoding);
        }

        static std::string sha256(const std::string& data) {
            auto code = multihash::code::sha2_256;
            auto algorithm = multihash::algorithm::create(code);
            algorithm->update(data);
            auto result = std::string(32, '\0');
            algorithm->digest(result);
            return result;
        }

    private:
        int version_ = cid_version_1;
        unsigned int codec_ = sha2_256_codec;
    };

} // namespace IPFS
