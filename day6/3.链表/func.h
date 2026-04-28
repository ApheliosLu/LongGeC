#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student {
	int num;
	float score;
	struct student* pnext;//定义指针类型*pnext,指向struct student成员的地址，作为车厢内的第二位乘客
}stu, * pstu;//*pstu等价于struct student *p，作为结构体的指针

//打印函数
void list_print(pstu phead);

//头插法
void list_head_insert(pstu* pphead, pstu* pptail,int val);//pstu为一级指针，pstu*为二级指针，传入子函数内发生改变；val为插入的值
                                                          //pstu*pphead等同于stu**pphead，stu为结构体
//尾插法
void list_tail_insert(pstu* pphead, pstu* pptail, int val);

//有序插入法
void list_sort_insert(pstu* pphead, pstu* pptail, int val);

//删除
void list_delete(pstu* pphead, pstu* pptail, int del_val);//传入要删除的值“del_val”，形参和实参的名称可以不一致

//修改
void list_modify(pstu, int, float);//(函数的声明）只传入形参的变量类型