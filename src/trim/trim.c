// trim.c
#include "trim.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* ltrim(char *str) {
    if (str == NULL) return NULL;
    
    // 使用strspn跳过所有空白字符
    size_t skip = strspn(str, " \t\n\r\f\v");
    
    if (skip > 0) {
        // 移动字符串到开头
        char *src = str + skip;
        char *dst = str;
        while (*src) {
            *dst++ = *src++;
        }
        *dst = '\0';
    }
    
    return str;
}

char* rtrim(char *str) {
    if (str == NULL) return NULL;
    
    char *end = str + strlen(str) - 1;
    while (end >= str && isspace((unsigned char)*end)) {
        end--;
    }
    *(end + 1) = '\0';
    
    return str;
}

char* trim(char *str) {
    rtrim(str);
    return ltrim(str);
}

// 返回去除空格后的新字符串（需要free）
char* trim_dup(const char *str) {
    if (str == NULL) return NULL;
    
    // 跳过开头空格
    size_t start = strspn(str, " \t\n\r\f\v");
    
    // 如果全是空格
    if (str[start] == '\0') {
        char *result = malloc(1);
        if (result) *result = '\0';
        return result;
    }
    
    // 找到结尾（最后一个非空格字符）
    size_t end = strlen(str) - 1;
    while (end > start && isspace((unsigned char)str[end])) {
        end--;
    }
    
    // 计算新字符串长度并分配内存
    size_t len = end - start + 1;
    char *result = malloc(len + 1);
    if (result == NULL) return NULL;
    
    // 复制字符串
    strncpy(result, str + start, len);
    result[len] = '\0';
    
    return result;
}