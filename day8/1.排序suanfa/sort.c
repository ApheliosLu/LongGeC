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
		for (j = i - 1; j >= 0; j--)
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

void arr_shell(int* arr)
{
	int gap, i, j, insert_val;
	for (gap = N >> 1; gap > 0; gap >>= 1)
	{
		for (i = gap; i < N; i++)
		{
			insert_val = arr[i];
			for (j = i - gap; j >= 0; j -= gap)//j=j-gap
			{
				if (insert_val < arr[j])
				{
					arr[j + gap] = arr[j];
				}
				else {
					break;
				}
			}
			arr[j + gap] = insert_val;//j一直--往前移动，直至循环条件不满足，此时将insert_val赋给arr[j+1]
		}
	}

}

int partition(int* arr, int left, int right)//分割函数
{
	int k, i;//k记录要放入比分隔值小的数据的位置
	for (i = left, k = left; i < right; i++)
	{
		if (arr[i] < arr[right])
		{
			SWAP(arr[k], arr[i]);
			k++;
		}
	}
	SWAP(arr[k], arr[right]);//将k位置的值与分隔值交换
	return k;//此时返回k即分隔值的位置
}

void arr_quick(int* arr, int left, int right)//两个int代表传入的数组的边界
											 //快速排序，每次递归使用8个字节的空间，递归次数log2n,字节数8*log2n;空间复杂度log2n
{
	int pivot_pos;//分隔值
	if (left < right)
	{
		pivot_pos = partition(arr, left, right);//通过partition函数获得分隔值；由partition函数返回得来的最终的“k的下标”
		arr_quick(arr, left, pivot_pos - 1);//分割后，左边数组的边界变为left和pivot_pos-1
		arr_quick(arr, pivot_pos + 1, right);//大于分隔值的右边数组，同理
	}

}
//qsort函数给compare函数传递的两个参数（void型指针）为：任意两个位置的地址值
int compare(const void* pleft, const void* pright)//pleft,pright分别指向数组的任意两个位置元素的地址值
{
	int* p1 = (int*)pleft;
	int* p2 = (int*)pright;
	if (*p1 > *p2)
	{
		return 1;//默认从小到大排列，若要改成从大到小则此处改为return -1
	}
	else if (*p1 < *p2)
	{
		return -1;
	}
	else {
		return 0;
	}
}

void adjust_max_heap(int* arr, int adjust_pos, int len)
{
	int dad = adjust_pos;//将父结点地址赋予dad变量
	int son = 2 * dad + 1;//左子结点
	while (son < len)//循环结束条件
	{
		//判断是否存在右节点&左右子结点比较
		if (son + 1 < len && arr[son] < arr[son + 1])
		{
			son++;
		}
		//如果子结点大于父结点
		if (arr[son] > arr[dad])
		{
			SWAP(arr[son], arr[dad]);
			dad = son;//将son赋给dad，现在的dad是交换之后的son
			son = 2 * dad + 1;//防止交换后，搞乱已经排序好的下层子树
		}
		else {
			break;
		}
	}

}

void arr_heap(int* arr)//时间复杂度:3n*log2n/2即nlog2n
{
	int i;
	//形成一个初步的大根堆
	for (i = N / 2 - 1; i >= 0; i--)
	{
		adjust_max_heap(arr, i, N);//传入数组起始地址,（最后一个）父结点地址，数组长度；
	}
	//将顶部元素和最后一个元素交换
	SWAP(arr[0], arr[N - 1]);
	for (i = N - 1; i > 1; i--)
	{
		//不断调整根部元素为大根堆
		adjust_max_heap(arr, 0, i);
		//将顶部元素和最后一个元素交换
		SWAP(arr[0], arr[i - 1]);
	}
}

//合并两个有序数组
void merge(int* arr, int low, int mid, int high)
{
	int b[N];
	int i, j, k;
	for (i = low; i <= high; i++)
	{
		b[i] = arr[i];//将arr拷贝进b
	}
	for (k = low, i = low, j = mid + 1; i <= mid && j <= high; k++)
	{
		if (b[i] < b[j])
		{
			arr[k] = b[i++];
			//k++;
			//i++;
		}
		else {
			arr[k] = b[j++];
			//k++;
			//j++;
		}
	}
	while (i <= mid)//若low到mid中仍有剩余
	{
		arr[k++] = b[i++];
		//k++;
		//i++;
	}
	while (j <= high)//若mid到high中仍有剩余
	{
		arr[k++] = b[j++];
		/*k++;
		j++;*/
	}
}

void arr_merge(int* arr, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		arr_merge(arr, low, mid);
		arr_merge(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}

void arr_count(int* arr)//时间复杂度O(n+m),m为下列代码中的M即数的取值范围
{
	int arr_count[M] = { 0 };
	int i,j,k;
	for (i = 0; i < N; i++)//遍历生成的随机数
	{
		arr_count[arr[i]]++;//统计arr里的每一个值出现的次数
	}
	k = 0;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < arr_count[i]; j++)//控制赋值次数
		{
			arr[k++] = i;//等同于此处写arr[k]=i,下一行写k++
		}
	}

}

void use_bitmap()//使用位图去重
{
	//找寻第三大的数
	long long bitmap[10] = { 0 };//long long每个元素占8个字节64位;此数组可存储640个数（用640个位），范围为0~639
	int i;
	while (scanf("%d", &i)!=EOF)
	{
		bitmap[i / 64] = bitmap[i / 64] | 1 << i % 64;
		//首先，i/64代表获得一个数后对arr[i]进行操作，比如129/64则对arr[2]进行操作；bitmap=arr
		//？其次，arr[i/64]按位或1<<i%64,代表将640位中对应的位数判定为1或0；
		//按位或为真，说明有一个数存在在arr[i]的位置
	}
}

#define MaxKey 1000
int hash(char* key)//elf hash函数，一列对key的位操作
{
	int h = 0, g;
	while (*key)
	{
		h = (h << 4) + *key++;
		g = h & 0xf0000000;
		if (g)
		{
			h ^= g >> 24;
		}
		h &= ~g;
	}
	return h % MaxKey;
}

void use_hash()
{
	char* pStr[5] = { "xiongda","lele","hanmeimei","wangdao","fenghua" };//将字符串hash后存入hash表
	int i;
	char* pHash_table[MaxKey] = { NULL };//定义一个哈希表（字符指针类型），初始化
	for (i = 0; i < 5; i++)
	{
		printf("%10s hashValue=%d\n", pStr[i], hash(pStr[i]));
		pHash_table[hash(pStr[i])] = pStr[i];//pstr[i]作为key
	}
}