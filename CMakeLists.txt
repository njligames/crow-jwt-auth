cmake_minimum_required(VERSION 3.10)
project(crow_jwt_auth)

set(CMAKE_CXX_STANDARD 17)


include(FetchContent)

FetchContent_Declare(
        crow
        GIT_REPOSITORY https://github.com/CrowCpp/Crow.git
        GIT_TAG master
)
FetchContent_MakeAvailable(crow)

FetchContent_Declare(
    asio
    GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
    GIT_TAG asio-1-28-0  # Use latest stable version
)

FetchContent_MakeAvailable(asio)



# JWT-CPP
FetchContent_Declare(
        jwt-cpp
        GIT_REPOSITORY https://github.com/Thalhammer/jwt-cpp
        GIT_TAG v0.5.0
)

FetchContent_MakeAvailable(jwt-cpp)



include_directories( ${crow_SOURCE_DIR}/include  ${asio_SOURCE_DIR}/asio/include)
# include_directories(jwt-cpp/include)

add_executable(main main.cpp)
target_link_libraries(main jwt-cpp::jwt-cpp pthread)
