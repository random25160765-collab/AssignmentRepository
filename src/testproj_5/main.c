#include <stdio.h>
#include "complex.h"

int main()
{
    Complex z = {RECT, 3.0, 4.0};

    printf("%.2f\n", real(z));
    printf("%.2f\n", img(z));
    printf("%.2f\n", mag(z));
    printf("%.2f\n", angle(z));

    Complex z1 = {RECT, 3.0, 4.0};
    Complex z2 = {RECT, 8.0, 2.0};
    Complex z3 = {POLAR, 8.0, 45.0};
    Complex z4 = {POLAR, 4.5, 66.0};

    Complex sum1 = zadd(z1, z2);
    Complex sum2 = zadd(z1, z3);
    Complex sum3 = zadd(z3, z4);

    printf("%d, %.2f, %.2f\n", sum1.t, sum1.a, sum1.b);
    printf("%d, %.2f, %.2f\n", sum2.t, sum2.a, sum2.b);
    printf("%d, %.2f, %.2f\n", sum3.t, sum3.a, sum3.b);

    return 0;
}
