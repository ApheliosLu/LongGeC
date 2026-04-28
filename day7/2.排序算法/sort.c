#include"sort.h"

void print(int* arr)
{
	int i;
	for (i = 0; i < N; i++)
	{
		printf("%3d", arr[i]);
	}
	printf("\n");
}

void arr_select(int* arr)
{
	int i, j, min_pos;
	for (i = 0; i < N - 1; i++)//外层控制无序数的数量
	{
		min_pos = i;//最开始，记录最小值的位置min_pos=i=0
		for (j = i + 1; j < N; j++)//内层循环控制比较（设定比较策略）
		{
			if (arr[min_pos] < arr[j])//说明有比min_pos更小的
			{
				min_pos = j;//将arr[j]的下标j赋给min_pos
			}
		}
		SWAP(arr[i], arr[min_pos]);//第一轮：将第一个即arr[0]和一轮比较下来最小的arr[min_pos]的交换位置
		//此处不可用异或^，原因在于arr[i]和arr[min_pos]可能在同一个位置（空间），此时两者异或则得0
	}
}

void arr_insert(int* arr)
{
	int i, j, insert_val;
	for (i = 1; i < N; i++)//外层控制要插入的数据
	{
		insert_val = arr[i];//把要插入的元素存起来，随着循环依次往后移动
		for (j =i-1 ; j >= 0; j--)
		{
			if (insert_val < arr[j])
			{
				arr[j + 1] = arr[j];//第一次比较时，将较大的数赋给后一位
			}
			else {
				break;
			}
		}
		arr[j + 1] = insert_val;//j一直--往前移动，直至循环条件不满足，此时将insert_val赋给arr[j+1]
	}
}