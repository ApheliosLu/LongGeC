#include<stdio.h>
#include<stdlib.h>
//1.如何判断两个浮点数是否相等？
int main()
{
	float f = 234.56;
	//if(f==234.56)//浮点数中存储的是对应数的近似值，只能保证精度为7位（float），若开启本行并注释下一行则输出不等于
	if (f - 234.56 > -0.0001 && f - 234.56 < 0.0001)
	{
		printf("f等于234.56\n");//输出f等于234.56
	}
	else {
		printf("f不等于234.56\n");
	}
	system("pause");
	return 0;
}