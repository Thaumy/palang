//
// Created by Thaumy on 2021/11/2.
//

#ifndef PALANGCLI_STR_H
#define PALANGCLI_STR_H

///字符串判等
int strEq(char *str, char *anotherStr) {
    if (strcmp(str, anotherStr) == 0)
        return 1;
    else
        return 0;
}

///字符串是否以另一个字符串开头
int strBeginWith(char *str, char *anotherStr) {
    int strLen = strlen(str);
    int anotherStrLen = strlen(anotherStr);

    if (anotherStrLen > strLen)
        return 0;
    else
        for (int i = 0; i < anotherStrLen; ++i) {
            if (str[i] != anotherStr[i])
                return 0;
        }

    return 1;
}

#endif //PALANGCLI_STR_H
