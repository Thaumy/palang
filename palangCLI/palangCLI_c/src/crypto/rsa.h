//
// Created by Thaumy on 2021/11/1.
//

#ifndef OPENSSL_APPLINK_C
#define OPENSSL_APPLINK_C

#include <openssl/applink.c>

#endif //OPENSSL_APPLINK_C


#ifndef PALANGCLI_RSA_H
#define PALANGCLI_RSA_H

#include <openssl/rsa.h>
#include <openssl/pem.h>
#include "../encoding/base64.h"
#include "../util/mem.h"

///生成rsa2048密钥对，返回值[0]为公钥，返回值[1]为私钥
///PEM格式，PKCS1填充模式
size_t *genRsa2048KeyPair() {
    BIGNUM *bignum = BN_new();
    RSA *rsa = RSA_new();
    //如需写入文件，请参考以下代码:
    //BIO *pubkeyFile = BIO_new_file("public.pem", "w+");
    //BIO *prikeyFile = BIO_new_file("private.pem", "w+");

    BIO *pubKeyBio = BIO_new(BIO_s_mem());
    BIO *priKeyBio = BIO_new(BIO_s_mem());

    BN_set_word(bignum, RSA_PKCS1_PADDING_SIZE);//PKCS1填充
    RSA_generate_key_ex(rsa, 2048, bignum, NULL);//2048位

    //将PKCS1格式公钥写入pubKey
    PEM_write_bio_RSA_PUBKEY(pubKeyBio, rsa);
    //将PKCS8格式私钥写入priKey
    PEM_write_bio_RSAPrivateKey(priKeyBio, rsa, NULL, NULL, 0, NULL, NULL);

    int pubKeyLength = 450;//经试验所得的公钥长度
    char *pubKey = newStr(pubKeyLength);
    BIO_read(pubKeyBio, pubKey, pubKeyLength);//将bio写入字符串

    int priKeyLength = 1674;//经试验所得的私钥长度
    char *priKey = newStr(priKeyLength);
    BIO_read(priKeyBio, priKey, priKeyLength);//将bio写入字符串

    BIO_free_all(pubKeyBio);
    BIO_free_all(priKeyBio);
    BN_free(bignum);
    RSA_free(rsa);

    //TODO 为何第二个不需要取地址???
    return (size_t *) {&pubKey, priKey};
}

char *rsa2048_encrypt(char *plain, char *pubKey) {
    //若要从文件流读入公钥，请参考以下代码：
    //FILE *pubKeyFile = fopen("public.pem", "r");
    //RSA *rsa = PEM_read_RSA_PUBKEY(pubKeyFile, NULL, NULL, NULL);

    //从内存（char *pubKey）读入公钥：
    BIO *pubKeyBio = BIO_new(BIO_s_mem());
    BIO_write(pubKeyBio, pubKey, 450);//公钥长度450
    RSA *rsa = PEM_read_bio_RSA_PUBKEY(pubKeyBio, NULL, NULL, NULL);


    //openssl doc:
    //RSA_size() returns the RSA modulus size in bytes.
    //It can be used to determine how much memory must be allocated for an RSA encrypted value.
    int size = RSA_size(rsa);//密文所需空间

    char *cipherHex = malloc(size + 1);//终止符+1
    fill0(cipherHex, size + 1);

    //openssl doc:
    //flen must not be more than RSA_size(rsa) - 11 for the PKCS #1 v1.5 based padding modes
    //flen是待加密文本的字节数，应始终保证flen不超过RSA_size(rsa) - 11
    int flen = strlen(plain) > size - 11 ? size - 11 : strlen(plain);
    RSA_public_encrypt(flen, plain, cipherHex, rsa, RSA_PKCS1_PADDING);

    RSA_free(rsa);
    //由于加密结果可能出现空字节，所以此处转base64需显示指定长度
    return base64_encode(cipherHex, size);
}

char *rsa2048_decrypt(char *cipher, char *priKey) {
    char *cipherHex = base64_decode(cipher);

    //若要从文件流读入私钥，请参考以下代码：
    //FILE *priKeyFile = fopen("private.pem", "r");
    //RSA *rsa = PEM_read_RSAPrivateKey(priKeyFile, NULL, NULL, NULL);

    //从内存（char *pubKey）读入公钥：
    BIO *priKeyBio = BIO_new(BIO_s_mem());
    BIO_write(priKeyBio, priKey, 1674);//私钥长度1674
    RSA *rsa = PEM_read_bio_RSAPrivateKey(priKeyBio, NULL, NULL, NULL);

    int size = RSA_size(rsa);//明文所需空间

    char *plain = malloc(size + 1);//终止符+1
    fill0(plain, size + 1);

    RSA_private_decrypt(size, cipherHex, plain, rsa, RSA_PKCS1_PADDING);

    RSA_free(rsa);
    return plain;
}


#endif //PALANGCLI_RSA_H
