#include <stdio.h>
#include <stdlib.h>

#define PI 3+2//define定义PI是常量，先定义可提高程序可读性以及修改效率rather than直接在下方代码3*2;define后不能加;
int main()
{
	int i = PI * 2;
	printf("i=%d\n", i);//i=3+2*2=7，预处理后define定义的内容是"常量"
	system("pause");
}