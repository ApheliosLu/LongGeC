#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//strcpy
//int mystrcpy(char a[], char b[])
//{
//	int i = 0;
//	while (b[i])
//	{
//		a[i] = b[i];//逐个地复制字符
//		i++;
//	}
//	a[i] = 0;//？结束符？
//	return 0;
//}

//strcmp
int mystrcmp(char a[], char b[])
{
	int i = 0;
	while (!(a[i]==0&&b[i]==0))
	{
		if (a[i] < b[i])
		{
			return -1;
		}
		else if (a[i] > b[i])
		{
			return 1;
		}
		i++;
	}
	return 0;
}

//strcat
//int mystrcat(char a[], char b[])
//{
//	int i = 0, j = 0;
//	while (a[i])
//	{
//		i++;
//	}
//	while (b[j])
//	{
//		a[i] = b[j];
//		i++;
//		j++;
//	}
//	a[i] = b[j];
//}

//strlen
//int mystrlen(char b[])
//{
//	int i = 0;
//	while (b[i])//也可写成 while(b[i++])
//	{
//		i++;
//	}
//	return i;//注意：return i而非i-1
//}
int main()
{
	char a[100];
	char b[100] = "how";

	//strcpy部分
	//while (gets(b) != NULL)
	//{
	//	mystrcpy(a,b);
	//}
	//puts(a);//输出字符数组a

	//strcmp部分
	/*while (gets(a) != NULL)
	{*/
	gets(a);
	printf("a?b %d\n", mystrcmp(a, b));
//}

//strcat部分
//mystrcat(a,b);
//puts(a);//输出hellohow

//strlen部分
/*int len;
len=mystrlen(b);
printf("mystrlen len=%d\n", len);*/

	system("pause");
}