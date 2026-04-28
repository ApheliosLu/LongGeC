#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int ElemType;//用ElemType代替int类型
typedef struct tag {//定义一个结构体类型tag，作为栈里的某一个节点
	ElemType m_val;//结构体内的ElemType（int）型变量m_val
	struct tag* next;//结构体内的指向下一个节点的指针*next
}Node,*pNode;//结构体缩写Node以及指针*pNode

typedef struct{//定义一个结构体类型Stack，作为栈；栈内存放栈顶指针phead(系结构体指针类型）和大小size
	pNode phead;
	int size;
}Stack,*pStack;//栈指针*pStack

//函数声明
void init_stack(pStack s);//栈的初始化，主要讲栈内的phead和size置为0；传入指针类型pStack,stack（s）为形参名，Stack为定义的栈的类型名
void pop(pStack s);//弹栈/出栈/退栈，分为是否拿到弹出来的值
void push(pStack s, ElemType val);//入栈/压栈；形参类型为ElemType（int）
ElemType top(pStack s);//返回栈顶元素
int empty(pStack s);//判断栈是否为空
int stack_size(pStack s);//返回栈中数据的个数