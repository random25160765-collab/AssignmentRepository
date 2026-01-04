#include <stdio.h>

/* 指向指针的指针，指针数组 */
int main(int argc, char *argv[])
{
    char *string[4] = {"Hel", "lo", " wor", "ld!\n"};
    char **pa = &string[0];

    for(int j = 0; j < 4; j++)
    {
        printf("%s", *pa);
        pa++;
    }

	return 0;
}