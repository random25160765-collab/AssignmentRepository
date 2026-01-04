/* 注意要引用头文件，要不然NULL没有定义！ */
#include <stddef.h>

int main()
{
    int i = 0;
    int j = 0;
    char c = 66;

    /* 定义指针变量 */
    int *pi = &i; 
    char *pc = &c;

    int *ptri = pi;

    pi = &j;
    *pi = *pi + 10;
    // (%rbp) += 10
    //这里的*就相当于汇编里的间接寻址，

    /*
    警惕段错误！
    pi = (int *)pc;
    */

    /* 防止野指针 */
    int *p = NULL;
    p = pi;

    return 0;
}