#include <stdio.h>

void increment(int *x)
{
	*x = *x + 1;
}

int main(void)
{
	int i = 1, j = 2;
	increment(&i); /* i now becomes 2 */
	increment(&j); /* j now becomes 3 */
    printf("%d, %d\n", i, j); /* 记得添加换行符，要不然会有奇怪的输出 */
	return 0;
}