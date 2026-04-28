#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

union data {//共用体（联合体）的定义；共用体类型变量主要用于可变参数的定义使用
	int i;
	char ch;
	float f;
};

enum weekday { sun, mon, tue, wed=6, thu, fri, sat };//枚举类型变量的定义;sun到sat相当于默认从0到6的（编号）符号，若使用define则需要define7次
//使用场景：一些固定的常量，如周一到周日、彩虹七色等
//可在此处定义sun=5，则后面的变量以此类推,变成5 6 7 8 9 10 11；给中间常量赋值亦可，如wed=6，则上述七个常量编程0 1 2 6 7 8 9

void use_union()//使用共用体
{
	union data d;//共用体变量的定义；此时sizeof(d)=4，即一个float的大小，而非三个成员变量大小的加和
	d.i = 10;//三个成员的起始地址和共用体变量d的起始地址一致
	d.ch = 'A';
	d.f = 98.5;
}



int main()
{
	//sun = 20;//报错，sun不是可以修改的左值
	enum weekday workday;//定义一个weekday类型的名为workday的枚举变量
	workday = wed;//给枚举变量赋值并打印
	printf("%3d%3d%3d%3d%3d%3d%3d\n", sun, mon, tue, wed, thu, fri, sat);//直接对“符号”进行打印；输出0到6
	printf("workday=%d\n", workday);//输出workday=6
	system("pause");
	return 0;
}
