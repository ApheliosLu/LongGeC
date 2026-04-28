#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define N 100000000
int cmp(const void* p1, const void* p2)//建立比较函数
{
	return *(int*)p1 - *(int*)p2;
}

//size是要排序的数的数量，k代表数的数值变化范围
int ctsort(int* data, int size, int k)
{
	int* counts,
		* temp;

	int i, j;

	/*为计数器数组分配空间*/
	if ((counts = (int*)malloc(k * sizeof(int))) == NULL)
		return -1;

	/*为已排序元素临时存放数组分配空间*/
	if ((temp = (int*)malloc(size * sizeof(int))) == NULL)
		return -1;

	/*初始化计数数组*/
	for (i = 0; i < k; i++)
	{
		counts[i] = 0;
	}

	/*统计每个元素出现的次数（counts的下标索引即是要统计的元素本身）*/
	for (j = 0; j < size; j++)
		counts[data[j]] = counts[data[j]] + 1;

	/*将元素本身的次数加上它前一个元素的次数（得到元素偏移量）*/
	for (i = 1; i < k; i++)
		counts[i] = counts[i] + counts[i - 1];

	/*关键代码：使用上面得到的计数数组放置每个元素要排序的位置*/
	for (j = size - 1; j >= 0; j--)
	{
		temp[counts[data[j]] - 1] = data[j];/*counts的值是元素要放置到temp中的偏移量，零次不放*/
		counts[data[j]] = counts[data[j]] - 1;
	}

	/*将ctsort已排序的元素从temp复制回data*/
	memcpy(data, temp, size * sizeof(int));

	/*释放前面分配的空间*/
	free(counts);
	free(temp);
	return 0;
}

void main()
{
	int* a;//整型指针a
	int i;
	time_t start, end;

	a = (int*)malloc(sizeof(int) * N);//分配（地址）空间
	srand(time(NULL));
	//随机数生成，生成一亿个0到99之间的数
	for (i = 0; i < N; i++)
	{
		a[i] = rand() % 100;
	}
	time(&start);
	qsort(a,N,sizeof(int),cmp);
	//ctsort(a, N, 100);
	time(&end);
	printf("%d\n", end - start);
	system("pause");
	return 0;
}