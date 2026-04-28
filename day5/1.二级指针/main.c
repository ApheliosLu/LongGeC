#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void change(int* pi, int** pj)//*pi=pi,**pj=&pj,赋值的情况;pj本身为一级指针int *pj,传入参数时传为int **pj二级指针，即传入变量的地址
{
	//pj = pi;//无法改变调用函数内变量的值
	*pj = pi;//可改变
}
void two_pointer_trans()//二级指针的传递使用场景
{
	int i = 10;
	int j = 5;
	int* pi = &i;
	int* pj = &j;
	printf("i=%d,j=%d,*pi=%d,*pj=%d\n", i, j, *pi, *pj);
	change(pi, &pj);//！！！将pj的地址传入被调函数，此时可改变调用函数中指针变量的值
	printf("i=%d,j=%d,*pi=%d,*pj=%d\n", i, j, *pi, *pj);

	//int* p = &i;//一级指针初始化
	//int** p2 = &p;//二级指针的初始化
	//printf("**p2=%d\n", **p2);//对p2进行两次取值
}

void print(char** p)//亦可写成char *p[]；传入二级指针，类型由形参决定
{
	int i;
	for (i = 0; i < 5; i++)
	{
		puts(p[i]);
	}
}
void print_twoarr(char(*p)[10])//可输出b，传入一级指针即b的地址的类型的指针
{
	int i;
	for (i = 0; i < 5; i++)
	{
		puts(p[i]);
	}
}
void two_pointer_add()//二级指针的偏移使用场景
{
	char b[5][10] = { "lele","lili","lilei","hanmeimei","zhousi" };//二维数组中一维数组的数组名，就是一个一级指针，因此可以赋给二级指针；属于数组指针类
	int i, j, tmp;
	int a[5] = { 3,7,9,2,4 };
	char* ptmp;//定义指针用于交换

	//char* p[5];//定义一个指针数组，属于一级指针类型，属于二级指针类
	char** p;//直接在主函数内定义二级指针的场景
	p = (char**)malloc(sizeof(char*) * 5);//由指针数控制分配的内存

	for (i = 0; i < 5; i++)//让指针数组中的每个指针都指向一个字符串
	{
		p[i] = b[i];//
	}
	print(p);//直接调用print函数打印输出，无排序
	//冒泡法排序（外层控制比较的数目，内层比较排序）
	for (i = 5; i > 1; i--)
	{
		for (j = 0; j < i - 1; j++)
		{
			if (strcmp(p[j], p[j + 1])> 0)//比较两个指针对应的字符串的大小
			{
				ptmp = p[j];//将两个数交换
				p[j] = p[j + 1];
				p[j + 1] = ptmp;
			}
		}
	}
	printf("------------\n");
	print(p); // 排序后输出
	printf("------------\n");
	//print(b);//报错，print传入的是二级指针类型，b是二维数组
	print_twoarr(b);//正确打印b，不改变原有顺序
}

void b()
{
	printf("I am func b\n");
}
void a(void (*p)())//传入函数指针参数
{
	p();
}
void function_pointer()
{
	void (*p)();//定义一个函数指针变量
	p = b;//函数指针的返回值及入参要与函数保持一致
	a(p);//a执行p,写成a(b);亦可
}

int main()
{
	//two_pointer_trans();//二级指针的传递使用场景
	//two_pointer_add();//二级指针的偏移使用场景
	function_pointer();//函数指针
	system("pause");
}