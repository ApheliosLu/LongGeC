#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


//.exe给main函数传参，
int main(int argc, char* argv[])
{
	int i;
	FILE* fp;
	int ret;
	char buf[1024] = { 0 };
	printf("argc=%d\n", argc);//argc=1;设置命令参数text.txt后，argc=2
	for (i = 0; i < argc; i++)
	{
		puts(argv[i]);//显示C:\BOOK\day10\Debug\2.main函数的传参.exe;设置命令参数text.txt后,打印第二行text.txt
	}
	fp = fopen(argv[1], "r+");
	if (NULL == fp)
	{
		perror("fopen");
		goto error;
	}
	ret=fread(buf, sizeof(buf), 1, fp);
	printf("ret=%d\n", ret);
	printf("%s\n", buf);
error:
	system("pause");
}