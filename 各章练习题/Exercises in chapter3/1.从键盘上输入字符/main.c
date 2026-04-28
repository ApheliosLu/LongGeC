//(1）分别统计其中字母、数字、其他字符的个数．
//（2）将统计的字母、数宇、其他字符的个数以柱状图的形式打印
//读取输入、排序、打印输出

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[3] = { 0 }; //定义一个数组，存储三个类型的变量的数目
	char* p[3] = { "alp","num","oth" }; //定义一个字符指针数组，记录三个类型的变量的地址
	char c;
	int tmp;
	char* ptmp;
	int i, j;
	while (scanf_s("%c", &c) != EOF) //读取输入的每一个字符
	{
		if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')//统计alp
		{
			a[0]++;
		}
		else if (c >= '0' && c <= '9')//统计num
		{
			a[1]++;
		}
		else {
			if (c == '\n')//不统计\n
			{
				break;
			}
			a[2]++;//统计oth
		}
		//上述判断可写作
		//else if(c!='\n')
		/*{
			a[2]++;
		}*/
	}
	for (i = 3; i > 1; i--) //冒泡法排序，同步交换；最后一个i=2>1时，j<i-1=1，j=0，此时可比较
	{
		for (j = 0; j < i - 1; j++)
		{
			if (a[j] < a[j + 1]) //从大到小的排序，小于时交换
			{
				tmp = a[j];
				a[j] = a[j + 1];//将a[j+1]赋给a[j]
				a[j + 1] = tmp;//交换整型数组

				ptmp = p[j];//交换字符指针数组中的指针
				p[j] = p[j + 1];
				p[j + 1] = ptmp;
			}
		}
	}
	printf("a[0]=%d,a[1]=%d,a[2]=%d\n", a[0], a[1], a[2]);
	printf("p[0]=%s,p[1]=%s,p[2]=%s\n", p[0], p[1], p[2]);
	//“两层for循环”，外层控制几行，内层控制几列
	for (i = 0; i <= a[0]; i++) //开始打印；i<=a[0]控制几行
	{
		if (0 == i) //在第一列，第0行打印a[0]
		{
			printf("%3d   ", a[0]);
		}
		else { //在下面的第1、2、3、4、5行打印*
			printf("***** ");
		}
		if (a[0] - a[1] == i)//控制第二列，在i=a[0]-a[1]的时候开始打印
		{
			printf("%3d   ", a[1]);
		}
		else if (i > a[0] - a[1]) {
			printf("***** ");
		}
		if (a[0] - a[2] == i) //在第a[0]-a[2]行打印a[2]
		{
			printf("%3d   ", a[2]);
		}
		else if (i > a[0] - a[2]) {
			printf("***** ");
		}
		printf("\n");
	}
	printf("%4s  %4s  %4s\n", p[0], p[1], p[2]);
	system("pause");
}
