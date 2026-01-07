#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *shrink_space(char *dest, const char *src, size_t n)
{
    // 检查字符串是否为空
    if (dest == NULL || src == NULL) {
        perror("Empty pointer");
        exit(1);
    }

    int max_index = strlen(src) - 1;
    int is_continued_space = 0;
    int i;

    // 处理第一个字符
    if (src[0] != ' ') strncpy(dest, src, sizeof(char));
    src++;  dest++;

    for (i = 1; i < max_index; i++) {
        if(src[i] == ' ' || src[i] == '\n' || src[i] == '\t' || src[i] == 'r') {
            strncpy(dest, " ", sizeof(char));
            is_continued_space = 1;
            src++;  dest++;
        } else {
            strncpy(dest, src, sizeof(char));
            is_continued_space = 0;
            src++;  dest++;
        }
    }

    // 处理最后一个字符
    if (dest[i-1] == ' ' && is_continued_space)

    return dest;
}