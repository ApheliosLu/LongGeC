#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n, i;
	char c[20];
	while (gets(c) != NULL)
	{
		n = 0;
		for (i = 0; i< strlen(c); i++)
		{
			if (i != 0&& c[i - 1] != ' ' && c[i] = ' ')//判断当前字符(i-1处）不是空格且下一个字符（i处）是空格;?为什么此处的i!=0编译错误
			{
				n++;//计数单词数
			}
		}
		if (i != 0 && c[i - 1] != ' ') n++;//如果最后不是空格，那么需要对单词书加1
		printf("the number of word is %d\n", n);
	}
	system("pause");
	return 0;
}