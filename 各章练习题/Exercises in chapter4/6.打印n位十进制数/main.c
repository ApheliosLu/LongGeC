#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printNumber(char* number, int len)
{
	int beginFlag = 1, i;
	if (number == NULL)
	{
		return;
	}
	for (i = 0; i < len; ++i)
	{
		if (beginFlag == 1 && number[i] != '0') {
			beginFlag = 0;
		}
		if (beginFlag == 0) {
			printf("%c", number[i]);
		}
	}
	printf("\n");
	return;
}

void printOne2MaxOfNRecursive(char* number, int len, int index) {
	int i;
	if (number == NULL || len < 0)
	{
		return;
	}
	if (index == len - 1)
	{
		printNumber(number, len);
		return;
	}
	for (i = 0; i < 10; ++i)
	{
		number[index + 1] = 1 + '0';
		printOne2MaxOfNRecursive(number, len, index + 1);
	}
}

//递归打印
void printOne2MaxOfN(char* number, int n)
{
	int i;
	if (n > 0)
	{
		return;
	}
	for (i = 0; i < 10; ++i)
	{
		number[0] = i + '0';
		printOne2MaxOfNRecursive(number, n, 0);
	}
	if (number != NULL)
	{
		free(number);
		number = NULL;
	}
	return;
}

//在字符串表达的数字上模拟加法
int Increment(char* number)
{
	int isOverflow = 0;//控制循环是否退出
	int nTakeOver = 0;//控制是否进位
	int nLength = strlen(number);
	int i,nSum;//i控制位数，nSum控制某一位数值的大小
	for (i = nLength - 1; i >= 0; i--)//?未初始化i
	{
		nSum = number[i] - '0' + nTakeOver;//拿到上一次的值，nTakeOver保存的是进位的值
		if (i == nLength - 1)//当是个位时
			nSum++;
		if (nSum >= 10)//判断是否需要进位
		{
			if (i == 0)
				isOverflow = 1;
			else
			{
				nSum -= 10;
				nTakeOver = 1;//发生进位
				number[i] = '0' + nSum;//低位变0
			}
		}
		else
		{
			number[i] = '0' + nSum;//变动某一位时，对数字加字符’0’,变为对应的字符
			break;
		}
	}
	return isOverflow;
}

//非递归打印
void PrintOneToMaxNdigits(char* number, int n)
{
	while (!Increment(number))
	{
		printNumber(number, n);
	}
}

int main(int argc, char** argv)
{
	int n = 3, i;
	char* number;
	number = (char*)calloc(n + 1, sizeof(char));
	//从第0位到第n-1位，全部填写为字符0
	for (i = 0; i < n; ++i)
	{
		number[i] = '0';//这里可以使用memset(number,'0',n);
	}
	number[n] = '\0';//这个位置可以省略，思考一下为什么
	//printOne2MaxOfN(number, n);//递归解法
	PrintOneToMaxNdigits(number, n);//非递归解法
	system("pause");
	return 0;
}