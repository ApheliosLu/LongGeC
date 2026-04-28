#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void use_if()
{
	int i;
	while (scanf_s("%d", &i) != EOF)
	{
		if (i > 10)//括号后面若带分号，代表此时if语句已结束，无论如何都会执行下列的printf语句
		{
			printf("i is bigger than 10\n");//分号在这里
		}
		else if (i < 0) {
			printf("i is smaller than 0\n");
		}
		else {
			printf("i is not bigger than 10\n");
		}
	}
}

void use_switch()
{
	int mon;
	while (scanf_s("%d", &mon) != EOF)
	{
		switch (mon)//switch语句的语法格式
		{
		case 2:printf("%dth is 28 days\n", mon); break;
		case 4:
		case 9:
		case 6:
		case 11:printf("%dth is 30 days\n", mon); break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:printf("%dth is 31 days\n", mon); break;
		default://default在所有case后的常量表达式的值都未匹配时，打印输出错误标志或者一些提醒
			printf("error mon\n");
		}
	}

}

void use_goto_while()//goto向上循环
{
	int i = 1, total = 0;
label://标签，注意命名规范
	total = total + i;
	i++;
	if (i <= 100)
	{
		goto label;//
	}
	printf("%d", total);
}

void use_goto_error()//goto向下跳转
{
	int i = 0;
	if (0 == i)//编码规范，数字等于字母
	{
		goto error;//goto只能前往同一个（子）函数内，不可跨函数
	}
	//磁盘有无空间
	//找不到节点
error:
	printf("system is error\n");
}

void use_while()
{
	int i = 1, total = 0;
	while (i <= 100)//while后不可加分号，会出现死循环
	{
		total += i;
		i++;//循环内要有使循环趋近于假的操作
	}//多层循环出现死循环时，由外向内判断（从外往内打断点）
	printf("%d\n", total);
}

void do_while()
{
	int i = 1, total = 0;
	do {
		total += i;
		i++;
	} while (i <= 100);//此处必须加分号，否则编译不通
	printf("%d\n", total);
}

void do_while_continue()//仅执行一次
{
	int i = 1;
	do {
		printf("%d\n", i);//仅打印一次
		i++;
		if (i < 15)
		{
			continue;
		}
	} while (0);//continue之后依旧进行了while的判断，while内表达式为假，因此代码只执行一次
}

void use_for()
{
	int i, total;
	for (i = 1, total = 0; i <= 100; i++)//括号后不能加分号，加分号不会死循环但结果错误;若此处加了分号则打印total=101
	{
		total += i;
	}
	printf("total=%d\n", total);
	system("pause");
	return 0;
}

void use_continue()
{
	int i, total;
	for (i = 1, total = 0; i <= 100; i++)
	{
		if (i % 2 == 0)//判断偶数
		{
			continue;//提前结束i为偶数的这轮循环，不进行total+=i而进行i++
		}
		total += i;
	}
	printf("total=%d\n", total);
	system("pause");
	return 0;
}

void use_break()
{
	int i, total;
	for (i = 1, total = 0; i <= 100; i++)
	{
		if (total > 2000)
		{
			break;
		}
		total += i;
	}
	printf("total=%d,i=%d\n", total, i);
	system("pause");
}

void print_rhombus()//打印菱形作业；E12_57：05左右
{
	int i, j;//第一步，打印五行(共九列）、每行九个*
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < abs(4 - i); j++)//abs即取绝对值公式；j<abs（4-i）也可用三目运算符实现即j<(4-i>0?4-i;i-4)
		{
			putchar(' ');//每一行的空格,js
		}
		for (j = 0; j < 9-2*abs(4-i); j++)//找规律，i与j有着数量上的对应关系，i0j5；i1j6；i2j7……;js即空格亦有对应关系
		{
			if (j % 2 == 1)//奇数列时打印空格，达到镂空的效果
			{
				putchar(' ');
			}
			else {
				putchar('*');
			}
			//下列代码实现打印中心全空的菱形
			//if (j == 0 || j == 8 - 2 * abs(4 - i))//只打印第一个和最后一个
			//{
			//	putchar('*');
			//}
			//else {
			//	putchar(' ');
			//}
		}
		putchar('\n');//每次打印九个菱形后换行，否则会打印在同一行
	}
}
int main()
{
	//use_if();
	//use_switch();
	//use_goto_while();//goto向上循环
	//use_goto_error();//goto向下跳转
	//use_while();
	//do_while();
	//do_while_continue();
	//use_for();
	//use_continue();
	//use_break();
	print_rhombus();//打印菱形作业
	system("pause");
}