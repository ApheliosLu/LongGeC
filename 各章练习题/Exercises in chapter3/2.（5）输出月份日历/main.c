#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int day_count(int y, int m, int d)
{
	int i, days = 0;
	int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	for (i = 0; i < m; i++)
	{
		days += a[i];//?
	}
	days += d;
	if (m > 2 && (y % 4 == 0 && y % 100 != 0 || y % 400 == 0))//闰年多加一天
	{
		days++;
	}
	return days;
}

int weekdays(int y1, int m1)
{
	int d1 = 1, y2 = 2018, m2 = 2, d2 = 18, a, b, c = 0, i, days, flag;//基准日期
	a = day_count(y1, m1, d1);
	b = day_count(y2, m2, d2);
	if (y1 > y2)//?为什么要异或两个年份
	{
		y1 = y1 ^ y2;
		y2 = y1 ^ y2;
		y1 = y1 ^ y2;
	}
	for (i = y1; i < y2; i++)
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
			c++;
	days = abs(b - a) + abs(y1 - y2) * 365 + c;
	if ((y1 < y2) || a < b)
		flag = (7 - days % 7) % 7;
	else
		flag = days % 7;
	return flag;
}

int main()
{
	int y, m, i, k, flag = 0;
	int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	printf("请输入年月：");
	while (rewind(stdin), scanf_s("%d%d", &y,& m) != EOF)
	{
		printf("MON TUS WED THU FRI SAT SUN\n");
		k = weekdays(y, m);//算出每个月的第一天是周几
		if (k == 0)
		{
			k = 7;//0代表周日，所以改为7
		}
		for (i = k - 1; i > 0; i--)
		{
			printf("    ");
		}
		if (m == 2)//如果是2月，又是闰年，flag为1
		{
			flag = (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
		}
		for (i = 1; i <= a[m] + flag; i++, k++)//?0x00007FF75F951CE9 处有未经处理的异常(在 2.（5）输出月份日历.exe 中): 0xC0000005: 读取位置 0x000000E60DEC2D98 时发生访问冲突。
		{
			printf("%-4d", i);
			if (k % 7 == 0)//每到周末就换行
			{
				printf("\n");
			}
		}
		printf("\n请输入年月：");
	}
	system("pause");
}