#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	char s[] = "122233344555666";
	int i, k = 0;//i用来遍历，k用来存储元素下标
	for (i = 1; s[i] != '\0'; i++)//从i=1开始循环判定
	{
		if (s[k] != s[i])//起始值：s[0]!=s[1]；两者不相等就让k往后加一位并赋值，直至s[i]='\0'
		{
			k++;//k往后移动
			s[k] = s[i];//将不相等的新字符赋给k所在的位置
		}//若相等，则k不往后移动，i++
	}
	k++;
	s[k] = '\0';//结束，赋予结束符，字符数组s的排列也结束
	printf("%s\n", s);
	system("pause");
}