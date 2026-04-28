#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 5

void print(int arr[], int arr_len)//传递数组参数；形参
{
	int i;
	for (i = 0; i < arr_len; i++)
	{
		printf("%3d", arr[i]);//打印数组的每一个元素
	}
	arr[4] = 20;//更改了arr[4]的值
	putchar('\n');
}
void arr_outofbounds()//一维数组的存储传递和访问越界
{
	int j = 10;
	int arr[N] = { 1,2,3,4,5 };
	//arr[5] = { 1,2,3,4,5 };不合法
	int i = 3;
	//arr[5] = 20;//访问越界
	//arr[6] = 30;
	//arr[7] = 40;
	print(arr, 5);//一维数组的传递：将数组传递给子函数，长度arr_len（5）需要自己传；子函数print,这里控制
	printf("arr[4]=%d\n", arr[4]);//arr[4]发生改变；实参
	printf("i=%d,j=%d\n", i, j);
}

void arr_stackoverflow()//数组定义过大导致Stack Overflow，另一种爆栈是递归
{
	int arr[260000] = { 0 };//爆栈
}

void two_arr_print(int arr[][4], int row)//传递到子函数处打印;不传行，必传列；	
{
	int i, j;
	for (i = 0; i < row; i++)//外层循环控制行，3行
	{
		for (j = 0; j < sizeof(arr[0]) / sizeof(int); j++)//算出列数sizeof(arr[0])/sizeof(int)=16/4=4
		{
			printf("%3d", arr[i][j]);//用下标控制
		}
		printf("\n");//打印每一行后换行
	}
}
void two_arr()//二维数组
{
	int i, j;
	int arr[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };//空间大小等于sizeof(arr)=3X4X4=48;arr[3][4]能访问的最大元素是arr[2][3]=12
	//int arr[3][4] = { {1,6},{5},{9} };//只赋值每一行的第一个元素
	two_arr_print(arr, 3);//控制三行，3控制了row，传递了3行；若改成4则变成四行，对应上方改成int arr[][3]
}

void scanf_while()//while循环读取一行字符
{//读入一行字符串，输出一行字符串
	char c;//用字符c来存储
	char arr[100] = { 0 };//初始化字符数组
	int i = 0;
	while (scanf("%c", &c) != EOF)//前加rewind（stdin）则只会输出第一个字符h，是因为putchar只能输出一个字符，后面的字符在缓冲区内被rewind了
		//scanf读取字符时用%c，读取字符串时用%s
	{
		//putchar(c);//putchar输出
		arr[i] = c;
		i++;
	}
	printf("%s\n", arr);
}

void string_print(char c[])
{
	int i = 0;
	while (c[i])//c[i]!='0'或者c[i]!=0是停止条件，也可以不写
	{
		putchar(c[i]);
		i++;
	}
	c[4] = 'A';
	printf("\n");
}
void char_arr_init()//字符数组的初始化
{
	//char c[10] = { 'h','e','l','l','o' };//初始化;若10改成5，则会打印输出乱码，是因为没有结束符'\0'的空间，会一直打印到出现结束符为止
	char c[6] = "hello";//一般使用这种初始化方式，6是因为字符后面要加一个字节的结束符'\0';C语言中只有字符数组，C++中才有string字符串类型
	//printf("%s\n",c);//用printf打印输出一串字符，%s的格式，后面必须是一个字符数组的数组名c
	string_print(c);
	printf("%s\n", c);
}

void string_scanf()//一次性读一行字符串，放在字符数组中
{//scanf不能一次读一行，一次能读一个字符串但会忽略空格
	char c[100];
	char d[100];
	while (scanf("%s%s", c, d) != EOF)//为了使scanf能够一次读取一行，而做的写法；学生信息管理系统时输入学号和成绩等
	{
		printf("%s----%s\n", c, d);
	}
}

void string_gets()//gets读取一行,不忽略空格
{
	char arr[100] = { 0 };//初始化
	while (gets(arr) != NULL)//!= NULL
	{
		//printf("%s\n", arr);
		puts(arr);//等同于上式printf\n，默认会在最后加入换行
	}
}

//自己实现strlen函数
size_t mystrlen(char c[])//size_t即strlen函数的返回值;写成unsigned int mystrlen(char c[])亦可
{
	int i;
	for (i = 0; c[i]; i++)
	{
	}
	return i;//返回字符串长度；"hello\0",从0计数，共“5个字符串”
}
void use_str()//str系列的使用
{
	char arr[100] = { 0 };//初始化
	char d[100];
	//while (gets(arr) != NULL)//!= NULL
	//{
	//	//printf("%s\n", arr);
	//	//puts(arr);//等同于上式printf\n，默认会在最后加入换行
	
	//	//printf("字符串的长度是%d\n", sizeof(arr));//每次都会输出100（初始化的长度）
	//	printf("字符串的长度是%d\n", mystrlen(arr));//输出正确的字符串长度

	//	strcpy(d, arr);//strcpy函数将arr的值复制到d中
	//	puts(d);
	//}
	while (scanf("%s%s", arr, d) != EOF)
	{
		printf("strcmp=%d\n", strcmp(arr, d));//strcmp比对用户名和密码是否是正确输入的

		strcat(arr, d);//strcat将字符串d拼接到字符串arr的后面
		puts(arr);
	}
}
int main()
{
	//arr_outofbounds();//一维数组的存储传递和访问越界
	//调试时F10（逐过程）和F11（逐语句）的区别：
	//在遇到函数调用语句时，F10将函数当作一条语句执行，F11进入函数内部执行
	//arr_stackoverflow();//栈空间溢出
	//two_arr();//二维数组的存储和传递
	//scanf_while();//while循环读取一行字符
	//char_arr_init();//字符数组的初始化
	//string_scanf();//一次性读一行字符串，放在字符数组中
	//string_gets();//gets读取一行
	use_str();//str系列的使用
	system("pause");
}