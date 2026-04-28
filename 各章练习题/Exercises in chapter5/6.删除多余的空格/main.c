#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void main()
{
	char s[] = "   hello    world   how are you  ";
	int i, j = 0;
	for (i = 0; s[i] == ' '; i++);//s[i]不等于空格时停下，找到字符串的第一个字母
	for (; s[i] != '\0'; i++)
	{
		if (s[i] != ' ')
		{
			s[j++] = s[i];//将非空格的s[i]赋值给s[j++]
			continue;//提前结束s[i]!=' '的这轮循环
		}
		s[j] = ' ';//若s[i]等于空格即一个单词结束后，则赋值一个s[j]为单词后的一个空格
		j++;
		for (; s[i + 1] == ' '; i++);//找到字母的地方，之所以i+1，是因为上面还有i++
	}
	s[j] = '\0';//赋一个结束符
	printf("%s\n", s);
	system("pause");
}