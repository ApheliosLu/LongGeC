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


void ConstructCircleList(pLNode* phead, pLNode* ptail)
{
	int k = 0;
	pLNode pcur = *phead;
	while (k < 3)//从一号节点移动三次便移动到四号节点
	{
		pcur = pcur->next;
		k++;
	}
	(*ptail)->next = pcur;//尾指针指向某个节点
}

int main()
{
	int n;
	pLNode phead = NULL, ptail = NULL;
	pLNode slow = NULL, fast = NULL;
	//尾插法新建链表
	while (scanf("%d", &n) != EOF)
	{
		List_Tail_Insert(&phead, &ptail, n);
	}
	//自行构造有环链表，所谓有环链表，就是让尾指针指向链表中的某个节点
	ConstructCircleList(&phead, &ptail);
	slow = phead;
	fast = phead;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)//一旦有环，两个指针就一定会相遇
		{
			printf("链表存在环！\n");
			break;//!!!找到环后break
		}
	}
	if (fast == NULL || fast->next == NULL)
	{
		printf("链表没有环！\n");
	}
	system("pause");
	return 0;
}