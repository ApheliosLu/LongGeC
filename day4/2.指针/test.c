#include <stdio.h>
#include <stdlib.h>

int test01(int a)
{
	a = 20;
	printf("test=%d\n", a);
	return a;
}

int test02(int* b)
{
	*b = 20;
	printf("test=%d\n", *b);
	return *b;
}
int main0202(void)
{
	int a = 10;

	/*
	test01(a);
	printf("main=%d\n", a);
	*/

	test02(&a);
	printf("main=%d\n", a);


	system("pause");
	return 0;
}