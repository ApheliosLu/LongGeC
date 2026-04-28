#include <stdio.h>
#include <stdlib.h>

//浮点数_防止精度丢失
int main()
{
	//float f = -.1e-3;//即-1e-4
	double f = 1.23456789e10, d;
	d = f + 20;
	printf("%0.1f,%0.1f\n", f,d);
	f = 1.456;//近似值，浮点数仅存在精度，判断时要用减法
	if (f-1.456>=-1e-6 && f-1.456<=1e-6)//此时可判断f是否等于1.456，精度6~7位，精度从最左侧数字开始
	{
		printf("f is 1.456\n");
	} else {
		printf("f is not 1.456\n");
	}
	f = 4.5;//内存地址为0x004FFE0C，小端存储位00009040（实际为40900000）
	system("pause");
}