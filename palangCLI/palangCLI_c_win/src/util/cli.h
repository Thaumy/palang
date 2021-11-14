//
// Created by Thaumy on 2021/11/2.
//

#ifndef PALANGCLI_CLI_H
#define PALANGCLI_CLI_H

void write_(char *msg) {
    printf("%s", msg);
}

void writeLine(char *msg) {
    puts(msg);
}

char *readLine() {
    fflush(stdin);
    int bufSize = 1024;
    char *input = newStr(bufSize);
    gets(input);
    return input;
}

///持续拼接输入行直至遇到某一行：该行中只有标记字符串
///特定标记mark不会被拼接到最终内容中
char *concatInputUntil(char *mark) {
    int bufLength = 0;
    //用于存放最终拼接结果的缓冲区
    char *buf= newStr(bufLength);

    char *line = readLine();
    while (!strEq(line, mark)) {
        int lineLength = strlen(line);

        buf = realloc(buf, sizeof(char) * (bufLength + lineLength + 1));//+1考虑了换行符
        strcpy(buf + bufLength, line);//strcpy会复制终止符
        buf[bufLength + lineLength] = '\n';
        bufLength += lineLength + 1;//+1考虑了换行符

        line = readLine();
    }

    return buf;
}

#endif //PALANGCLI_CLI_H
