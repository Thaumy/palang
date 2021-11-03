//
// Created by Thaumy on 2021/11/1.
//

#ifndef OPENSSL_APPLINK_C
#define OPENSSL_APPLINK_C

#include <openssl/applink.c>

#endif //OPENSSL_APPLINK_C


#ifndef PALANGCLI_AES_H
#define PALANGCLI_AES_H

#include <math.h>
#include <openssl/aes.h>
#include "../encoding/hex.h"
#include "../util/mem.h"

///aes256加密
///0填充模式
char *aes256_encrpyt(char *plain, char *key) {
    int plainLength = strlen(plain);//u64
    int paddingLength = AES_BLOCK_SIZE - (plainLength % AES_BLOCK_SIZE);//填充长度
    {//防止当明文长度恰好为16（即AES_BLOCK_SIZE）时，仍填充一个新区块的情况
        if (paddingLength == AES_BLOCK_SIZE)
            paddingLength = 0;
    }
    int paddedPlainLength = plainLength + paddingLength;//填充后明文长度

    char *paddedPlain = malloc(sizeof(char) * (paddedPlainLength + 1));
    strcpy(paddedPlain, plain);
    fill0(paddedPlain + plainLength, paddingLength);//填充0

    AES_KEY aesKey;
    AES_set_encrypt_key(key, 256, &aesKey);

    //原始密文长度与填充后明文相同
    char *rawCipher = newStr(paddedPlainLength);

    int round = ceil((double) strlen(plain) / 16);//每次16字节的加密轮数
    for (int i = 0; i < round; ++i) {
        //一次只能加密16位
        AES_ecb_encrypt(paddedPlain + i * 16, rawCipher + i * 16, &aesKey, AES_ENCRYPT);
    }

    //将原始密文转换成可读密文，长度加倍
    char *readableCipher = newStr(paddedPlainLength * 2 + 1);
    //只循环到明文长度，防止将0填充格式化到最终结果
    for (int i = 0; i < paddedPlainLength; ++i) {
        ///转换成无符号char以防止格式化到ffffffff形式
        sprintf(readableCipher + 2 * i, "%02X", (unsigned char) rawCipher[i]);
    }

    return readableCipher;
}

///aes256解密
///cipher是可读的hex字符串（即非u8），它的位数始终是32的整数倍
char *aes256_decrpyt(char *cipher, char *key) {
    char *rawCipher = hex_decode(cipher);

    AES_KEY aesKey;
    AES_set_decrypt_key(key, 256, &aesKey);

    //明文长度始终是可读密文（cipher）的一半
    int plainLength = strlen(cipher) / 2;
    char *plain = newStr(plainLength);

    int round = ceil((double) strlen(rawCipher) / 16);//每次16字节的解密轮数
    for (int i = 0; i < round; ++i) {
        //一次只能解密16位
        AES_ecb_encrypt(rawCipher + i * 16, plain + i * 16, &aesKey, AES_DECRYPT);
    }

    return plain;
}

#endif //PALANGCLI_AES_H
