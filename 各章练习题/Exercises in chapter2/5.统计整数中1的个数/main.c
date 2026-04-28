#include<stdio.h>
#include<stdlib.h>
//5.统计一个整数对应的二进制数的1的个数。输入一个整数（可正可负），输出该整数的二进制数中包含1的个数，按组合键Ctrl + Z结束。
//正数在内存中存储的是原码，负数在内存中存储的是补码，无论是原码还是补码，我们统计的都是实际在内存中二进制数为1的个数
//方法：使用移位操作实现
int main(void)
{
	int n, a, con, i;//n存储输入值，a用于存储n与1按位与的结果，con记录1的个数，i控制循环次数
	while (scanf_s("%d", &n) != EOF)
	{
		i = 32;
		con = 0;
		while (i--)
		{
			a = n & 1;
			n = n >> 1;//
			if (1 == a) {
				con++;
			}
		}printf("%d\n", con);
	}
	system("pause");
	return 0;
}