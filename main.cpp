#include "crow.h"
#include "jwt_utils.h"
#include "basic_auth.h"

std::unordered_map<std::string, std::string> user_db = {
    {"admin", hash_password("password123")},
    {"user", hash_password("mypassword")}
};

int main() {
    crow::SimpleApp app;

    // Public login route - returns JWT if valid basic auth
    CROW_ROUTE(app, "/login").methods("GET"_method)([](const crow::request& req) {
        auto auth = req.get_header_value("Authorization");
        if (auth.find("Basic ") != 0) return crow::response(401, "Unauthorized");

        auto [username, password] = parse_basic_auth(auth);
        if (user_db.count(username) == 0 || user_db[username] != hash_password(password)) {
            return crow::response(403, "Forbidden");
        }

        auto token = generate_token(username);
        crow::json::wvalue result;
        result["token"] = token;
        return crow::response{result};
    });

    // Protected route - requires valid JWT
    CROW_ROUTE(app, "/protected").methods("GET"_method)([](const crow::request& req) {
        auto auth = req.get_header_value("Authorization");
        if (auth.find("Bearer ") != 0) return crow::response(401, "Unauthorized");

        auto token = auth.substr(7);
        try {
            std::string username;
            if(validate_token(token, username))
                return crow::response(200, "Hello, " + username + "! Welcome to the protected resource.");
            return crow::response(403, "Invalid token");
        } catch (...) {
            return crow::response(403, "Invalid token");
        }
    });

    app.port(18080).multithreaded().run();
}
