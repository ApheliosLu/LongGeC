#include <stdio.h>
#include <stdlib.h>

//浮点数常量默认按8字节运算
int main()
{
	float f = 12345678900.0 + 1;
	double d = 12345678900.0 + 1;//必须以这种形式来赋值d
	printf("%f\n", f);//打印只有7位精度，原因是单精度浮点数f只有4字节的存储空间，
	printf("%f\n", 12345678900.0+1);//必须加.0，此时才能输出浮点型而非int型,按8字节即double型进行运算。
	printf("%f\n", d);
	system("pause");
	return 0;
}