#include"func.h"

//函数的定义，也叫函数的实现
int print_star(int i)//此处i为形参，要接受实参的值（值传递），实际含义是将10赋值给i即i=10
{
	printf("**************\n");
	return i + 3;
}

void print_message()
{
	int i;
	printf("How do you do\n");
	i=print_star(3);
	printf("%d\n", i);
}
