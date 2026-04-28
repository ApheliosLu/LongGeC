#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//求字符数组的最大值和次大值，定义函数如下：
//void big(char* arr[], int size, char** big1, char** big2)


//法1：冒泡法比较交换指针数组
void big_bubble(char* arr[], int size, char** big1, char** big2)
{
	int i, j;
	char* t;
	//冒泡法排序，外层控制比较的次数，内层根据次序进行比较
	for (i = size; i > 0; i--)//排序的思想，i=size=6轮，六轮至少可以把最大的数放到最前面，实际操作中四轮完成
	{
		for (j = 0; j < i - 1; j++) {
			if (strcmp(arr[j], arr[j + 1]) < 0) {
				t = arr[j];//两相比较，交换值
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
	*big1 = arr[0];
	*big2 = arr[1];
}

//法2：不交换指针数组
void big(char** arr, int size, char** big1, char** big2)//只有传入*big1的地址即**big1，方可在被调函数中修改*big1的值
{
	int i;
	*big1 = strcmp(arr[0], arr[1]) > 0 ? arr[0] : arr[1];//条件运算符
	*big2 = strcmp(arr[0], arr[1]) > 0 ? arr[1] : arr[0];
	for (i = 2; i < size; i++)
	{
		if (strcmp(arr[i], *big1) > 0)
		{
			*big2 = *big1;
			*big1 = arr[i];
		}
		else if (strcmp(arr[i], *big2) > 0)
		{
			*big2 = arr[i];
		}
	}
}

void main()
{
	char* a[6];//字符指针数组
	char b[6][10] = { "how","hello","help","god","is","girl" };
	char* x, * y;//x用来指向最大字符串，y用来指向次大字符串
	int i;
	for (i = 0; i < 6; i++)
	{
		a[i] = b[i];//字符指针数组指向二维字符数组，不直接判断二位字符数组，二是通过字符指针数组来交换
	}
	big(a, 6, &x, &y);//法2：不交换指针数组的方法；考查二级指针的传递与偏移使用场景
	//big_bubble(a, 6, &x, &y);//法1：冒泡法比较交换指针数组
	puts(x);
	puts(y);
	system("pause");
}