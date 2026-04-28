#include"func.h"

int main()
{
	pstu p;//定义一个pstu指针p
	pstu phead = NULL, ptail = NULL;//代表链表，将链表头尾置空
	int i;
	float f;
	while (scanf("%d", &i) != EOF)//链表的尾插、头插、有序插入
	{
		//list_tail_insert(&phead, &ptail, i);//&phead等同于pstu *pphead
		//分别传入实参：指向“链表头的地址”的地址（链表头phead本身作为一个指针指向一个地址）、指向“链表尾的地址”的地址、插入的值i
		//目的：改变链表头、尾的地址
		//输入3 6 9 2 5 8；输出 3 6 9 2 5 8

		//list_head_insert(&phead, &ptail, i);
		////输入3 6 9 2 5 8；输出 8 5 2 9 6 3

		list_sort_insert(&phead, &ptail, i);
		//输入3 6 9 2 5 8；输出 9 8 6 5 3 2
	}
	list_print(phead);//打印输出结果
	//while (printf("please input delete num:"), scanf("%d", &i) != EOF)//根据输入的i（对应num），进行链表删除
	//{
	//	list_delete(&phead, &ptail, i);
	//	list_print(phead);
	//}
	while (printf("please input modify num:"), scanf("%d%f", &i, &f) != EOF)//根据输入的i和f（对应num和score），进行链表修改
	{
		list_modify(phead, i, f);
		list_print_score(phead);//对修改后的分数进行打印输出
	}
	system("pause");
}


