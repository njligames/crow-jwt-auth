#!/bin/bash

API_URL="http://localhost:18080"
USERNAME="admin"
PASSWORD="password123"

echo "🔐 Testing login endpoint..."
LOGIN_RESPONSE=$(curl -s -u $USERNAME:$PASSWORD $API_URL/login)

if [[ $LOGIN_RESPONSE == *"token"* ]]; then
    echo "✅ Login succeeded."
    TOKEN=$(echo $LOGIN_RESPONSE | sed -n 's/.*"token":"\([^"]*\)".*/\1/p')
    echo "📦 Received JWT: $TOKEN"
else
    echo "❌ Login failed. Response: $LOGIN_RESPONSE"
    exit 1
fi

echo -e "\n🔒 Accessing protected endpoint with token..."
PROTECTED_RESPONSE=$(curl -s -H "Authorization: Bearer $TOKEN" $API_URL/protected)

if [[ $PROTECTED_RESPONSE == *"Welcome"* ]]; then
    echo "✅ Access granted: $PROTECTED_RESPONSE"
else
    echo "❌ Access denied: $PROTECTED_RESPONSE"
    exit 1
fi

echo -e "\n🚫 Testing login with wrong password..."
BAD_LOGIN=$(curl -s -u $USERNAME:wrongpass $API_URL/login)

if [[ $BAD_LOGIN == *"token"* ]]; then
    echo "❌ Login should have failed but succeeded!"
    exit 1
else
    echo "✅ Login failed as expected: $BAD_LOGIN"
fi

echo -e "\n🚫 Accessing protected with invalid token..."
BAD_TOKEN="ey.invalid.token"
INVALID_RESPONSE=$(curl -s -H "Authorization: Bearer $BAD_TOKEN" $API_URL/protected)

if [[ $INVALID_RESPONSE == *"Invalid token"* ]]; then
    echo "✅ Invalid token correctly rejected."
else
    echo "❌ Invalid token unexpectedly succeeded! Response: $INVALID_RESPONSE"
    exit 1
fi

echo -e "\n🎉 All tests completed successfully!"
