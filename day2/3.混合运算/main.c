#include <stdio.h>
#include <stdlib.h>

//强制转换
int main()
{
	short i = 10;
	long j = 5;
	float f;
	i = (short)j;//将long型赋值给short型时需要进行强制类型转换，不加short强转编译会警告
	f = (float)j/ 2;//要将一个整型表达式赋值给浮点数，需要进行强制类型转换；或将2改成2.0运行也可
	printf("%f\n", f);
	//printf("i=%d,f=%f,g=%f,m=%d\n",i,f,g,m);
	system("pause");
}