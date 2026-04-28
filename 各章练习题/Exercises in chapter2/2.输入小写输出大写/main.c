#include<stdio.h>
#include<stdlib.h>
//2．从键盘上输入宇符，将小写字母转换成大写字母，按组合键Ctrl + Z结束程序。
int main(void)
{
	char c;
	while (scanf_s("%c", &c)!=EOF)//通过scanf_s函数每次读取一个字符
	{
		if (c >= 'a' && c <= 'z')//判断其范围是否在a与z之间
		{
			c = c - 32;//减32得到其对应的大写字母（的ASCII码）
		}
		printf("%c", c);
	}
	system("pause");
	return 0;
}