#include<stdio.h>
#include<stdlib.h>

void decimal_binary()//十进制数转换成二进制数
{//方法：不断地除以2
#define N 2//定义N为2
	int m, r;
	int binary[50];
	int decimal;
	printf("输入一个十进制数：（Ctrl+Z)结束\n");
	while (scanf_s("%d", &decimal) != EOF)
	{
		int i = 0; m = decimal;
		while (m / N != 0) {
			r = m % N;
			m = m / N;
			binary[i++] = r;
		}
		binary[i++] = m;
		for (int j = i - 1; j >= 0; j--)
			printf("%d", binary[j]);
		printf("\n");
	}
	return 0;
#undef N
}

void binary_decimal()//二进制数转换成十进制数
{//方法：将二进制数的每一位乘以2的幂次，最低位是2的零次幂
#define N 2
	int decimal = 0;
	char b; int bw = 1;
	int binary[50];
	int i = 0;
	printf("输入：\n");
	while (scanf_s("%c", &b) != EOF) {
		if (b == '\n')
			break;//书上这里写的是continue
		binary[i++] = b - '0';// 减去字符0的ascii码，获得距离0的距离，1即是1，9即是9
	}
	for (int j = i - 1; j >= 0; j--) {
		decimal += binary[j] * bw;
		bw = bw * N;
	}
	printf("%d\n", decimal);
	return 0;
#undef N
}

void decimal_hexadecimal()//十进制数转换成十六进制数  !!!256可转化为100但会出现32转化为20的问题
{//方法：不断地除以16
#define N 16//定义N为16
	int m, r;
	int binary[50];
	int decimal;
	printf("输入一个十进制数：（Ctrl+Z)结束\n");
	while (scanf_s("%d", &decimal) != EOF)
	{
		int i = 0; m = decimal;
		while (m / N != 0) {
			r = m % N;
			m = m / N;
			binary[i++] = r;
		}
		binary[i++] = m;
		for (int j = i - 1; j >= 0; j--)
			printf("%d", binary[j]);
		printf("\n");
	}
	return 0;
#undef N
}

void hexadecimal_decimal()//十六进制数转换成十进制数
{
#define N 16
	int decimal = 0;
	char b; int bw = 1;
	int binary[50];
	int i = 0;
	printf("输入：\n");
	while (scanf_s("%c", &b) != EOF) {
		if (b == '\n')
			continue;
		if (b >= 65 && b <= 70)//此两行与十进制数转化为二进制数时不同
			binary[i++] = b - 'A' + 10;//65到70之间的数即A到F
		else
			binary[i++] = b - '0';
	}
	for (int j = i - 1; j >= 0; j--) {
		decimal += binary[j] * bw;
		bw = bw * N;
	}
	printf("%d\n", decimal);
	return 0;
#undef N
}
int main()
{
	//decimal_binary();//十进制数转换成二进制数
	binary_decimal();//二进制数转换成十进制数
	//decimal_hexadecimal();//十进制数转换成十六进制数
	//hexadecimal_decimal();//十六进制数转换成十进制数
}

void decimal_binary()//十进制数转换成二进制数
{//方法：不断地除以2
#define N 2//定义N为2
	int m, r;
	int binary[50];
	int decimal;
	printf("输入一个十进制数：（Ctrl+Z)结束\n");
	while (scanf_s("%d", &decimal) != EOF)
	{
		int i = 0; m = decimal;
		while (m / N != 0) {
			r = m % N;
			m = m / N;
			binary[i++] = r;
		}
		binary[i++] = m;
		for (int j = i - 1; j >= 0; j--)
			printf("%d", binary[j]);
		printf("\n");
	}
	return 0;
#undef N
}

void binary_decimal()//二进制数转换成十进制数
{//方法：将二进制数的每一位乘以2的幂次，最低位是2的零次幂
#define N 2
	int decimal = 0;
	char b; int bw = 1;
	int binary[50];
	int i = 0;
	printf("输入：\n");
	while (scanf_s("%c", &b) != EOF) {
		if (b == '\n')
			break;//书上这里写的是continue
		binary[i++] = b - '0';// 减去字符0的ascii码，获得距离0的距离，1即是1，9即是9
	}
	for (int j = i - 1; j >= 0; j--) {
		decimal += binary[j] * bw;
		bw = bw * N;
	}
	printf("%d\n", decimal);
	return 0;
#undef N
}

void decimal_hexadecimal()//十进制数转换成十六进制数  !!!256可转化为100但会出现32转化为20的问题
{//方法：不断地除以16
#define N 16//定义N为16
	int m, r;
	int binary[50];
	int decimal;
	printf("输入一个十进制数：（Ctrl+Z)结束\n");
	while (scanf_s("%d", &decimal) != EOF)
	{
		int i = 0; m = decimal;
		while (m / N != 0) {
			r = m % N;
			m = m / N;
			binary[i++] = r;
		}
		binary[i++] = m;
		for (int j = i - 1; j >= 0; j--)
			printf("%d", binary[j]);
		printf("\n");
	}
	return 0;
#undef N
}

void hexadecimal_decimal()//十六进制数转换成十进制数
{
#define N 16
	int decimal = 0;
	char b; int bw = 1;
	int binary[50];
	int i = 0;
	printf("输入：\n");
	while (scanf_s("%c", &b) != EOF) {
		if (b == '\n')
			continue;
		if (b >= 65 && b <= 70)//此两行与十进制数转化为二进制数时不同
			binary[i++] = b - 'A' + 10;//65到70之间的数即A到F
		else
			binary[i++] = b - '0';
	}
	for (int j = i - 1; j >= 0; j--) {
		decimal += binary[j] * bw;
		bw = bw * N;
	}
	printf("%d\n", decimal);
	return 0;
#undef N
}

int main()
{
	//decimal_binary();//十进制数转换成二进制数
	binary_decimal();//二进制数转换成十进制数
	//decimal_hexadecimal();//十进制数转换成十六进制数
	//hexadecimal_decimal();//十六进制数转换成十进制数
}