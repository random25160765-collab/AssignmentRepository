#include <stdio.h>
#include <stddef.h>

/* 指针与const限定符 */
int main()
{
    const int *a0 = NULL; // 指向的内存是只读的
    int *const a1 = NULL; // 指针是只读的
    const int *const a2 = NULL; // 指针和指向的内存都是只读的

    char c = 'a';
    const char *pa = &c; /* 会自动做转换 */

    const char d = 'a';
    const char *pb = &d; /* 不加const会报错 */

    /* 特别注意：字符串字面值分配在.rodata段！ */
    /* 如果要定义一个指针指向字符串字面值，这个指针应该是const char *型 */ 

    const char *p = "abcd\n";
    const char str0[6] = "abcd\n";
    char str1[6] = "abcd\n";

    printf("%s",p);
    printf("%s",str0);
    printf("%s",str1);
    printf("abcd\n");

    /* 这样比较安全，也不会有警告 */

    return 0;
}