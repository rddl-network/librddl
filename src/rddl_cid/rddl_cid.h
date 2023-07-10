#ifndef RDDL_CID_H
#define RDDL_CID_H

#include <string>
#include <vector>

namespace RDDL {

class Cid {
public:
    // constructor
    Cid(int version, unsigned int codec)
            : version_(version), codec_(codec) {}

    // destructor
    ~Cid() {}

    // create from bytes
    std::string CreateFromString(const std::string& data);

    // encrypt from string
    static std::string sha256(const std::string& data);

private:
    int version_;
    std::vector<unsigned char> hash_;
    unsigned int codec_;

    // encode CID
    std::vector<unsigned char> Encode() const;
};

// SHA256 hash function
std::string sha256(const std::string& data);

} // namespace RDDL

#endif // RDDL_CID_H