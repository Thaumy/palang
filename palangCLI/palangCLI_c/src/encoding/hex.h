//
// Created by Thaumy on 2021/11/1.
//

#ifndef PALANGCLI_HEX_H
#define PALANGCLI_HEX_H

#include <stdlib.h>
#include <string.h>

///hex编码
///显示指定strLength参数以防止字符串中间出现空字节（00000000）的情况
char *hex_encode(const char *str, long strLength) {
    //转换到16进制字符串后，占用内存应为原字符串的2倍+1（终止符计入）
    char *dst = newStr(strLength * 2 + 1);

    const char hexTable[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                             '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    for (int i = strLength; i > -1; --i) {
        *(dst + 2 * i + 1) = hexTable[(*(str + i)) & 0x0f];
        *(dst + 2 * i) = hexTable[(*(str + i)) >> 4];
    }

    dst[strLength * 2] = '\0';//终止符
    return dst;//有效长度为 strLength * 2（终止符不计入）
}

///hex解码
char *hex_decode(const char *hex) {
    int hexLength = strlen(hex);//u64

    //为保证hex不变，使用hex副本
    char *hex_cpy = malloc(sizeof(char) * (hexLength + 1));
    strcpy(hex_cpy, hex);//strcpy会复制终止符

    //转换到字符串后，占用内存应为原字符串的一半+1（终止符计入）
    char *dst = newStr(hexLength / 2 + 1);

    for (int i = 0; i < hexLength / 2; ++i) {
        *(dst + i) = ((*hex_cpy > '9' ? *(hex_cpy++) + 9 : *(hex_cpy++)) << 4)
                     | ((*hex_cpy > '9' ? *(hex_cpy++) + 9 : *(hex_cpy++)) & 0x0F);
    }

    dst[hexLength / 2] = '\0';//终止符

    return dst;//有效长度为 hexLength / 2（终止符不计入）
}

#endif //PALANGCLI_HEX_H
