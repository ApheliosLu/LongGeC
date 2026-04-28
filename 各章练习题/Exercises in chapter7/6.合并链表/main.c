#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node //定义一个结构体类型Node
{
	int val;//内包含一个整型val
	struct Node* next;//一个指针next
}LNode, * pLNode;//缩写成LNode和*pLNode；*pLNode等价于struct Node*,系一级指针

//有序插入新建链表
void List_Insert_pSort(pLNode* p_head, pLNode* p_tail, int n)//传入三个形参，两个一级指针和一个整型变量
{
	pLNode s = (pLNode)malloc(sizeof(LNode));//定义一个pLNode类型的一级指针s
	pLNode pre = *p_head, pcur = *p_head;//新定义两个一级指针，将链表头的地址*p_head赋予他们
	memset(s, 0, sizeof(LNode));
	s->val = n;//n作为s的val项
	if (*p_head == NULL)//1.若链表头为空，既成为新的头又成为新的尾
	{
		*p_head = s;//则按照有序插入法新插入的节点s作为新的链表头、尾
		*p_tail = s;
	}
	//从小到大排列，链表头不为空
	else if (n <= (*p_head)->val)//2.插入头部
	{
		s->next = *p_head;
		*p_head = s;//s作为新的头
	}
	else
	{
		while (pcur != NULL)//若头不为空，3.插入中间时
		{
			if (pcur->val > n)
			{
				s->next = pcur;//s链接到pcur前
				pre->next = s;//pre链接到s前
				break;//break
			}
			pre = pcur;
			pcur = pcur->next;
		}
		if (pcur == NULL)//一直遍历完整个链表，4.插入到尾部
		{
			pre->next = s;
			*p_tail = s;
		}
	}
}

void Merge_list(pLNode* phead, pLNode* ptail, pLNode* head1, pLNode* head2)//phead,ptail代表两个链表链接后的新头和新尾
{
	pLNode p1 = *head1;//*head1,2分别代表原有的两个链表的两个头
	pLNode p2 = *head2;
	while (p1 != NULL && p2 != NULL)//原来的两个头不为空
	{
		if (*phead == NULL)//合并的链表头为空，说明还未放入第一个节点
		{
			if (p1->val > p2->val)//若链表1的头大于链表2的头，则将链表2的头作为新链表的头（从小到大排序）
			{
				*phead = p2;
				p2 = p2->next;//头部删除法，将原有的链表2的头删去
				(*phead)->next = NULL;
				*ptail = *phead;//头尾一体
			}
			else
			{
				*phead = p1;//否则链表1的头作为新的头
				p1 = p1->next;
				(*phead)->next = NULL;
				*ptail = *phead;
			}
		}
		else//链表头不为空，已经放入第一个节点后
		{
			if (p1->val >= p2->val)//p1的val大于等于p2的val
			{
				(*ptail)->next = p2;//新链表采用尾插法
				*ptail = p2;
				p2 = p2->next;////头部删除法，往后遍历
			}
			else
			{
				(*ptail)->next = p1;
				*ptail = p1;
				p1 = p1->next;
			}
		}
	}
	if (p1)//若1号链表还存在剩余节点，就附到新链表尾部
	{
		(*ptail)->next = p1;
		while (p1->next)
		{
			p1 = p1->next;
		}
		*ptail = p1;
	}
	if (p2)//若2号链表还存在剩余节点，就附到新链表尾部
	{
		(*ptail)->next = p2;
		while (p2->next)
		{
			p2 = p2->next;
		}
		*ptail = p2;
	}
}

void Print_List(pLNode* phead)
{
	pLNode pcur = *phead;
	while (pcur)
	{
		printf("%3d", pcur->val);
		pcur = pcur->next;
	}
	printf("\n");
}

int main()
{
	int n;
	pLNode p1_head = NULL, p1_tail = NULL;//两个原链表和新链表的初始化
	pLNode p2_head = NULL, p2_tail = NULL;
	pLNode phead = NULL, ptail = NULL;
	while (scanf("%d", &n) != EOF)
	{
		List_Insert_pSort(&p1_head, &p1_tail, n);//按照有序插入法对链表1进行排序插入
	}
	printf("链表1如下：\n");
	Print_List(&p1_head);//打印链表1
	while (scanf("%d", &n) != EOF)
	{
		List_Insert_pSort(&p2_head, &p2_tail, n);//按照有序插入法对链表1进行排序插入
	}
	printf("链表2如下：\n");
	Print_List(&p2_head);//打印链表2
	printf("链表1和链表2合并后如下：\n");
	Merge_list(&phead, &ptail, &p1_head, &p2_head);//传入地址，相当于一级指针
	Print_List(&phead);
	system("pause");
	return 0;
}