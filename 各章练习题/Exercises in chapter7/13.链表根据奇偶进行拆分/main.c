#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node//定义构造体类型Node节点
{
	int val;
	struct Node* next;//携带的一级指针地址*next
}LNode, * pLNode;//缩写LNode和一级指针*pLNode

void list_tail_insert(pLNode* phead, pLNode* ptail, int n)
{
	pLNode s = (pLNode)malloc(sizeof(LNode));//新建一级指针s并分配空间
	memset(s, 0, sizeof(LNode));
	s->val = n;
	if (*ptail == NULL)//尾插法用*ptail==NULL来判断
	{
		*phead = s;
		*ptail = s;
	}
	else
	{
		(*ptail)->next = s;
		*ptail = s;
	}
}

void List_Print(pLNode phead)
{
	pLNode cur = phead;
	while (cur)
	{
		printf("%d  ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

//链表拆分
void divideList(pLNode phead, pLNode* pheadL1, pLNode* ptailL1, pLNode* pheadL2, pLNode* ptailL2)//?为什么phead前不加*，是因为不需要改变值吗
{
	int n = 1;//直接用顺序来divide吗
	while (phead != NULL)
	{
		if (n % 2 != 0)//奇
		{
			list_tail_insert(pheadL1, ptailL1, phead->val);
		}
		else {
			list_tail_insert(pheadL2, ptailL2, phead->val);
		}
		n++;
		phead = phead->next;
	}
}

int main()
{
	pLNode phead = NULL, ptail = NULL;//原链表
	pLNode pheadL1 = NULL, pheadL2 = NULL;//拆分后的链表1，2
	pLNode ptailL1 = NULL, ptailL2 = NULL;
	int n;
	while (scanf("%d", &n) != EOF)
	{
		list_tail_insert(&phead, &ptail, n);
	}
	divideList(phead, &pheadL1, &ptailL1, &pheadL2, &ptailL2);
	printf("链表原来是：");
	List_Print(phead);
	printf("链表L1：");
	List_Print(pheadL1);
	printf("链表L2：");
	List_Print(pheadL2);
	system("pause");
	return 0;
}