#include"func.h"

//增量编译提高编译效率
int main()
{
	int ret;
	//函数的调用
	ret=print_star(10);//此处10为传递的实参，实参可以是常量、变量、表达式;只有变量才可以称为左值
	//此处ret用于接收print_star函数的返回值
	printf("%d\n", ret);
	print_message();
	system("pause");
}

