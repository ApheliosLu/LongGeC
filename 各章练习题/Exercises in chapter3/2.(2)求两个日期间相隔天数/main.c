#include<stdio.h>
#include<stdlib.h>

int isleap(int year);

int main(void)
{
	int i, j, a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int year[2], month[2], day[2], data, sum[2] = { 0 }, days = 0;//定义两个年月日
	char lese[30];//
	for (i = 0; i < 2; i++)
	{
		printf("请输入第%i日期：\n", i + 1);
	yea://年份部分
		printf("\n年:");
		scanf_s("%d", &year[i]);
		gets(lese);
		if (year[i] > 9999 || year[i] < 0)//防止错误
		{
			printf("请输入正确的年份\n");
			goto yea;//goto循环
		}
	mon://月份部分
		printf("\n月:");
		scanf_s("%d", &month[i]);
		gets(lese);
		if (month[i] < 0 || month[i]>12)
		{
			printf("请输入正确的月份\n");
			goto mon;
		}
	da://日期部分
		printf("\n日：");
		scanf_s("%d", &day[i]);
		gets(lese);
		if (day[i] <=0 || day[i]>28)//输入值校检
		{
			if (0 == day[i])
			{
				printf("请输入正确的日期\n");
				goto da;
			}
			if (2 == month[i])//考虑是否是闰年的情况
			{
				data = isleap(year[i]);//
				if (data)
				{
					if (29 != data)
					{
						printf("请输入正确的日期\n");
						goto da;
					}
				}
				else {
					printf("请输入正确的日期\n");
					goto da;
				}
			}
			if (4 == month[i] || 6 == month[i] || 9 == month[i] || 11 == month[i])
			{
				if (day[i] > 30)
				{
					printf("请输入正确的日期\n");
					goto da;
				}
			}
			else if (day[i] > 31)
			{
				printf("请输入正确的日期\n");
				goto da;
			}
		}
	}
	for (i = 0; i < 2; i++)
	{
		data = isleap(year[i]);//data用于标记该年是否为闰年
		for (j = 1; j < month[i]; j++)
		{
			sum[i] = sum[i] + a[j];//加上每个月的天数
		}
		sum[i] = sum[i] + day[i];
		if (data && month[j] > 2)
		{
			sum[i] += 1;
		}
	}
	for (i = year[0]; i < year[1]; i++)
	{
		if (isleap(i))
		{
			days += 366;
		}
		else {
			days += 365;
		}
	}
	days = days + sum[1] - sum[0];
	printf("相差%d天\n", days);
	system("pause");
	return 0;
}

int isleap(int year)//定义isleap即闰年，在year中嵌套自定义
{
	if (0 == year % 4 && 0 != year % 100 || 0 == year % 400)
		return 1;//此时为真，是闰年leapyear
	else
		return 0;//此时为假
}