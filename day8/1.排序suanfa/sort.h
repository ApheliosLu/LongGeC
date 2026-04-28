#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>//time头文件
#define N 10//处N不可大于250000(栈空间）
#define M 100

//代码替换
#define SWAP(a,b) {int tmp;tmp=a,a=b;b=tmp;}

//函数声明
void print(int*);//打印函数，形参类型为“整型指针”
void arr_select(int*);//选择排序
void arr_insert(int*);//插入排序；使用场景：通讯录等原本有序的队列，新增加项时使用插入排序
void arr_shell(int*);//希尔排序
void arr_quick(int*, int, int);//快速排序
int partition(int*, int, int);
int compare(const void* pleft, const void* pright);
void arr_heap(int* arr);//堆排
void adjust_max_heap(int* arr, int adjust_pos, int len);
void arr_merge(int* arr, int low, int high);//归并排序
void merge(int* arr, int low, int mid, int high);
void arr_count(int* arr);//计数排序
void use_bitmap();
void use_hash();