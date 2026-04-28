#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void scanf_while()//scanf循环输入
{
	int i, ret;//ret用来获取scanf的返回值
	while (rewind(stdin), (ret = scanf("%d", &i)) != EOF)//rewind刷新（清空）标准输入缓冲区，避免疯狂打印
	{
		printf("%d\n", i);//最后在下三行首按3次组合键Ctrl+z让scanf函数失效，结束循环
	}
}

void scanf_many_type()//多种数据类型混合输入
{
	int i,ret;
	char c;
	float f;
	double d;
	while (rewind(stdin),(ret = scanf("%d %c%f%lf", &i, &c, &f,&d)) != EOF)//输入类型包括%c即字符型时，需要在前加入空格来读取抵消输入时的空格；双精度浮点数即double型在输入时需用%lf来输入，四字节和八字节的98.5在计算时不一样，因为存储时格式不一样
	{
		printf("i=%d,c=%c,f=%.5f,d=%f,ret=%d\n", i, c, f,d,ret);//.5f表示保留五位小数，以此类推;输出的ret为scanf函数的返回值（数），此时ret=4，EOF即endoffile的返回值为-1
	}
}

void use_getchar()//练习getchar
{
	char c;
	c = getchar();
	putchar(c);
}

void printf_alignment()//联系printf对齐打印格式
{
	int i = 10;
	float f = 98.3;
	printf("student info num=%3d,score=%5.2f\n", i, f);//默认靠右对齐；3d代表从右数三位；3d前加个0则输出010
	printf("student info num=%-3d,score=%5.2f\n", i, f);//加负号后靠左对齐；-3d代表占从左数三位
	printf("%10s\n", "hello");//默认靠右对齐，10s则代表从右边数十位，“hello”占右边的五位
}

void calc_operator()//使用取余运算符%;  算术运算符+-*/%
{
	int i = 12345,result;//华为面试题（测试一个数是否是对称数，方法如下即取余）
	while (i)//C语言中0代表假，任何非0代表真，此处的i即代表i!0；无布尔类型的True和False
	{
		printf("%c\n", i % 10+'0');//!!!输出5 4 3 2 1，即所求取余;加零部分原因在于此时输出类型是字符型，将输出ASCII码的第54321个字符而加了零之后则变成数字54321，加48亦可；是一种数值和字符之间的转换
		i = i / 10;
	}
}

void relation_()//关系运算符
{
	int year;
	while (scanf("%d", &year) != EOF)//!!!
	{
		if (year%4==0&&year%100!=0||year%400==0)//涉及到关系运算符的顺序问题，无论year输入5还是10000，此时3<year为真即为1，1<10；加上逻辑与运算符&&之后即可
		{
			printf("year is leap year\n");
		}else {
			printf("year is not leap year\n");

		}
	}
}

void use_logic()//短路运算
{
	int j = 1, i = 5;
	j == 0 && printf("system is error\n");//短路运算判断j是否等于0,短路运算不受优先级干扰,精简代码;逻辑与，不打印
	j == 0 || printf("system is error two\n");//逻辑或前为假，打印；前为真，即j==1则不打印
}

void bit_calc()//位运算符:左移乘2;右移,正数高位补0，负数高位补1
{
	short i =5;//防止移动到符号位
	printf("i<<1=%d\n", i<<1);//i左移一位；输出i<<1=10(即左移相当于乘以2的1次方）；malloc(1<<30)即申请1G内存，1<<20为1M,1<<10为1K
	printf("%d\n", i);//i本身仍是5，能改变数值的只有两种，一是赋值，二是加加减减/自增自减；输出5
	//short i =-5;
	//printf("i>>1=%d\n", i>>1);//i=5右移输出2，i=-5右移输出-3；即(负数）奇数先减一再除以二
}

void xor ()//位运算符
{
	int a[7] = { 7,5,7,8,11,8,11 };//快速在一群出现两次的数中找到只出现一次的数
	int i,ret=0;
	for (i = 0; i < 7; i++)
	{
		ret = ret ^ a[i];
	}
	printf("ret=%d\n", ret);//输出5
	printf("%d\n", 5 ^ 7);//按位异或（满足交换律）；输出2，相同为假即0，相异为真即本身
	printf("%d\n", ~5);//取反，此时输出-6
	printf("%d\n", 5 & 7);//按位与：都为1时为1；相同保留，相异得零；输出5
	printf("%d\n", 5 | 7);//按位或；0与1或运算得1，1与1或运算得1，输出7
	printf("%d\n", 28 & -28);//“经过和相反数的与运算，得到原数保留最低位为1的结果”
}

void assign()//赋值运算符
{
	int b=3;
	b += 5;//b+=5相当于b=b+5
	printf("b=%d\n",b);
}

void condition()//三目运算符/条件运算符
{
	int i, j, k, max_value;//寻找三个数中的最大数，涉及“遍历和排序”
	while (scanf("%d%d%d",&i,&j,&k) != EOF)//一条语句找两个数中的最大值：三目运算符先进行判断，若前表达式为真即i>j则取中间的值为这个函数的值即?:中间的值，此时为i；相反则取j
	{
		max_value = (i > j ? i : j)>k?(i > j ? i : j):k;
		//或用此语句亦可；max_value = i > j ? (i > k ? i : k) : (j > k ? j : k);
		printf("%d\n", max_value);
	}
}

void add_self()//自增自减运算符
{
	int i = -1;
	int j;
	j = i++ > -1;//!!!后加加，先去掉加加；分解为j=i>-1和i++即i=i+1两句来看；前一句，判断语句，j为0或1；后一句i=-1+1=0
	printf("i=%d,j=%d\n", i, j);//输出i=0，j=0
	j = !++i;//++i为1，!取非，j为0
	printf("i=%d,j=%d\n", i, j);//输出i=1,j=0
}
int main()
{
	scanf_while();  //scanf循环输入
	scanf_many_type();//多种数据类型混合输入
	//use_getchar();//练习getchar
	//printf_alignment();//联系printf对齐打印格式
	//calc_operator();//使用取余运算符%
	//relation_();//关系运算符
	//use_logic();//短路运算
	//bit_calc();//位运算符，左移右移
	//xor ();//位运算符
	//assign();//赋值运算符
	//condition();//三目运算符/条件运算符
	//add_self();//自增自减运算符
	system("pause");
}