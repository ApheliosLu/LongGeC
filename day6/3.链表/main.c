#include"func.h"

int main()
{
	//链表可以只有phead，这里有两个指针{phead,ptail}表示链表
	pstu phead=NULL,ptail=NULL;//定义链表头的一级指针phead；赋值为NULL，代表链表头不带头节点，只存储下一个节点的地址
	int val;
	float score;
	while (scanf("%d", &val) != EOF)
	{
		//头插法
		//list_head_insert(&phead, &ptail, val);//在主函数内调用头插法函数；传入实参&phead和&ptail；头插法，最后一个输入的在头部
		//上行运行，输入5 0 9 2 3 7，此时头部为7，并且链表的顺序为 732905
		//运行下列打印函数后，输出7 3 2 9 0 5

		//尾插法
		//list_tail_insert(&phead, &ptail, val);
		//输入9 2 5 1 4；输出9 2 5 1 4

		//有序插入法
		list_sort_insert(&phead,&ptail,val);
		//输入9 8 3 5 7 1，输出1 3 5 7 8 9
	}
	list_print(phead);
	printf("---------------\n");//增与删分割

	//链表的删除
	//while (scanf("%d", &val) != EOF)
	//{
	//	list_delete(&phead, &ptail, val);//删除
	//	list_print(phead);//每删除一次就打印一次
	//}

	//链表修改部分
	while (scanf("%d%f",&val,&score)!=EOF)
	{
		list_modify(phead, val, score);//函数的调用，直接传入实参
		//输入3 6 9 8 2，打印2 0.00 3 0.00以此类推
		//输入 3 98，打印2 0.00 3 98.00一次类推，达到修改链表的目的
		list_print(phead);
	}
	system("pause");
}