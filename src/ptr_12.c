#include <stdio.h>

/* 函数指针 */
void say_hello(const char *str)
{
	printf("Hello %s\n", str);
}

int main(void)
{
    /* 函数类型和数组类型类似，做右值使用时自动转换成函数指针类型，所以可以直接赋给f */
	void (*f)(const char *) = say_hello;
    /* 亦可写成 void (*f)(const char *) = &say_hello; */
	f("Guys");
    /* 亦可写成 (*f)("Guys") */
	return 0;
}