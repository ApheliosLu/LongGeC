#include<stdio.h>
#include<stdlib.h>

int if_alp(char a)//判断是否为字母，若是则返回1，否则返回0
{
	return(a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z');
}

void findstr(char str[], char word[][50])//定义查找字符串的子函数
{
	int i = 0, j = 0;
	//int* str;
	while (*str != '\n')
	{
		if (*str != ' ')
		{
			while (if_alp(*str))
			{
				word[i][j] = *str;//？将字符依次赋给二维字符数组
				str++;
				j++;
			}
			word[i][j] = '\n';//找到一个单词后，给对应单词赋结束符；？引发异常
			i++;//开始填充下一行
			j = 0;
		}//发现字母，计数+1，向后走到结尾
		while (*str == ' ')
		{
			str++;
		}//当stl的位置为空格时向后移动，直到不是空格时跳出该循环
	}
	//二维字符数组打印
	for (j = 0; j < i; j++)//?
	{
		puts(word[j]);
	}
}

int main()
{
	char a[100];
	char words[10][50] = { 0 };//用于存储每一个单词
	gets(a);
	findstr(a, words);
	system("pause");
	return 0;
}