#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//指针变量是存地址，指针变量，工作时，地址就是指针
//指针变量本质为了实现间接访问
void pointer_essence()//指针的本质
{
	int i = 10;
	int* p;//取值符*，解引用
	printf("i=%d\n", i);//直接访问
	p = &i;//取地址符&，引用
	//*p=*&i=i
	printf("*p=%d\n", *p);//间接访问
}

//函数调用的本质就是值传递，j=&i;*j=i
void change(int* j)//j为形参；传递&i时，写int* j
{
	*j = 5;
	//*j=i;j=&i
}
//在被调函数中去改变调用函数中某个变量的值，一定要用指针
void pointer_trans()//指针的传递使用场景
{
	int i = 10;
	printf("before change i=%d\n", i);
	change(&i);//&i为实参
	printf("after change i=%d\n", i);
}

#define N 5
void print(int* p)//传入形参指针变量*p
{
	int i;
	for (i = 0; i < N; i++)
	{
		printf("%3d", *(p + i));
	}
	p[3] = 100;//p[3]的值改变为100；写成*(p+3)等价
	printf("\n");

}
void pointer_move()//指针的偏移使用场景
{
	int a[N] = { 1,2,3,4,5 };
	int* p;
	int i;
	p = a;//保证等号两边的数值类型一致
	for (i = 0; i < N; i++)
	{
		printf("%3d", *(p + i));//*(p+i)取各地址的值(即括号后偏移的各个值）；p[i]亦可
	}
	printf("\n");
	//p = &a[4];//指向第五个元素，写成p=a+4亦可
	print(p);//调用print函数，p+4传成a+4亦可
	printf("%d\n", a[3]);//a[3]改变为100
}

void pointer_self_add()//指针与自增自减运算符
{
	int a[3] = { 2,7,8 };
	int* p;
	int j;
	p = a;
	j = *p++;//后加加：第一步，把加加去掉，j=*p；第二步，对*p++（如果*p加了括号则是对j++）
	printf("a[0]=%d,j=%d,*p=%d\n", a[0], j, *p);//输出2，2，7
	//j = p[0]++;//等价于(*p)++;    两步，j=p[0],p[0]++;    p[0]此时指向a[1],p[0]++时a[1]亦++
	//printf("a[0]=%d,a[1]=%d,j=%d,*p=%d\n", a[0],a[1], j, *p);//输出2,8,7,8
	j = *++p;
	printf("a[1]=%d,j=%d,*p=%d\n", a[1], j, *p);//输出7，8，8
}

void use_malloc()//堆空间的使用，malloc
{
	int len;
	char* p;
	printf("请输入要申请的空间大小：");
	scanf("%d", &len);
	p = (char*)malloc(len);
	strcpy(p, "hello");
	puts(p);
	//p++;不能偏移，如果要偏移，要存最初的位置，free时的指针必须是最初malloc返回的
	free(p);
}

char* stack_string()//返回char*;函数栈空间释放后，函数内所有局部变量消失
{
	char c[10] = "hello";
	return c;
}
char* heap_string()//堆空间不会因为函数执行结束而释放
{
	char* p = (char*)malloc(10);
	strcpy(p, "hello");
	return p;
}
void stack_heap()//栈空间和堆空间的区别
{
	char* p;
	p = stack_string();
	printf("%s\n", p);//无法输出hello，输出乱码
	p = heap_string();
	printf("%s\n", p);//正确输出
}

void pointer_init()//字符指针和字符数组的初始化
{
	char* p = "hello";//把字符串常量"hello"的起始地址赋给p
	char c[10] = "hello";//等价于strcpy(c,"hello");
	c[0] = 'H';
	//p[0] = 'H';//非法,可读不可写
	p = "world";
	//c = "world";//非法，c的地址已经确定下来
	puts(p);
}

void wild_pointer()//野指针
{
	int* p1, * p2, * p3;
	p1 = (int*)malloc(4);//内存分配
	*p1 = 1;//解引用，方可访问空间
	p2 = (int*)malloc(4);
	*p2 = 2;
	free(p1);
	p1 = NULL;//处理野指针，将free后的p1空间置为NULL
	p3 = (int*)malloc(4);
	*p3 = 3;
	printf("p3=%d\n", *p3);
	//*p1 = 100;//NULL不可写入
	printf("p3=%d\n", *p3);//未对p3进行修改，但此处打印100
}

void use_const()//const的使用
{
	const char* p;//const修饰指针，代表不能用p去修改它指向的空间的内容
	char str[] = "helloworld";//长度为11
	p = str;
	str[0] = 'H';
	//p[0] = 'm';//非法，左值不可修改
	p = str + 1;//可改变指向的空间
}
void use_const1()//const的使用
{
	char str[] = "helloworld";
	char str1[] = "meinv";
	char* const p = str;//const修饰变量，代表不能修改指向的空间
	//p = str + 1;//非法，不能修改指向的空间
	p[0] = 'm';//可改变指向的空间的内容
}

void mymemmove(void* to, void* from, size_t count)//自我实现memmove接口
{
	char* pFrom, * pTo;
	if (from > to)//源地址大于目的地址，即从大往小复制,直接从前往后复制即可
	{
		pFrom = (char*)from;//?强制类型转换
		pTo = (char*)to;
		while (count)
		{
			*pTo = *pFrom;//赋值（复制）
			pFrom++;//复制完一位后，往后走
			pTo++;
			count--;//使表达式趋向于假
		}
	}
	else if(from < to) {//源地址小于目的地址，即从小往大复制，此时要从后往前复制，以免破坏原值
		pFrom = (char*)from + count-1;//即最后一个开始复制
		pTo = (char*)to + count - 1;
		while (count)
		{
			*pTo = *pFrom;
			pFrom--;
			pTo--;
			count--;
		}
	}
}
void use_mem()//memcpy和memmove的差异
{
	int a[7] = { 1,2,3,4,5,6,7 };//两个不同方向的分类判断
	//memcpy(a + 2, a, sizeof(int) * 5);//使a[7]变成{1,2,1,2,3,4,5}；移动的大小是sizeof(int)*5即20个字节；即从前往后复制，无误
	//memcpy(a, a + 2, sizeof(int) * 5);//使a[7]变成{3,4,5,6,7,6,7};亦无误
	//memmove(a, a + 2, sizeof(int) * 5);//同上，无误
	mymemmove(a+2, a, sizeof(int) * 5);//自我实现的memmove
}

void arr2_print(int(*p)[4], int row)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < sizeof(*p) / sizeof(int); j++)
		{
			printf("%3d", p[i][j]);//写成*(*(p+i)+j),意思是先偏移到某一行，然后再偏移到某一个整形元素
		}
		printf("\n");
	}
}
void arr_pointer()//数组指针和二维数组
{
	int(*p)[4];//数组指针，数组类型的指针；大小为4个字节（一个指针的编址为4个字节，64位为8字节），此变量仍旧是一个指针;
	//sizeof(p)=4;sizeof(*p)=16
	//int* p1[4];//指针数组，指针类型的数组；大小为16个字节，一个指针为4字节，存放了四个指针的数组为16字节
	int a[3][4] = { 1,3,5,7,2,4,6,8,9,11,13,15 };//二维数组所存一个数组指针
	int b[4] = { 1,2,3,4 };//所存一个整型指针，&b则存放一个数组指针
	int i = 10;
	p = a;
	//p = b;//产生警告
	//a+1指向第二排即2，4，6，8；&a+1则指向整个二维数组所占空间的末尾
	arr2_print(a, 3);//传行3
}

int main()
{
	//pointer_essence();//指针的本质
	pointer_trans();//指针的传递使用场景
	pointer_move();//指针的偏移使用场景
	//pointer_self_add();//指针与自增自减运算符
	//use_malloc();//堆空间的使用，malloc
	//stack_heap();//栈空间和堆空间的区别
	//pointer_init();//字符指针和字符数组的初始化
	//wild_pointer();//野指针
	//use_const();//const的使用
	//use_const1();//const的使用
	//use_mem();//memcpy和memmove的差异
	//arr_pointer();//数组指针和二维数组
	system("pause");
}