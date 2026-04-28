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

void List_Print(pLNode phead)//用于打印删除重复元素后的链表
{
	pLNode cur = phead;
	while (cur)
	{
		printf("%d  ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

int main()
{
	int n;
	pLNode phead = NULL;
	pLNode ptail = NULL;
	pLNode pre = NULL;//存储前一个节点地址
	pLNode pcur = NULL;//存储当前节点地址
	pLNode pnext = NULL;//存储下一个节点地址
	pLNode q;
	while (scanf("%d", &n) != EOF)
	{
		List_Insert_pTail(&phead, &ptail, n);
	}
	pcur = phead;
	while (pcur)//外层循环，遍历链表
	{
		pre = pcur;
		pnext = pcur->next;//得到下一个节点
		while (pnext)//内层循环，将当前节点与后面的每一个节点进行比较；一直遍历到最后，查看是否有相同节点
		{
			if (pcur->val == pnext->val)
			{
				pre->next = pnext->next;
			}
			else
			{
				pre = pnext;//当前节点无相同值的节点，开始进行下一个的比较
			}
			pnext = pnext->next;
		}
		pcur = pcur->next;
	}
	List_Print(phead);
	system("pause");
	return 0;
}