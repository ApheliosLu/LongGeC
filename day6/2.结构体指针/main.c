#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student {//定义结构体类型
	int num;
	char name[20];
	char sex;
}stu, * pstu;//typedef的使用
//pstu等价于struct student*,属于指针类型

//typedef和define
//
//typedef int INTEGER;   //INTEGER代替int
//#define INTEGER int   //INTEGER代替int
//#define N 5   //N代替5


//用结构体指针访问结构体里的成员
int main()
{
	stu s = { 1001,"lele",'M' };//定义结构体变量
	stu sarr[3] = { 1005,"lele",'M',1002,"xiongda",'M',1003,"peiqi",'M' };//定义结构体数组
	//stu* p;//定义结构体指针
	pstu p, p1;//等价于上行；p,p1均为结构体指针
	int num;
	p = &s;//初始化指针，将s的地址赋值给结构体指针p
	printf("%d %s %c\n", (*p).num, (*p).name, (*p).sex);//方式一获取成员；成员选择（对象）运算符
	p = sarr;//将结构体数组直接赋值给结构体指针p，原因在于结构体内存储的值就是结构体的起始地址
	printf("-------------------\n");
	printf("%d %s %c\n", p->num, p->name, p->sex);//方式二获取成员；成员选择（指针）运算符，优先于上行;不偏移时，只会打印第一个成员1005
	num = p->num++;//后加加，分为两步：1.num=p-num；2.p->num++;
	printf("num=%d,p->num=%d\n", num, p->num);//打印1005 1006(注意是（p->num）的值++）
	num = p++->num;//依旧是后加加，分为两步：1.num=p-num;2.p++
	printf("num=%d,p->num=%d\n", num, p->num);//!!!打印1006 1002（注意是p++);即结构体指针的偏移
	system("pause");
}