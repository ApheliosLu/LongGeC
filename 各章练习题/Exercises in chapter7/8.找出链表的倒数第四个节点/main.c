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

//计算链表长度
int calcListLen(pLNode phead)
{
	int count = 0;
	pLNode pcur = phead;
	while (pcur)
	{
		++count;//每加一，往后走一节
		pcur = pcur->next;
	}
	return count;
}

int main()
{
	int n;
	int len = 0;
	int x = 1;
	pLNode phead = NULL, ptail = NULL;
	pLNode p1 = NULL, p2 = NULL;
	while (scanf("%d", &n) != EOF)
	{
		List_Tail_Insert(&phead, &ptail, n);//尾插法新建链表
	}
	len = calcListLen(phead);//判断链表长度
	if (len < 4)
	{
		printf("链表长度小于4，没有倒数第4个元素！\n");
	}
	else
	{
		p1 = phead;//跟随指针
		p2 = phead;//p2先走4步，然后p1和p2一起走，p2走到末尾时，p1就指向倒数第4个元素
		while (p2->next)
		{
			if (x >= 4)//!
			{
				p1 = p1->next;
			}
			p2 = p2->next;
			x++;
		}
		printf("链表的倒数第4个元素是:%d\n", p1->val);
	}
	system("pause");
	return 0;
}