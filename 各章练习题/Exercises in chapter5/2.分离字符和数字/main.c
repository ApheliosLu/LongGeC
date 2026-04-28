#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* formate(char* s)//此指针函数实现字母和数字的分离；传入参数字符数组s的地址即*s,相当于一个字符指针
{
	char ch[100], num[100];//定义两个字符型数组
	int i = 0, j = 0, k = 0;
	while (s[i] != '\0')//用while循环实现(s[ps]不等于零是限制条件）
	{
		if (s[i] >= '0' && s[i] <= '9')//判断s[i]中的元素是字母还是数字
			num[k++] = s[i++];//若是数字，则把它赋给数组num
		else
			ch[j++] = s[i++];
	}
	ch[j] = '\0', num[k] = '\0';//数组转换为字符串
	return strcpy(s, strcat(num, ch));
}

void main()
{
	char s[100];//定义字符数组s
	gets(s);
	puts(formate(s));//输出指针函数的返回值
	system("pause");
}