#include<stdio.h>
#include<stdlib.h>

//函数的声明，放入头文件，便于不同的.c文件使用
int print_star(int);//可写为int print_star(int i)/(int j)，重点在于传参的类型检查
void print_message();