#include"sort.h"

typedef struct {
	int num;
	char name[20];
	float english;
	float math;
}stu, * pstu;

int compare1(const void* pleft, const void* pright)
{
	pstu p1 = (int*)pleft;//一级指针
	pstu p2 = (int*)pright;
	//return p1->num - p2->num;//学号从小到大排序，直接return这个值即可;适合比较的是整型数时使用（int num）
	//浮点数时（float english），使用下列语句
	if (p1->english + p1->math > p2->english + p2->math)
	{
		return 1;//默认从小到大排列，若要改成从大到小则此处改为return -1
	}
	else if (p1->english + p1->math < p2->english + p2->math)
	{
		return -1;
	}
	else {
		return 0;
	}
}

int compare_hard(const void* pleft, const void* pright)//pleft, pright分别指向数组的任意两个位置元素的地址值,本身为一级指针
{
	pstu* p1 = (pstu*)pleft;//p1,p2用于指向pleft（指向任意位置元素的一级指针），因此为二级指针
	pstu* p2 = (pstu*)pright;
	if ((*p1)->english > (*p2)->english)///(*p1)取到任意位置元素的地址，->对象选择后获取到对应元素
	{
		return 1;
	}
	else if ((*p1)->english < (*p2)->english)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

void use_qsort()
{
	stu sarr[5];//构造体数组
	pstu p[5];//建立一个对应的指针数组，用于qsort排序指针数组
	int i;
	for (i = 0; i < 5; i++)
	{
		scanf("%d%s%f%f", &sarr[i].num, sarr[i].name, &sarr[i].english, &sarr[i].math);//？使用scanf_s反而会报错
		p[i] = sarr + i;//指针数组指向构造体数组
	}
	//qsort(sarr, 5, sizeof(stu), compare1);
	//qsort去排指针数组，最终输出有效效果，原数组内容打印不变
	printf("--------------------------\n");//打印指针数组有效结果
	qsort(p, 5, sizeof(pstu), compare_hard);//qsort排序指针数组
	for (i = 0; i < 5; i++)
	{
		printf("%d %s %5.2f %5.2f %6.2f\n", p[i]->num, p[i]->name, p[i]->english, p[i]->math, p[i]->english + p[i]->math);//？使用scanf_s反而会报错
	}
	printf("--------------------------\n");//打印原数组内容
	for (i = 0; i < 5; i++)
	{
		printf("%d %s %5.2f %5.2f %6.2f\n", sarr[i].num, sarr[i].name, sarr[i].english, sarr[i].math, sarr[i].english + sarr[i].math);//？使用scanf_s反而会报错
	}
}

int main()
{
	//int arr[N];//使用栈空间存储
	int* arr = (int*)malloc(sizeof(int) * N);//申请堆空间存储，
	int i;
	time_t start, end;//!定义两个时间节点
	//用接口获取随机数
	srand(time(NULL));
	for (i = 0; i < N; i++)
	{
		arr[i] = rand() % M;//将获得的随机数存入数组arr
		//printf("%d\n", rand()%100);//？打印10个随机数，每次运行输出结果不同；取模100后，得到0~99之间的数；取模100000则得到0~99999之间的数
	}
	//print(arr);//调用打印函数print的接口，传入实参arr
	start = time(NULL);//!获取排序之前的秒数（时间）

	//arr_select(arr);//选择排序
	//arr_insert(arr);//插入排序
	//arr_shell(arr);//希尔排序；N为一千万时，排序时间2s
	//arr_quick(arr, 0, N - 1);//快速排序；N为一千万时，报错Stack overflow，原因在于递归次数过多
	//qsort(arr, N, sizeof(int), compare);//使用qsort;N为一千万时，耗时3s;N为一亿时，耗时27s
	//arr_heap(arr);//N为一亿时，堆排用时31s
	//arr_merge(arr, 0, N - 1);//归并排序
	//arr_count(arr);//计数排序
	//use_bitmap();//使用位图（去重）
	use_hash();//实现elf hash并使用

	end = time(NULL);//获取排序之后的时间，放在打印之前（打印耗时）;统计排序所耗时间时，将两次打印注释掉
	//print(arr);//排序后再打印一次结果
	printf("use time=%d\n", end - start);//统计排序所用时间end-start
	//在N=50000时，选择排序用时4s，插入排序用时2s
	//use_qsort();//自己实现qsort给结构体数组排序；

	system("pause");
}
