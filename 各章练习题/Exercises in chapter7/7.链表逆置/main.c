#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node//定义构造体类型Node节点
{
	int val;
	struct Node* next;//携带的一级指针地址*next
}LNode,*pLNode;//缩写LNode和一级指针*pLNode

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

//链表打印
void Print_List(pLNode phead)
{
	pLNode pcur = phead;
	while (pcur)
	{
		printf("%d  ", pcur->val);
		pcur = pcur->next;
	}
	printf("\n");
}

int main()
{
	int n;
	pLNode phead = NULL;
	pLNode ptail = NULL;
	pLNode pre = NULL;
	pLNode pcur = NULL;
	pLNode r = NULL;//保存下一个节点的位置
	while (scanf("%d", &n) != EOF)
	{
		List_Tail_Insert(&phead, &ptail, n);
	}
	pcur = phead;
	//链表原地逆置
	while (pcur)//?如何停止循环
	{
		r = pcur->next;//r用来保存下一个节点
		pcur->next = pre;//因为pre存的是前一个节点，逆置后当前节点的next要指向前一个
		pre = pcur;//因为pcur要指向下一个节点，所以保存当前位置
		pcur = r;//将下一个节点给pcur，开始对下一个节点进行逆置
	}
	phead = pre;
	printf("链表逆置为：");
	Print_List(phead);
	system("pause");
	return 0;
}