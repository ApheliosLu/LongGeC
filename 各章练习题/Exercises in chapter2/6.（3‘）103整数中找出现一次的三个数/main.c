#include<stdio.h>
#include<stdlib.h>
#define N 7

//（1） 有101个整数，其中有50个数出现了两次，1个数出现了一次，找出出现了一次的那个数
//方法：异或：相同数字得到0，任何数与零异或最终得到本身，同时异或满足交换律。通过将101个数全部异或，最终找到出现一次的那个数
int find_one_value(int* arr)//101找1
{
	int i;
	int res = 0;
	for (i = 0; i < N; i++)
	{
		res ^= arr[i];//所有元素异或，保存在res中
	}
	return res;
}

//（2） 有102个整数，其中有50个数出现了两次，2个数出现了一次，找出出现了一次的那两个数
//方法：第一步：将所有数异或，由于有两个数出现一次，因此最终得到的异或结果实际上是两个出现一次的数的异或结果；
//第二步：由结果的最低位为1可以得知，出现一次的两个数的这一位一定不同，因此拿该位与所有的数按位与，为1的放在一堆，为0的放在另一堆，
//此时将两个出现一次的数分开，然后对两堆各自异或，就能找到出现一次的两个数
void find_two_val(int* arr)//102找2
{
	int res, res1 = 0, res2 = 0;//存储数组所有元素异或后的结果;res1,res2代表各出现一次的两个数
	int split_flag, i;
	res = find_one_value(arr);//利用one函数返回所有元素异或后的结果
	split_flag = res & -res;//？任意数和自己的相反数“按位与”得到最低位为1
	for (i = 0; i < N; i++)//将数组分为两堆
	{
		if (arr[i] & split_flag)//arr[i]与split_flag按位与为真，“1”的那一堆
		{
			res1 ^= arr[i];//进行异或找单身狗环节
		}
		else {//按位与为假，“0”的那一堆
			res2 ^= arr[i];
		}
	}
	printf("res1=%d,res2=%d\n", res1, res2);
}

void find_two_val3(int* arr,int even_val,int odd_val)//为103找3改造的上述函数的接口；传入数组容量、偶数堆和奇数堆的异或结果
{
	int i,res1 = 0, res2 = 0;
	int split_flag;
	split_flag = even_val & -even_val;//此时的split_flag为偶数堆中所有数异或(即结果even_val)后，再与相反数按位与的值
	for (i = 0; i < N; i++)
	{//此时split_flag为2
		if (arr[i] & split_flag)//在进行按位与操作分堆后，会将9和24分为一堆
		{
			res1 ^= arr[i];
		}
		else {
			res2 ^= arr[i];
		}
	}//！！！三个要找的数是6，24，9时，且9是被分离出来的奇数堆里找出来的第一个数时，
	if (split_flag & odd_val)//若split_flag（即2）和已经找出的第一个数（即9）按位与的值为真；此处为假设
	{
		printf("two value=%d,three value=%d\n", res1 ^ odd_val, res2);//此时的res1为6和9异或后的数，再次与9异或则得到6
	}
	else {//若split_flag和已经找出的第一个数（即9）按位与的值为假；此处为本例数组的实例
		printf("two value=%d,three value=%d\n", res1, res2 ^ odd_val);//此时的res2为24和9异或后的数（即上述9和24会分为一堆），再次与9异或则得到24
	}
}
//暴力求解，拿1与数组中的数按位与，通过不断地移位（最多三十二次），可将所要求的三个数分成两堆，一堆一个、另一堆两个
//通过对偶数堆异或，若不为零则说明三个数分开
void find_three_val(int* arr)//103找3
{
	int res1, res2, count1, count2;//记录两堆，对两堆计数
	int flag = 1, i, j;//flag代表用来按位与的1
	for (i = 0; i < 32; i++)
	{
		res1 = res2 = count1 = count2 = 0;
		for (j = 0; j < N; j++)//通过flag与数组的按位与，将数组分为两堆
		{
			if (flag & arr[j])//若flag与arr[j]按位与为真，为零，分为一堆
			{
				res1^=arr[j];//异或
				count1++;
			}
			else {//第二堆
				res2^=arr[j];
				count2++;
			}
		}//完成分堆
		if (count1 % 2 == 0 && res1 != 0)//若第一队为偶数堆且其异或的结果不为零
		{
			printf("find one val=%d\n", res2);//此时奇数堆的异或结果res2便是第一个找到的数
			find_two_val3(arr, res1, res2);
			break;//找到任何一个“第一个数”后break
		}
		if (count2 % 2 == 0 && res2 != 0)//另一种找到第一个数的情况
		{
			printf("find one val=%d\n", res1);
			find_two_val3(arr, res2, res1);
			break;//找到任何一个“第一个数”后break
		}
		flag = flag << 1;//未找到第一个数时，将flag=1向左移一位，继续按位与
	}
}

int main()
{
	int a[N] = { 5,8,6,8,5,24,9 };
	int val;

	//val=find_one_value(a);
	//find_two_val(a);
	find_three_val(a);

	system("pause");
}