#include <stdio.h>
#include <stdlib.h>

//溢出，无符号用%u输出，有符号用%d输出
int main()
{
    //unsigned short i = 32767, j;
	//j = i + 2;
	unsigned int i = 0x7fffffff, j;
	j = i + 1;//printf%d时输出-2147483648，printf%u时输出2147483648
	//short i = 32767, j;
	//j = i + 1;//输出-32768
	printf("%d\n",j);
	system("pause");
}