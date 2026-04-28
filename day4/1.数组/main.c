#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void use_strn()//使用strn系列接口
{
	char c[100] = "how";
	char d[100];
	//while (gets(d) != NULL)
	int i;
	//while(scanf("%s%d",d,&i)!=EOF)
	//{
	//	memset(c, 0, sizeof(c));//初始化，将数组c中的元素初始化为0；一个一个字节赋值
	//	strncpy(c, d, i);
	//	puts(c);//接口未赋结束符
	//}
	//printf("strncmp=%d\n", strncmp("hello", "how", 1));//strncmp
	memset(c + 4, 1, sizeof(c) - 4);
	strncat(c, "hello world", 5);
	puts(c);
}

use_mem()//使用mem系列
{
	int a[5] = { 1,2,3,4,5 };       //代码从上往下写，【编程从下往上编】；上面低地址，下面高地址；高字节放在高地址，低字节放在低地址；小端模式
	//memset(a, -1, sizeof(a));     
	int b[5] = { 1,2,4,7,8 };
	printf("a是否等于b %d\n", memcmp(a, b, sizeof(a)));
	memcpy(a + 2, b + 2, 12);//将数组b从第三个数开始的三个数（即十二个字节）复制到a的第三个数开始的三个数
}
int main()
{
	//use_strn();//使用strn系列接口
	use_mem();//使用mem系列
	system("pause");
}