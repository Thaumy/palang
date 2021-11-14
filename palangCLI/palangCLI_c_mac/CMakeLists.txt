cmake_minimum_required(VERSION 3.20)
project(palangCLI C)

set(CMAKE_C_STANDARD 11)

# OpenSSL
link_directories(/opt/homebrew/Cellar/openssl@3/3.0.0_1/lib)
include_directories(/opt/homebrew/Cellar/openssl@3/3.0.0_1/include)
link_libraries(libcrypto.a)

add_executable(palangCLI src/main.c src/crypto/rsa.h src/crypto/aes.h src/socket/tcp.h src/encoding/base64.h src/encoding/hex.h src/util/str.h src/util/mem.h src/util/cli.h)

target_link_libraries(palangCLI)