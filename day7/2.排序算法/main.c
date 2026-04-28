#include"sort.h"


int main()
{
	int arr[N];
	int i;
	//随机数
	srand(time(NULL));
	for (i = 0; i < N; i++)
	{
		arr[i] = rand() % 100;//将获得的随机数存入数组arr
		//printf("%d\n", rand()%100);//打印10个随机数，每次运行输出结果不同
	}//取模100后，得到0~99之间的数
	print(arr);//调用打印函数print的接口，传入实参arr
	//arr_select(arr);//选择排序
	arr_insert(arr);
	print(arr);//选择排序后再打印一次结果
	system("pause");
}
