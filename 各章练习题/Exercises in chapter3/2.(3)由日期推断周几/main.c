#include<stdio.h>
#include<stdlib.h>

int day_count(int y, int m, int d)//定义两日期分别在一年中所处的位置
{
	int i, days = 0;
	int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	for (i = 0; i < m; i++)
	{
		days += a[i];
	}
	days += d;
	if (m > 2 && (y % 4 == 0 && y % 100 != 0 || y % 400 == 0))
	{
		days++;
	}
	return days;
}

int main()
{
	//选择2018年2月18日作为基准日期，这一天是周日
	int y1, m1, d1, y2 = 2018, m2 = 2, d2 = 18, a, b, c = 0, i, days, flag;
	printf("请输入年月日：");
	while (rewind(stdin),scanf_s("%d%d%d", &y1, &m1, &d1) != EOF)//每次清空标准输入区
	{
		a = day_count(y1, m1, d1);//
		b = day_count(y2, m2, d2);
		if (y1 > y2)//通过异或方法对两个数进行交换：经过三次的异或就可以将两个数进行交换
		{
			y1 = y1 ^ y2;
			y2 = y1 ^ y2;
			y1 = y1 ^ y2;
		}
		for (i = y1; i < y2; i++)
		{
			if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)//闰年判定
				c++;//
		}
		days = abs(b - a) + abs(y1 - y2) * 365 + c;//计算输入日期与基准日期之间相差的天数
		if (y1 < y2 || a < b)//如果输入日期小于基准日期
			flag = (7 - days % 7) % 7;
		else//如果输入日期大于基准日期
			flag = days % 7;

		switch (flag)
		{
		case 1:printf("是周一"); break;
		case 2:printf("是周二"); break;
		case 3:printf("是周三"); break;
		case 4:printf("是周四"); break;
		case 5:printf("是周五"); break;
		case 6:printf("是周六"); break;
		case 7:printf("是周日"); break;
		}
		printf("\n请输入年月日：");
	}
	system("pause");
}