#include"func.h"

//只打印学号
void list_print(pstu phead)
{
	while (phead != NULL)//链表不为空时
	{
		printf("%3d", phead->num);//打印num部分
		phead = phead->pNext;//往后遍历打印
	}
	printf("\n");
}

//打印学号和分数
void list_print_score(pstu phead)
{
	while (phead != NULL)
	{
		printf("%3d  %5.2f", phead->num, phead->score);
		phead = phead->pNext;
	}
	printf("\n");
}

void list_tail_insert(pstu* pphead, stu** pptail, int i)
{
	pstu pnew;//定义新插入节点的指针，系一级指针
	pnew = (pstu)malloc(sizeof(stu));//为其分配空间
	memset(pnew, 0, sizeof(stu));//初始化
	pnew->num = i;//与输入的i建立联系，i作为新插入节点pnew的num项
	if (NULL == *pptail)//判断链表是否为空（*pptail是否为NULL），为空时，pnew既为头又为尾
	{
		*pphead = pnew;//原指向“链表头的地址”的二级指针*pphead现指向pnew，即令新插入的节点pnew成为新的链表头
		*pptail = pnew;//也成为新的链表尾
	}
	else {//若链表不为空时
		(*pptail)->pNext = pnew;//将新节点的地址赋值给尾节点的pnext
		*pptail = pnew;//使其成为新的尾节点
	}
}

void list_head_insert(pstu* pphead, pstu* pptail, int i)
{
	pstu pnew;
	pnew = (pstu)malloc(sizeof(stu));
	memset(pnew, 0, sizeof(stu));
	pnew->num = i;
	if (NULL == *pptail)//同尾插法，若链表为空则新插入的节点既成为新的头节点也成为新的尾节点
	{
		*pphead = pnew;
		*pptail = pnew;
	}
	else {
		pnew->pNext = *pphead;//将新插入的pnew的pNext项赋给*pphead即指向头节点的地址的指针
		*pphead = pnew;
	}

}

void list_sort_insert(pstu* pphead, pstu* pptail, int i)
{
	pstu pcur, ppre;//定义“大哥小弟”，用于指向新插入节点的两端
	pstu pnew;
	pnew = (pstu)calloc(1, sizeof(stu));
	pnew->num = i;
	pcur = *pphead;//让两个指针都指向链表头
	ppre = pcur;
	if (NULL == pcur)//判断链表是否为空
	{
		*pphead = pnew;
		*pptail = pnew;

	}
	//若不为空
	else if (i > pcur->num)//情况1：判断i是否大于头部数据，若是则将其插入头部（以从大到小排列链表的情况为例，从小到大则相反）
	{
		pnew->pNext = pcur;//原有链表的头指针赋给新节点的pNext
		*pphead = pnew;//新节点变为链表头
	}
	else {//情况2：插入中间
		while (pcur != NULL)
		{
			if (i > pcur->num)//从大到小排列，若i小于pcur->num，将pnew插入ppre和pcur中间
			{
				ppre->pNext = pnew;
				pnew->pNext = pcur;
				break;//停止循环
			}
			ppre = pcur;//前指针先赋给后指针
			pcur = pcur->pNext;//前指针往前移动，进行遍历以致满足i>pcur->num
		}
		if (NULL == pcur)//情况3：插入尾部
		{
			(*pptail)->pNext = pnew;//将新节点的地址赋给尾节点的pnext
			*pptail = pnew;//新节点变为链表尾部
		}
	}
}

void list_delete(pstu* pphead, pstu* pptail, int delete_num)
{
	pstu pcur, ppre;
	pcur = *pphead;//将头节点的地址赋给pcur
	ppre = pcur;
	//1.考虑链表为空时的情况
	if (NULL == pcur)
	{
		printf("list is empty\n");
		return;
	}
	//2.删除头部
	if (delete_num == pcur->num)//情1：若删除头部即“2”，写成dellete_num=(*pphead)->num亦可
	{
		*pphead = pcur->pNext;//将头部保存的pnext即下一项的地址赋值给pphead，使其成为新的头;pcur仍指向旧的头
		//free(pcur);//将pcur给free掉，达到删除头部的目的；删除此行，精简代码
		//pcur = NULL;//置NULL
		//!考虑尾节点被删除的情况1：头是空的
		if (NULL == *pphead)
		{
			*pptail = NULL;//则尾也是空的，链表为空
		}
	}
	//3.删除中间或尾部
	else {//情况2：若删除中间即“5”，以链表1 2 5 8为例；ppre指向2，pcur指向5
		while (pcur)//使用while遍历，若pcur存在，即pcur指向链表中的数据
		{
			if (pcur->num == delete_num)//使用pcur来判断以遍历；此时5==5
			{
				ppre->pNext = pcur->pNext;//将5中存的8的地址赋给2来存，以达到将5去除的目的；
				//上一行同时可以达到删除情况3：即删除尾部“8”的目的
				//将pcur->pnext即NULL赋给ppre->pnext，使ppre指向NULL成为新的尾部
				//free(pcur);//删除此行精简代码
				break;//达到目的后break，无需下列的遍历
			}
			ppre = pcur;//大哥出去，小弟守城
			pcur = pcur->pNext;//大哥指向下一个
		}
	}
	//若pcur为NULL，说明没有找到对应节点；对应要删除“10”的情况
	if (pcur == NULL)
	{
		printf("this val is not in list\n");
		return;
	}
	//!考虑尾节点被删除的情况2：ppre->pnext=NULL时，即尾是空的
	if (ppre->pNext = NULL)
	{
		*pptail = ppre;//对应上列尾部被删，ppre->pnext=pcur->pnext时，将ppre赋给*pptail即修改尾指针
	}
	free(pcur);//两行free合并为此行，精简代码；在pcur!=NULL的情况下，return，在经过上述两种情况的删除后free
	pcur = NULL;//置NULL
}

void list_modify(pstu phead, int i, float f)
{
	while (phead != NULL)
	{
		if (phead->num == i)
		{
			phead->score = f;
			break;
		}
		phead = phead->pNext;//遍历寻找携带的num与i相等的"phead"
	}
	if (NULL == phead)//链表为空时
	{
		printf("no this node\n");
	}
}