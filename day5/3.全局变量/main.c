#include "func.h"

int i = 10;//定义全局变量；若不初始化（即注释掉本行的同时，将func.c文件中的extern删去），则默认为零；全局变量不可定义在头文件中
//若上行定义为 static int i=10;，则func.c文件无法借用全局变量i；同时static修饰函数时，也对其他文件不可见

int main()
{
	int i=8;//若加入此行语句，由于有两个i，采用“就近原则”，下一句打印的i属于这一行的i；会报错误，未初始化；若定义i=8，则下一行打印8，而15行打印10
	printf("main i=%d\n", i);//打印10
	i = 5;
	print(i);//打印5
	system("pause");
}