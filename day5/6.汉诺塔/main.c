#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

/*定义hanoi函数，将n个盘从第one柱借助第two柱，移到第three柱*/
void hanoi(int n, char one, char two, char three)
{
	void move(char x, char y);//对move 函数的声明
	if (n == 1) move(one, three);
	else
	{
		hanoi(n - 1, one, three, two);//？函数运行的具体步骤；（n-1）=1时，程序怎么走；C-->B的过程是哪一句，哪个过程出现的
		move(one, three);
		hanoi(n - 1, two, one, three);
	}
}

void move(char x, char y)//定义move 函数
{
	printf("%c-->%c\n",x, y);
}

void main()
{
	void hanoi(int n, char one, char two, char three);//对 hanoi函数的声明
	int m;
	printf("input the number of diskes:");
	scanf_s("%d", &m);
	printf("The step to moveing %d diskes:\n",m);
	hanoi(m, 'A', 'B', 'C');//传入实参
	system("pause");
}