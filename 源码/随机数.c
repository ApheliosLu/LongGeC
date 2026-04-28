#include <stdio.h>
//1.导入两个头文件
#include <stdlib.h>//产生随机数，使用函数srand和rand
#include <time.h>//获取当前系统时间，使用函数time

int main01(void)
{
	int i;
	//2.创建随机数种子	time获取当前系统时间，将当前时间作为随机数种子
	srand((unsigned int)time(NULL));	//将time函数的返回值作为srand的参数，即此时srand的随机数种子为时间;	并将其强制类型转换为unsigned int;	NULL为time函数的参数

	//3.生成随机数	对rand取模会得到一个范围的随机数
	for(i=0;i<100;i++)
	printf("%d\n",rand()%100);	//0~99之内的随机数；	即将从rand获取的随机数取模1000;	并通过printf函数打印出来

	system("pause");
	return 0;
}

//小游戏：猜数字，随机一个1~100之间的数，通过键盘输入数据，根据数据输入进行提示
int main(void)
{
	int value;//用户输入的数值
	int num;//随机数
	srand((unsigned int)time(NULL));
	
	num=rand()%100+1;//0~99之间的数加以，变成1~100之间的数
	while(1)
	{
		scanf("%d",&value);
		if(num>value)
		{
			printf("您输入的数太小了\n");
		}
		else if(num<value)
		{
			printf("您输入的数太大了\n");
		}
		else
		{
			printf("恭喜您，猜对了\n");
			break;	//while出口
		}
	}
	system("pause");
	return 0;
}
