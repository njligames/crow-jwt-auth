Here’s a complete and professional `README.md` file for your **Crow C++ JWT Auth API** app:

---

```markdown
# 🔐 Crow JWT Auth API

A minimal C++ REST API built with [Crow](https://github.com/CrowCpp/Crow) that supports both **Basic Authentication** and **JWT-based authorization** to protect API resources.

---

## 🚀 Features

- ✅ Basic Authentication via `Authorization: Basic <base64>`
- 🔑 JWT Token issuance on successful login
- 🔒 Protected route access via `Authorization: Bearer <token>`
- ⌛ JWT expiration handling (default: 30 minutes)
- 🔐 Password hashing using SHA-256
- 🧪 API test script using `curl`

---

## 🏗️ Project Structure

```

crow-jwt-auth/
├── main.cpp            # Entry point of the server
├── jwt\_utils.h         # JWT token generation and verification
├── basic\_auth.h        # Basic Auth header parsing and password hashing
├── test\_api.sh         # Bash script to test login & protected route
├── CMakeLists.txt      # Build configuration
└── crow/ & jwt-cpp/    # Dependencies (Crow and jwt-cpp as submodules or folders)

````

---

## 🧰 Requirements

- C++17+
- CMake 3.10+
- Crow (header-only or cloned submodule)
- [jwt-cpp](https://github.com/Thalhammer/jwt-cpp)
- OpenSSL (for SHA-256)

---

## 🔧 Setup & Build

```bash
# Clone the repo and enter it
git clone https://github.com/yourusername/crow-jwt-auth.git
cd crow-jwt-auth

# Clone dependencies
git clone https://github.com/CrowCpp/Crow.git crow
git clone https://github.com/Thalhammer/jwt-cpp.git jwt-cpp

# Build
mkdir build && cd build
cmake ..
make
./main
````

---

## 🔐 JWT Secret

Set a secure secret key before starting the app:

```bash
export JWT_SECRET=$(openssl rand -base64 32)
```

The secret is used for signing and verifying JWT tokens.

---

## 🧪 Testing the API

Run the included test script:

```bash
./test_api.sh
```

It will:

* Login with basic auth
* Extract the JWT
* Use it to access the protected route
* Test invalid scenarios

---

## 📬 API Endpoints

### `GET /login`

> Logs in using Basic Auth and returns a JWT

**Headers:**

```
Authorization: Basic base64(username:password)
```

**Response:**

```json
{
  "token": "<JWT>"
}
```

---

### `GET /protected`

> Access protected resource using a Bearer token

**Headers:**

```
Authorization: Bearer <JWT>
```

**Response:**

```
Hello, <username>! Welcome to the protected resource.
```

---

## 🔒 Security Notes

* Replace SHA-256 with bcrypt/argon2 for production password hashing.
* Store JWT secret securely (not hardcoded).
* Set proper expiration time and enforce refresh policies.

---

## 📃 License

MIT © \[Your Name]

```

---

Would you like me to add badges (build, version, license) or convert this to a GitHub Pages-style doc?
```
