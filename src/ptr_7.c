#include <stdio.h>
#include <stdlib.h>

/* 指向指针的指针，指针数组 */
int main(int argc, char *argv[])
{
	int i;
	int N = atoi(argv[1]);
	int M = atoi(argv[2]);
	printf("%d, %d\n", N, M);
	for(i = 0; i < argc; i++)
		printf("argv[%d]=%s\n", i, argv[i]);
	return 0;
}