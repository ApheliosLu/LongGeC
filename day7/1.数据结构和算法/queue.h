#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxSize 5
typedef int ElemType1;//用ElemType代替int，作为基础类型
typedef struct {//若不往结构体内放入指针，则无需在定义时取名
	ElemType1 data[MaxSize];//定义一个“基础类型”类型的、名为data的数组，存储MaxSize-1个元素（为了实现循环队列）
	int front, rear;//队列头、队列尾下标
}SqQueue;//名为SqQueue；定义一个队列SqQueue，系结构体类型数据，内部包含“基础类型”的数组data以及队列头尾下标

void InitQueue(SqQueue* q);
void EnQueue(SqQueue* q, ElemType1 val);
int DeQueue(SqQueue* q);