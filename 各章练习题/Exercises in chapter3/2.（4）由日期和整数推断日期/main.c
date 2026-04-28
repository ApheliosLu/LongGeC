#include<stdio.h>
#include<stdlib.h>

int isleap(int year);//定义闰年（在年中定义）

int main(void)
{
	int i, a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int year, month, day, data, sum = 0, days, n;
	char lese[30];//?lese

	printf("请输入日期:\n");
	scanf_s("%d%d%d", &year, &month, &day);
	printf("请输入经过的天数:\n");
	scanf_s("%d", &n);
	data = isleap(year);//?
	for (i = 1; i < month; i++)
	{
		sum = sum + a[i];
	}
	sum = sum + day;
	if (data && month > 2)
	{
		sum += 1;
	}//先计算出输入的日期距离年初的天数，存入sum
	days = sum + n;
	while (days < 0)//如果输入负值，先以年为单位往前推
	{
		year -= 1;
		days += 365;
		if (isleap(year))//减1年后的天数
		{
			days += 1;
		}
	}
	for (i = 1; days > a[i];)//不断对days做减法，直到days小于某个月的天数
	{
		days = days - a[i];
		if (2 == i && isleap(year))//闰年的情况
		{
			days -= 1;
		}
		i++;
		if (13 == i)//说明天数大于365，已经减了12个月，所以年份加1，月份回到1月
		{
			i = 1;
			year += 1;
		}
	}
	printf("经过%d天后日期是：%d-%d-%d\n", n, year, i, days);
	system("pause");
	return 0;
}

int isleap(int year)
{
	if (0 == year % 4 && 0 != year % 100 || 0 == year % 400)
		return 1;//真，为闰年
	else
		return 0;
}