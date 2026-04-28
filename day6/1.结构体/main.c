#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//定义结构体时，把小字节定义在一起，放到结构体最后（下方字节数的原理）
struct student {//结构体类型的声明（定义）
	int num;
	char name[20];
	char sex;
	int age;
	float score;
	char addr[30];
};

int main()
{
	struct student s = { 1001,"lele",'M',20,98.5,"BeiJing" };//声明结构体类型后，定义变量名;初始化数据:
	//sizeof(s)=68而非直观计算得来的63，原理：寄存器以4的倍数去取地址；(四个字节）对齐，字符sex（M）多占了3个字节，addr[30]多占了两个字节
	struct student sarr[3];//定义一个结构体类型的数组
	int ret,i;
	memset(&s, 0, sizeof(s));//将s初始化，清空为零
	ret=scanf("%d %s %c %d %f %s", &s.num, s.name, &s.sex, &s.age, &s.score, s.addr);//读取时需要取地址，字符数组不需要（数组名里就是地址）
	//通过返回值ret查看读取成功数；读取字符型数据时，需要在字符数据和其他数据间加入空格（字符型数据%c不会忽略空格）
	printf("%d %s %c %d %5.2f %s\n", s.num, s.name, s.sex, s.age, s.score, s.addr);//结构体类型变量的输出
	printf("-------------------------------\n");
	for (i = 0; i < 3; i++)
	{
		scanf("%d%s %c%d%f%s", &sarr[i].num, sarr[i].name, &sarr[i].sex, &sarr[i].age, &sarr[i].score, sarr[i].addr);
	}
	for (i = 0; i < 3; i++)
	{
		printf("%d %s %c %d %5.2f %s\n", sarr[i].num, sarr[i].name, sarr[i].sex, sarr[i].age, sarr[i].score, sarr[i].addr);
	}
	system("pause");
}