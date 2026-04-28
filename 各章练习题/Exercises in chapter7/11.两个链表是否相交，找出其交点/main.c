#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node//定义构造体类型Node节点
{
	int val;
	struct Node* next;//携带的一级指针地址*next
}LNode, * pLNode;//缩写LNode和一级指针*pLNode

void List_Insert_pTail(pLNode* phead, pLNode* ptail, int n)
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

//构造相交：找到1号链表的第四个节点，然后让2号链表的尾节点的next指向第四个节点
void Construct_intersect_List(pLNode* p1_head, pLNode* p2_head, pLNode* p1_tail, pLNode* p2_tail)
{
	int k = 0;
	pLNode pcur = *p1_head;
	while (k < 3)//从一号节点移动三次便移动到四号节点,找到1号链表的第四个节点
	{
		pcur = pcur->next;
		k++;
	}
	(*p2_tail)->next = pcur;//2号链表的尾节点的next指向第四个节点
}

int calcListLen(pLNode* p_head)//用于计算链表长度
{
	int count = 0;
	pLNode pcur = *p_head;
	while (pcur)
	{
		++count;
		pcur = pcur->next;
	}
	return count;
}

int main()
{
	int n;
	pLNode p1_head = NULL;
	pLNode p1_tail = NULL;
	pLNode p2_head = NULL;
	pLNode p2_tail = NULL;
	int len1 = 0;
	int len2 = 0;
	pLNode longList = NULL;//长短链
	pLNode shortList = NULL;
	int dist = 0;//dist存储长短链节点数之差
	//尾部插入法建立两个链表
	while (scanf("%d", &n) != EOF)
	{
		List_Insert_pTail(&p1_head, &p1_tail, n);
	}
	while (scanf("%d", &n) != EOF)
	{
		List_Insert_pTail(&p2_head, &p2_tail, n);
	}
	//构建相交链表，原理：两个链表有不同的头节点和相同的尾节点
	Construct_intersect_List(&p1_head, &p2_head, &p1_tail, &p2_tail);
	len1 = calcListLen(&p1_head);
	len2 = calcListLen(&p2_head);
	//找出较长的链表，将其链表头赋给longList，将较短的链表赋给shortList
	if (len1 > len2)
	{
		dist = len1 - len2;
		longList = p1_head;
		shortList = p2_head;
	}
	else
	{
		dist = len2 - len1;
		longList = p2_head;
		shortList = p1_head;
	}
	//通过dist获得两链表节点数之差，先让长链表走对应的步数，再让短链和长链同时走，发现两个指针在某个位置相等时，找到交点
	while (dist--)
	{
		longList = longList->next;
	}
	while (longList && shortList)
	{
		if (longList == shortList)
		{
			printf("两个链表相交，交点为：%d\n", longList->val);
			break;
		}
		longList = longList->next;
		shortList = shortList->next;
	}
	if (NULL == longList)
	{
		printf("两个链表不相交\n");
	}
	system("pause");
	return 0;
}