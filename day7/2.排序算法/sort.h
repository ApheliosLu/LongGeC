#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>//time头文件
#define N 10
//代码替换
#define SWAP(a,b) {int tmp;tmp=a,a=b;b=tmp;}

//函数声明
void print(int*);//打印函数，形参类型为“整型指针”
void arr_select(int*);//选择排序
void arr_insert(int*);//插入排序；使用场景：通讯录等原本有序的队列，新增加项时使用插入排序