#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char str[100] = { 0 };//str用来存储输入的字符串
	char* p;//！存储申请多大空间的起始地址
	int count = 0;//记录空格的个数
	int i, j = 0;
	gets(str);
	for (i = 0; i < strlen(str); i++)//统计空格个数的循环
	{
		if (' ' == str[i])
		{
			count++;
		}
	}
	i = strlen(str) + 3 * count + 1;//这里+1的目的是为了存储结束符'\0'
	p = (char*)malloc(i);//！申请内存
	memset(p, 0, i);//？初始化为零，目的是什么？
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] != ' ')//不是空格，直接赋给p[j]
		{
			p[j] = str[i];
			j++;
		}
		else {//如果是空格，就将%020附到后面
			strcat(p + j, "%020");
			j = j + 4;
		}
	}
	p[j] = '\0';//这里也可以写为p[j]=0
	puts(p);
	free(p);
	p = NULL;
	system("pause");
	return 0;
}