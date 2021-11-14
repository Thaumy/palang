//
// Created by Thaumy on 2021/11/1.
//

#ifndef PALANGCLI_TCP_H
#define PALANGCLI_TCP_H

#include <stdlib.h>
#include <windows.h>
#include <winsock2.h>

///新建连接
SOCKET connect_(char *ip, unsigned short port) {
    WORD sockVersion = MAKEWORD(2, 2);
    WSADATA data;
    WSAStartup(sockVersion, &data);

    SOCKET client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    SOCKADDR_IN addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.S_un.S_addr = inet_addr(ip);

    connect(client, &addr, sizeof(addr));

    return client;
}

///销毁连接
void dispose_(SOCKET client) {
    closesocket(client);
    WSACleanup();
}

///发送信息
///显式指定信息长度以去除多余信息
void send_(SOCKET client, char *msg, int msgLength) {
    send(client, msg, msgLength, 0);
}

///接收信息
char *recv_(SOCKET client, int msgLength) {
    //动态接收不太适用，因为往往需要指定长度以去除多余内容
    /*int bufSize = 256;//缓冲区大小
    char *msg = malloc(sizeof(char) * bufSize);
    fill0(msg, bufSize);
    int count = 0;
    int nowSize = bufSize;
    do {
        count = recv(client, msg, 256, 0);

        {//扩容
            nowSize += bufSize;
            msg = realloc(msg, sizeof(char) * nowSize);
            //为新分配区域填充0
            fill0(msg + nowSize - bufSize, nowSize);
        }
    } while (count == bufSize);
    return msg;*/

    char *clippedMsg = newStr(msgLength);

    recv(client, clippedMsg, msgLength, 0);

    return clippedMsg;
}

///加密并发送信息
void encrypt_send(SOCKET client, char *msg, char *key) {
    char *encryptedMsg = aes256_encrpyt(msg, key);
    long encryptedMsgLength = strlen(encryptedMsg);
    send_(client, encryptedMsg, encryptedMsgLength);
}

char *decrypt_recv(SOCKET client, char *key) {
    int maxMsgLength = 20000;//最大接收长度
    char *encryptedMsg = recv_(client, maxMsgLength);
    //puts(encryptedMsg);//TODO
    char *msg = aes256_decrpyt(encryptedMsg, key);

    return msg;
}

#endif //PALANGCLI_TCP_H
