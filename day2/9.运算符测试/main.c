#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void arithmetic_operators()//1.算术运算符+-*/%
{
	long a;
	int g;
	int s = 4 + 5 * 2 - 6 / 3 + 10 % 4;
	printf("s=%d\n", s);//输出14
	scanf_s("%d", &a);//输入4123
	printf("a=%d\n", a);//输出a=4123
	while (a != 0)//一道面试题：输入一个证书并将其逆序输出；使用了取余运算符
	{
		g = a % 10;
		printf("%c", g + 48);//g+48使得数字变字符；
		a = a / 10;//除法运算符
	}
}

void relational()//2.关系运算符> < == >= <= !=
{//判断浮点数是否等于某个值（用减法）
	float f = 234.56;
	//if(f==234.56)//浮点数存储的是对应数的近似值，只能保证精度为7位，若使用此行判断则输出不等于
	if (f - 234.56 > -0.0001 && f - 234.56 < 0.0001)	//-1e-4 1e-4
	{
		printf("f等于234.56\n");
	}
	else {
		printf("f不等于234.56\n");
	}
	//不能写if（5==5==5）或者（3<a<10)这种形式，因为关系运算符会进行关系判断运算，值只有真1和假0，在C中0为假，非0为真
	int a;
	while (scanf_s("%d", &a) != EOF)
		//while(scanf_s("%d",&a)!=EOF)
	{
		if (a > 3 && a < 10)
		{
			printf("a在3和10之间\n");
		}
		else {
			printf("a不在3和10之间\n");
		}
	}
}

void logical()//3.逻辑运算符! && ||
{
	int i, j;
	while (scanf_s("%d", &i) != EOF)
	{
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
		{
			printf("i is leap year\n");
		}
		else {
			printf("i is not leap year\n");
		}
	}
	j = 1;//逻辑与：同时为真则为真
	j != 0 && printf("system is error\n");
	j = 0;//逻辑或，一者为真则为真，从左往右执行一者即可
	printf("system is error\n") || j == 0;
	j = 10;//逻辑非
	i = !!j;
	printf("i的值=%d\n", i);
}

void bitwise()//4.位运算符<< >> ~ | ^ &
{
	short i = -5;
	int a[5] = { 11,4,5,4,11 };
	int f = 0;
	i >> 1;//单独的i右移或者左移不会改变i的值
	i = i >> 1;//只有重新赋值给i，i的值才会改变
	for (i = 0; i < 5; i++)
	{
		f = f ^ a[i];
	}
	printf("%d\n", f);//得到f数值5；按位异或^，相同为0，不同为1，任何数和0异或得其本身；可得到五个数中只出现一次的数
	i = 5; f = 7;
	printf("i&f=%d\n", i & f);//按位与，有0则0，全1则1
	printf("i|f=%d\n", i | f);//按位或，有1则1，全0则0
	printf("~i=%d\n", ~i);//按位取反，得到-6；数位上的数是1变为0，0变为1，但得到的数是负数时要减一取反再输出现；总结：对a取反得到-（a+1）
}   //取反加一得到其相反数的补码，仅取反则由该相反数减一即可

void assignment_operator()//5.赋值运算符=
{
	char c;
	while ((c = getchar()) != EOF)
	{
		printf("%c", c);
	}
	//复合赋值运算符
	//i+=5等同于i=i+5
	//i*=5等同于i=i*5
}

void condition()//6.条件运算符（三目运算符）?:与逗号运算符,
{
	int a, b, c, max;
	while (rewind(stdin), scanf("%d%d%d", &a, &b, &c) != EOF)
	{
		max = (a > b ? a : b) > c ? (a > b ? a : b) : c;
		//或用此语句亦可，max=a>b?(a>c?a:c):(b>c?b:c);
		printf("max=%d\n", max);
	}
}

void self_calc()//自增自减运算符及求字节运算符
{
	//sizeof不是函数，是C的关键字，是一个运算符
	int i = -1;
	int j;
	//5++;//如果打开该句，会造成编译不通，常量不可自增自减
	j = i++ > -1;//后++，或者后--等价于j=i>-1;i=i+1 分成两句来理解
	printf("i=%d,j=%d\n", i, j);//输出i=0,j=0
	j = !++i;//使用前加加时，直接按优先级结合顺序，即先计算自增自减再运算逻辑非
	printf("i=%d,j=%d,sizeof(i)=%d\n", i, j, sizeof(i));//输出i=0，j=1，sizeof(i)=4即i以四个字节存储
}
int main()
{
	//arithmetic_operators();//1.算术运算符+-*/%
	//relational();//2.关系运算符> < == >= <= !=
	//logical();//3.逻辑运算符! && ||
	//bitwise();//4.位运算符<< >> ~ | ^ &
	//assignment_operator();//5.赋值运算符=
	//condition();//6.条件运算符（三目运算符）?:与逗号运算符,
	//self_calc();//自增自减运算符及求字节运算符sizeof

	printf("%c\n", '0');
	printf("%d\n", '0');
	system("pause");
}