#include <stdio.h>

/* 指向指针的指针，指针数组 */
int main(int argc, char *argv[])
{
	int i;
	for(i = 0; i < argc; i++)
		printf("argv[%d]=%s\n", i, argv[i]);
	return 0;
}