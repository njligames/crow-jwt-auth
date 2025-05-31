#pragma once
#include <crow.h>
#include <string>
#include <unordered_map>
#include <sstream>
#include <openssl/sha.h>
#include <iomanip>

inline std::string hash_password(const std::string& pass) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(pass.c_str()), pass.size(), hash);

    std::ostringstream os;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
        os << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];

    return os.str();
}

inline std::pair<std::string, std::string> parse_basic_auth(const std::string& auth_header) {
    auto encoded = crow::utility::base64decode(auth_header.substr(6));
    auto colon = encoded.find(':');
    return {encoded.substr(0, colon), encoded.substr(colon + 1)};
}
