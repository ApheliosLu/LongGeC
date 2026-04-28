#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int f(int n)//n的阶乘的递归函数
{
	if (1 == n)//2.找结束条件
	{
		return 1;
	}
	return n * f(n - 1);//1.找公式，n!=f(n)=n*f(n-1)

}

 
int step(int n)//走楼梯,“斐波那契数列”
{
	if (1 == n)//2.找结束条件，相当于最基本的“动作”
	{
		return 1;
	}
	if (2 == n)
	{
		return 2;
	}
	return step(n - 1) + step(n - 2);//1.找公式，f(n)=f(n-1)+f(n-2)，为一次能走一个台阶或者两个的情况；
}                                    //若是一次能走三个台阶则，f(n)=f(n-1)+f(n-2)+f(n-3),以此类推

int main()
{
	//int n;
	//while (scanf("%d", &n) != EOF)   //多次测试使用
	//{
	//	printf("n!=%d\n", f(n));//f(n)为求n的阶乘的递归函数
	//}

	int n;
	int ret;
	scanf_s("%d", &n);//请输入数字的大小
	ret = f(n);
	printf("%d\n", ret);
	scanf_s("%d", &n);//请输入台阶数
	ret = step(n);
	printf("%d\n", ret);
	system("pause");
	return 0;
}