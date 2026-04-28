#include <stdio.h>
#include <stdlib.h>


int main()
{
	int i = 123;
	printf("%d\n", i);
	printf("%o\n", i);
	printf("%x\n", i);
	system("pause");//最前面的7b即123的16进制数，同时是“小端”模式
}