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

///拼接
char *strConcat(char *str1, char *str2) {
    int len1 = (int) strlen(str1);
    int len2 = (int) strlen(str2);

    char *result = malloc(sizeof(char) * (len1 + len2 + 1));

    memcpy(result, str1, len1);
    memcpy(result + len1, str2, len2);

    result[len1 + len2] = '\0';//终止符

    return result;
}

char *strConcat3(char *str1, char *str2, char *str3) {
    return strConcat(strConcat(str1, str2), str3);
}

#endif //PALANGCLI_STR_H
