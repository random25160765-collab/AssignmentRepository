#include <stdio.h>
#include <stddef.h>

/* 指针与const限定符 */
int main()
{
    const int *a0 = NULL;
    int *const a1 = NULL;
    const int *const a2 = NULL;

    char c = 'a';
    const char *pa = &c; /* 会自动做转换 */

    const char d = 'a';
    const char *pb = &d; /* 不加const会报错 */

    /* 特别注意：字符串字面值分配在.rodata段！ */
    /* 如果要定义一个指针指向字符串字面值，这个指针应该是const char *型 */ 

    const char *p = "abcd\n";
    const char str0[5] = "abcd\n";
    char str1[5] = "abcd\n";

    printf(p);
    printf(str0);
    printf(str1);
    printf("abcd\n");

    /* 出现UB，输出5个abcd */

    return 0;
}