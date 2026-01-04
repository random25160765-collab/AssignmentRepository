#include <stdio.h>

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int *pa = a;
    /* 或者也可以这么写：int *pa = &a[0] */

    for(int i = 0; i < 10; i++)
    {
        printf("%d\n", *pa);
        pa++;
    }

    return 0;
}

