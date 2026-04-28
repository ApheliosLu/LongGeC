#include <stdio.h>
#include <stdlib.h>

//void swap(int a,int b)
//{
//	int temp=a;
//	a=b;
//	b=temp;
//}


void swap(int* a, int* b)
{
	int temp = *a;	//此处的（int*)a相当于是&a，即a的地址
	*a = *b;
	*b = temp;
}

int main0401(void)
{
	int a = 10;
	int b = 20;

	//值传递，形参不能改变实参的值
	//swap(a,b);

	//利用指针/地址传递参数，可以改变实参的值
	swap(&a, &b);

	printf("%d\n", a);
	printf("%d\n", b);
	system("pause");
	return 0;
}
