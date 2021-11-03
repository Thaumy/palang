//
// Created by Thaumy on 2021/11/2.
//

#ifndef PALANGCLI_MEM_H
#define PALANGCLI_MEM_H

///为内存区域填充0
void fill0(char *str, int size) {
    memset(str, 0, size);
}

///新建字符串
///该函数会自动填充0以保证安全
///终止符不计入length，但会为其预留空间并写入终止符（即填充0）
char *newStr(int length) {
    char *str = malloc(sizeof(char) * (length + 1));
    fill0(str, length + 1);

    return str;
}

#endif //PALANGCLI_MEM_H
