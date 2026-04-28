#include<stdio.h>
#include<stdlib.h>
//多层循环发生死循环，从最外层循环依次打断点，听到哪一层，就是哪一层有问题
int main()
{
	int year, mon, day, total, i;
	int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };//建立12个月份对应的天数的数组
	while (scanf_s("%d%d%d", &year, &mon, &day) != EOF)//使用while循环，判断输入的年月日
	{
		total = 0;//初始化所要求的第几天
		for (i = 0; i < mon - 1; i++)//mon-1
		{
			total = total + a[i];
		}
		total = total + day;
		if (mon > 2)
		{
			total = total + (year % 4 == 0 && year % 100|| year % 400 == 0);//闰年2月加一天
		}
		printf("%4d-%02d-%02d is %dth day\n", year, mon, day, total);//打印输出
	}
	system("pause");
}