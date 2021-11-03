cmake_minimum_required(VERSION 3.20)
project(palangCLI C)

set(CMAKE_C_STANDARD 11)

# OpenSSL
link_directories(D:/app/OpenSSL-Win64/lib)
include_directories(D:/app/OpenSSL-Win64/include)
link_libraries(openssl libcrypto libssl)

add_executable(palangCLI src/main.c src/crypto/rsa.h src/crypto/aes.h src/socket/tcp.h src/encoding/base64.h src/encoding/hex.h src/util/str.h src/util/mem.h src/util/cli.h)

target_link_libraries(palangCLI ws2_32)