#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node//定义构造体类型Node节点
{
	int val;
	struct Node* next;//携带的一级指针地址*next
}LNode, * pLNode;//缩写LNode和一级指针*pLNode

//尾插法新建链表
void List_Tail_Insert(pLNode* phead, pLNode* ptail, int n)
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

int main()
{
	int n;
	pLNode phead = NULL, ptail = NULL;
	pLNode pslow = NULL, pfast = NULL;
	while (scanf("%d", &n) != EOF)
	{
		List_Tail_Insert(&phead, &ptail, n);//尾插法新建链表
	}
	pslow = phead;
	pfast = phead;
	/*由于pfast要移动两个位置，所以要确保pfast与pfast->next都为真，
	在判断pfast->next->next为真，目的是当为偶数节点时，中间节点为
	前一个，比如有6个节点，中间节点是第3个节点*/
	while (pfast && pfast->next && pfast->next->next)
	{
		pslow = pslow->next;
		pfast = pfast->next->next;//pfast指针每次移动两个位置
	}
	printf("链表的中间节点为：%d\n", pslow -> val);
	system("pause");
	return 0;
}