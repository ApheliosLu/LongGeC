#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int f(int m, int n);//函数先声明

void main()
{
	int m, n;
	printf("input m,n\n");
	while (scanf("%d%d", &m, &n) != EOF)//为便于测试使用了循环，按Ctrl+Z结束
	{
		printf("路径数量为：%d\n", f(m, n));
	}
	system("pause");
}

int f(int m, int n)//函数后定义（实现）
{
	if (0 == m)//当m为零时，只有一种方法到达终点
		return 1;
	if (0 == n)
		return 1;//同上
	//到达（m，n）节点只有两种情况，要么从（m-1，n）到达，要么从（m，n-1）到达
	return f(m - 1, n) + f(m, n - 1);
}