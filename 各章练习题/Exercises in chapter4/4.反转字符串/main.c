#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//反转字符串函数
void reverse(char* start, char* end)
{
	char tmp;
	while (start < end)
	{
		tmp = *start;
		*start = *end;//开头和结尾的地址互换
		*end = tmp;
		start++;
		end--;
	}
}

int main()
{
	char c[500];//存放字符串
	char* pstep, * ptmp;
	while (gets(c) != NULL)
	{
		reverse(c, c + strlen(c) - 1);
		//puts(c);
		pstep = c;
		while (*pstep)//循环
		{
			while (*pstep = ' ')//找到一个单词的开头;?引发了异常: 写入访问权限冲突。
			{
				pstep++;
			}
			ptmp = pstep;//找到单词的开头，并用ptmp记录
			while (*pstep != ' ' && *pstep)//找到对应单词的尾部
			{
				pstep++;
			}
			reverse(ptmp, pstep - 1);//将每一个单词对应反转
		}
		puts(c);
	}
	system("pause");
}