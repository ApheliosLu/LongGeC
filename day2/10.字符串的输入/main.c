#include <stdio.h>
#include <stdlib.h>
//#define _CRT_SECURE_NO_WARNINGS

int main()
{
	
	//1.字符串的初始化
	char buf1[50] = { 'h','e','l','l','o' };	//指定长度，后面自动补0
	char buf2[50] = { "hellp" };				//同上
	char buf3[] = "hellq";					//字符串初始化，常用！！！
	char* p = "hellr";						//字符指针

	printf("%s\n", buf1);
	printf("%s\n", buf2);
	printf("%s\n", buf3);
	printf("%s\n", p);
	
	
	
	//2.gets、puts
	char str1[100] = { 0 };
	puts("请输出字符串puts：\n");
	gets(str1);
	printf("%s\n", str1);
	

	//3.getchar、putchar
	int i = 0;
	while ((i=getchar()) != EOF) {		//使用getchar和putchar来循环读取输出多个字符
		putchar(i);
	}

	
	//4.scanf_s只能输入不含空格的一行字符串。如果输入的字符串中含有空格，则只会打印出第一个空格之前的子字符串。
	char str2[100];
	printf("请输入字符串scanf_s:\n");
	scanf_s("%[^\n]", str2,100);		
	//读到'\n'结束读取，此般即可使用scanf_s读取带有空格的字符串；
	//%[^\n]表示匹配除换行符以外的所有字符。它可以用于scanf函数中读取包含空格的字符串，直到遇到换行符为止
	//传入第三个参数100以表明最多读取多少位字符使得准确性、安全性提高。

	printf("%s\n", str2);
	
	

	system("pause");
	return 0;
}