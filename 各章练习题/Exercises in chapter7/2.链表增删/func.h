#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student {//定一个一个结构体变量类型
	int num;//结构体内包含的变量
	float score;
	struct student* pNext;//定义结构体指针struct student*；*pNext为指向下一个结构体的指针
}stu, * pstu;//*pstu等同于struct student*

//尾插法
void list_tail_insert(pstu*, stu**, int);//pstu*等同于stu**，系二级指针类型；
                                        //pstu本身指向某一个节点的地址，用于间接改变某一个节点的值
                                        //pstu*为"指向节点地址"的地址，用于间接改变某一个节点的地址

//头插法
void list_head_insert(pstu*, pstu*, int);

//有序插入法
void list_sort_insert(pstu*, pstu*, int);

//删除
void list_delete(pstu*, pstu*, int);

//链表修改
void list_modify(pstu, int, float);

//链表打印
void list_print(pstu);
void list_print_score(pstu);