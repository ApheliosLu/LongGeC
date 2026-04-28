#include "func.h"

extern int i;//借用mian.c文件中的全局变量i


void print()
{

	printf("print_i=%d\n", i);
}