#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//输入日期返回该日期对应当年的第几天
int day_count(int y, int m, int d)
{
	int i, days = 0;
	int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	for (i = 0; i < m; i++)
	{
		days += a[i];
	}
	days += d;//?d在哪
	if (m > 2 && (y % 4 == 0 && y % 100 != 0 || y % 400 == 0))
	{
		days++;
	}
	return days;
}
//输入日期，返回当月1日是周几，1~7对应周一至周日
int weekdays(int y1, int m1)
{
	int d1 = 1, y2 = 2018, m2 = 2, d2 = 18, a, b, c = 0, i, days, flag;
	a = day_count(y1, m1, d1);
	b = day_count(y2, m2, d2);
	if (y1 > y2)//在基准日期之后
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
		flag = (7 - days % 7) % 7;//基准日期之前
	else
		flag = days % 7;//基准日期之后
	if (flag == 0)
	{
		flag = 7;//?代表基准日期是周几吗
	}
	return flag;
}
//输入year和month打印横向双月日历
void month_print(int y, int m)
{
	int h, i = 1, j = 1, k1, k2, flag = 0, flag1 = 1;//flag用来记录是否为闰年
	//i,j分别记录横向两月的日期，h为用于计数的变量
	//flag用于处理闰年，flag1用于让右侧1日前打印空格的语句只运行一次
	int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	printf(" %d  MON TUS WED THU FRI SAT SUN%3d  MON TUS WED THU FRI SAT SUN"
		       "\n",m,m+6);//代码跨行
	k1 = weekdays(y, m); k2 = weekdays(y, m + 6);//k1,k2用于记录月份的第一天是周几
	if (m == 2)
	{
		flag = (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);//处理闰年
	}
	printf("|  ");
	//打印左侧月份1日前面可能存在的空格
	for (h = k1 - 1; h > 0; h--)
	{
		printf("   ");
	}
	while (i <= a[m] || j <= a[m + 6])//打印主体开始
	{
		if (i != 1)
			printf("|  ");
		for (;; i++, k1++)
		{
			if (i <= a[m] + flag)
			{
				printf("%4d", i);
			}
			else
			{
				printf("    ");
			}
			if (k1 % 7 == 0)
			{
				k1++; i++;
				break;
			}
		}//左侧月份打印完一行
		printf("     ");//打印间隔
		if (flag1)
		{
			//打印右侧月份1日前可能存在的空格
			for (h = k2 - 1; h > 0; h--)
			{
				printf("   ");
			}
			flag1 = 0;
		}
		for (;; j++, k2++)
		{
			if (j <= a[m + 6])
			{
				printf("%4d", j);
			}
			else {
				printf("    ");
			}
			if (k2 % 7 == 0)
			{
				k2++; j++;
				printf(" |\n");
				break;
			}
		}//右侧月份打印完一行
	}
}

int main()
{
	int year, mon;
	printf("please input the year whose calendar you want to know:");
	while (rewind(stdin), scanf_s("%d", &year) != EOF)
	{
		mon = 1;
		printf("|-----------------The Calendar of Year%d-----------------------|\n", year);
		while (mon <= 6)
		{
			month_print(year, mon);
			mon++;
		}
		printf("|----------------------------------------------------------------|\n");
		printf("please input the year whose calendar you want to konw:");
	}
	system("pause");
}