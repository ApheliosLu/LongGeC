#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	char str_num1[50], str_num2[50], * res;//定义两个容量为50的字符数组，默认数组所存储的十进制数的位数不超过50;*res系为申请空间所定义的字符指针
	int n, len1, len2, i;
	memset(str_num1, 0, 50);//初始化
	printf("please input the 1st number:\n");
	scanf("%s", str_num1);
	memset(str_num2, 0, 50);
	printf("please input the 2nd number:\n");
	scanf("%s", str_num2);
	//统计两个字符串的长度，找出最长的，并加1，加1的目的是为了存储进位
	len1 = strlen(str_num1); len2 = strlen(str_num2);
	n = len1 >= len2 ? len1 : len2;//三目运算符
	n++;
	//!移动字符串，把进位的地方腾出来
	memmove(str_num1 + n - len1, str_num1, len1);
	memmove(str_num2 + n - len2, str_num2, len2);
	//提前把进位的地方赋值为0
	memset(str_num1, '0', n - len1);
	memset(str_num2, '0', n - len2);
	//为最终存储申请空间，并初始化
	res = (char*)malloc(n);
	memset(res, 0, n);
	for (i = n - 1; i > 0; i--)//从尾部开始相加
	{
		//res[i]与字符0比较的目的是查看是否有进位，有和没有操作不同
		res[i] = res[i] - (res[i] > '0' ? '0' : 0) + str_num1[i] + str_num2[i] - '0';//?
		if (res[i] - '0' > 9)
		{
			res[i - 1] = '1';
			res[i] -= 10;//进位
		}
	}
	res[n] = '\0';
	if (res[0] > '0')//若最高位有值，则打印，无值不打印
	{
		printf("%s\n", res);
	}else{
		printf("%s\n", res + 1);
	}
	system("pause");
	return;
}