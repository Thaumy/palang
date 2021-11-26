#include <stdio.h>
#include "crypto/rsa.h"
#include "crypto/aes.h"
#include "socket/tcp.h"
#include "util/str.h"
#include "util/cli.h"

#pragma comment(lib, "ws2_32.lib")


int main() {
    int c = connect_("127.0.0.1", 16112);//client
    char *sessenKey = NULL;//会话密钥

    {//认证阶段
        send_(c, "hello", 5);

        if (strEq(recv_(c, 2), "hi"))
            writeLine("..........ready to auth");
        else {
            writeLine("......failed to connect");
            return 0;
        }

        size_t *keyPair = genRsa2048KeyPair();
        char *pubKey = keyPair[0];
        char *priKey = keyPair[1];

        send_(c, pubKey, 450);
        writeLine(".....client pubKey sent");

        sessenKey = rsa2048_decrypt(recv_(c, 344), priKey);
        writeLine("....sessionKey received");

        char *token = "a6abf30a015f47ecb3cc21fbce1400cc";
        encrypt_send(c, token, sessenKey);

        if (strEq(recv_(c, 5), "pass"))
            writeLine("..............auth pass");
        else {
            writeLine("..............auth failed");
            return 0;
        }
    }
    //puts(sessenKey);
    {//palang执行阶段
        write_("palang> ");

        char *cmd = readLine();

        while (!strEq(cmd, "bye")) {
            if (strBeginWith(cmd, "set")) {
                writeLine("to(input 'q' to finish):");

                //取得新值编码到base64后组装到最终命令
                char *value = concatInputUntil("q");
                char *value_in_base64 = base64_encode(value, strlen(value));
                char *final_cmd = strConcat3(cmd, " to ", value_in_base64);

                encrypt_send(c, final_cmd, sessenKey);
            } else {
                encrypt_send(c, cmd, sessenKey);
            }

            writeLine(decrypt_recv(c, sessenKey));
            write_("palang> ");
            cmd = readLine();
        }
    }

    dispose_(c);
    return 0;
}