#pragma once
#include <jwt-cpp/jwt.h>
#include <string>

inline std::string generate_token(const std::string& username) {
    try {
        std::string jwtSecret = getenv("JWT_SECRET");
        if(jwtSecret.empty()) {
            jwtSecret = "secret";
        }
        return jwt::create()
                .set_issuer("crow-auth")
                .set_type("JWS")
                .set_subject(username)
                .set_issued_at(std::chrono::system_clock::now())
                .set_expires_at(std::chrono::system_clock::now() + std::chrono::minutes(30))
                .sign(jwt::algorithm::hs256{jwtSecret.c_str()});
    } catch (const std::exception& e) {
        std::cerr << "JWT validation error: " << e.what() << std::endl;
    }
    return "";
}

inline bool validate_token(const std::string& token, std::string &subject) {
    try {
        std::string jwtSecret = getenv("JWT_SECRET");
        if(jwtSecret.empty()) {
            jwtSecret = "secret";
        }
        auto decoded = jwt::decode(token);
        auto verifier = jwt::verify()
                .allow_algorithm(jwt::algorithm::hs256{jwtSecret.c_str()})
                .with_issuer("crow-auth");
        verifier.verify(decoded);
        subject = decoded.get_subject();
        return true;
    } catch (const std::exception& e) {
        std::cerr << "JWT validation error: " << e.what() << std::endl;
    }
    return false;
}
