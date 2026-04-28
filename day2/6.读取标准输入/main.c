//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//可在这一行即文件开头（头文件）部分添加#define_CRT_SECURE_NO_WARNINGS来解除使用scanf而非scanf_s时的警告
//缓存区里所有数据都是字符，scanf根据你的要求进行匹配
//scanf %d %f（这两者只能匹配0~9的数字和小数点）发现里面有\n空格时会删除（即忽略）然后再阻塞，%c（一切都是字符包括\n和空格）则不会（忽略/删除而引起阻塞）
int main()
{
	int i=10,j;
	char c;
	scanf_s("%d", &i);//将读取的整型数据填到i的地址空间内
	printf("i=%d\n", i);
	scanf_s("%d",&j);
	printf("j=%d\n",j);
	rewind(stdin);   //rewind清空标准输入缓冲区
	scanf_s("%c", &c,100);//第二个scanf不会被阻塞，是因为第二个scanf函数读取了缓冲区中的'\n'即回车，即scanf("%c",&c)实现了读取，打印其实输出了换行;第三个参数100代表最大获取多少个数据
	printf("c=%c\n", c);//打印输出了换行
	system("pause");
	return 0;
}