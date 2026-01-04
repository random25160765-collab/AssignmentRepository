#include <stdio.h>

/* 指针遍历数组 */
/*
如果这个参数指向一个元素，通常写成指针的形式;
如果这个参数指向一串元素中的首元素，则经常写成数组的形式。
*/
void func(int pa[])
{
    for(int i = 0; i < 10; i++)
    {
        printf("%d\n", *pa);
        pa++;
    }
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    func(a);
    return 0;
}

