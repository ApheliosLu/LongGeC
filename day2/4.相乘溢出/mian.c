#include <stdio.h>
#include <stdlib.h>

void default_int()//整型int任何情况下按四个字节运算，高位补0/1
{
	char c = 0x93 << 1 >> 1;
	printf("%x\n", c);//按四个字节移位，输出ffffff93
	c = 0x93 << 1;//按四个字节移位，高位丢弃，10010011左移一位变成00100110即26
	c = c >> 1;//右移一位即除以二，输出13；仍旧按四个字节，但前面补最高位0
	printf("%x\n", c);//步骤分开，输出13
}


void long_calc()//32位须用longlong型，64位用long型
{
	long long i;//以longlong定义i，64位则用long来定义，下文同理
	i = (long long)131076 * 131076;//强行转换成longlong型
	printf("%lld\n", (long long)i);//以longlong型输出
}

int main()
{
	default_int();//整型int按四个字节运算
	//long_calc();//long型输出
	system("pause");
}