#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE* fp;//定义一个文件类型的指针fp
	char c;
	fp = fopen("text.txt", "r");//以r的方式打开一个文件text.txt
	if (NULL == fp)//若返回为NULL，说明没有正确建立指针，报错
	{
		perror("fopen");//perror用于检测接口操作是否发生错误
		goto error;//若发生错误则前往error处并pause
	}
	/*c = fgetc(fp);//从指定的文件中读入一个字符
	putchar(c);//打印读取的字符c
	c = fgetc(fp);
	putchar(c);*/

	while ((c = fgetc(fp)) != EOF)//循环读取字符，注意加括号
	{
		putchar(c);
	}

error://!注意冒号结尾
	system("pause");
}