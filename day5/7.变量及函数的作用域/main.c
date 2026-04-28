#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	{
		int j = 10;//局部变量，仅在大括号（语句块，语句体）内有效
	}
	printf("j=%d\n", j);//出现错误，未定义标识符"j"；
	system("pause");
}