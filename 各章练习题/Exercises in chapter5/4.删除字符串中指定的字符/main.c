#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void del_chr(char* s, char ch)//导入子函数，传入str的地址和目标字符
{//两个指针，*s和*t;*s用来遍历字符串，*t用来指向要放置字符的位置
	char* t = s;//目标指针*t先指向原字符串头部
	while (*s != '\0')//遍历字符串s
	{
		if (*s != ch)//若当前字符不是要删除的，则保存在目标字符串中
			*t++ = *s;//每放置一个字符，t就移动一个位置
		s++;//检查下一个字符
	}
	*t = '\0';//把要放置字符的位置替换为'\0'
}

void main()
{
	char str[] = "**abcde**fghi***";
	del_chr(str, '*');//导入子函数，传入str的地址和目标字符
	printf("str=【%s】\n", str);
	system("pause");
}