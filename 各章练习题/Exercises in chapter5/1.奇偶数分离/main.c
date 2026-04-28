#include<stdio.h>
#include<stdlib.h>

void adj_arr(int arr[], int arr_len)//传入整型数组arr和整型数arr_len,设置函数参数为数组和该数组的长度
{
	int i = 0, j = arr_len - 1;//设置两个变量，分别代表数组第一个元素和最后一个元素的下标,最开始值为a[0]和a[9]
	int tmp = 0;
	while(i < j)//数组首端小于尾端下标时
	{
		if ((arr[i] % 2 == 0) && (arr[j] % 2 == 1))//判断第一个元素和最后一个元素的奇偶，若第一个元素为偶，最后一个为奇，则互换二者
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
		if (arr[i] % 2 == 1)//若第一个为奇，则i++
			i++;
		if (arr[j] % 2 == 0)//若最后一个为偶，则j--
			j--;
	}//不断地循环，直至i>=j
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr_len = 0;//?
	int i = 0;
	arr_len = sizeof(arr) / sizeof(arr[0]);//   40/4=10
	adj_arr(arr, arr_len);//子函数
	for (i = 0; i < arr_len; i++)
	{
		printf("%d", arr[i]);
	}
	system("pause");
	return 0;
}