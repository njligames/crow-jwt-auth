
# 🔐 Crow JWT Auth API

[![Build](https://img.shields.io/badge/build-passing-brightgreen)](https://cmake.org/)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue)](https://en.cppreference.com/w/cpp/17)

> A minimal C++ REST API built with [Crow](https://github.com/CrowCpp/Crow) that supports **Basic Auth** and **JWT** for secure access control.

---

## 📦 Features

- 🔐 Basic Authentication (`Authorization: Basic`)
- 📤 JWT Token issuance
- 🔒 JWT-Protected endpoints
- 🔑 Password hashing via SHA-256
- ✅ Ready-to-use testing script
- 🧰 Built with C++17 + Crow + jwt-cpp

---

## 🚀 Quick Start

### 🔧 Setup

```bash
# Clone this repo
git clone https://github.com/yourusername/crow-jwt-auth.git
cd crow-jwt-auth

# Clone required libraries
git clone https://github.com/CrowCpp/Crow.git crow
git clone https://github.com/Thalhammer/jwt-cpp.git jwt-cpp

# Build the app
mkdir build && cd build
cmake ..
make
./main
```

---

## 🔐 Setting JWT Secret

Set your secret key as an environment variable:

```bash
export JWT_SECRET=$(openssl rand -base64 32)
```

This secret is used to sign and verify JWT tokens.

---

## 🔑 API Endpoints

### 🔓 `GET /login`

Authenticate using Basic Auth and receive a JWT.

**Request Header:**

```
Authorization: Basic base64(username:password)
```

**Success Response:**

```json
{
  "token": "<JWT>"
}
```

---

### 🔒 `GET /protected`

Access protected resources with a Bearer token.

**Request Header:**

```
Authorization: Bearer <JWT>
```

**Success Response:**

```
Hello, <username>! Welcome to the protected resource.
```

---

## 🧪 Run Tests

A full `curl` test script is included:

```bash
chmod +x test_api.sh
./test_api.sh
```

Covers:

* ✅ Successful login
* 🔒 Protected access
* 🚫 Failed login
* 🚫 Invalid token test

---

## 🛠 Tech Stack

* **C++17**
* [Crow](https://github.com/CrowCpp/Crow) - C++ micro web framework
* [jwt-cpp](https://github.com/Thalhammer/jwt-cpp) - JSON Web Token for C++
* OpenSSL - used for SHA-256 password hashing

---

## ⚠️ Security Notes

* Replace SHA-256 with bcrypt or Argon2 in production
* Never hardcode secrets – use secure env management
* Consider rate limiting and HTTPS in production

---

## 📄 License

MIT License • © \[Your Name]

---

## 🌐 GitHub Pages Docs (Optional)

To enable GitHub Pages:

1. Create a `docs/` folder.
2. Add a copy of this `README.md` as `index.md`.
3. Enable GitHub Pages under repository settings pointing to `main/docs`.

---

## 🙋‍♂️ Contributions

PRs are welcome! If you find issues or want to improve security/hashing/token scopes, feel free to open a PR.

---

```

---

Would you like me to generate a `docs/index.md` for GitHub Pages right now too?
```
