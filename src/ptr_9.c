#include <stdio.h>

int main()
{
    /* 指针->指针->内存（只读） */
    const char **a = NULL; // 指针指向的指针指向的内存是只读的
    /* 指针->指针（只读）->内存 */
    char *const *b = NULL; // 指针指向的指针是只读的
    /* 指针（只读）->指针->内存 */
    char **const c = NULL; // 指向指针的指针是只读的

    /* 验证 */
    char num = 12;
    const char num_const = 34;

    char *ptr_0 = &num;
    const char *ptr_0_const = &num_const;

    const char **ptr_1_const = &ptr_0_const;

    char *const *ptr_1 = &num;
    char **const ptr_2 = &num;

    *ptr_0 = 21; /* 不允许改写 */ 

    const char num_1 = 56;


}