#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node
{
	char num;//每位以字符形式存储
	struct Node* next;//携带的一级指针地址*next
}LNode, * pLNode;//缩写LNode和一级指针*pLNode

//头插法新建链表
void list_head_insert(pLNode* head, pLNode* tail, char num)
{
	pLNode pnew = (pLNode)malloc(sizeof(LNode));
	memset(pnew, 0, sizeof(LNode));
	pnew->num = num;
	if (*head == NULL)
	{
		*head = pnew;
		*tail = pnew;
	}
	else {
		pnew->next = *head;
		*head = pnew;
	}
}

//链表打印
void lprint(pLNode head)
{
	while (head != NULL)
	{
		printf("%c", head->num);
		head = head->next;
	}
	printf("\n");
}

//针对in1节点和in2节点做加法，注意是字符加法，返回值代表是否有进位
//in1和in2分别为两个链表的头部
int add_list_head(pLNode* head, pLNode* tail, pLNode in1, pLNode in2)//？*head和in1，一个加*一个不加
{
	int flag = 0;
	pLNode pnew = (pLNode)malloc(sizeof(LNode));
	memset(pnew, 0, sizeof(LNode));
	//?通过条件表达式来判断是减去0，还是减去字符'0'
	pnew->num = in1->num  + in2->num + '0' - (in1->num >= '0' ? '0' : 0) - (in2->num >= '0' ? '0' : 0) ;
	//???in1的位数小于in2时报错
	//大于9，就进位
	if (pnew->num > '9')
	{
		pnew->num -= 10;
		flag = 1;//进位
	}
	else {
		flag = 0;
	}
	//头插法新建结果链表
	if (*head == NULL)
	{
		*head = pnew;
		*tail = pnew;
	}
	else {
		pnew->next = *head;
		*head = pnew;
	}
	return flag;//返回值代表是否有进位
}

void main()
{
	char n;
	int i = 0, ret = 0;
	//结构体指针有3个元素，分别为3个链表的头尾指针
	//head[0]，head[1]系记录输入元素的两个链表，head[2]记录最终结果
	pLNode head[3] = { NULL }, tail[3] = { NULL }, p = (pLNode)malloc(sizeof(LNode));
	p->num = 0; p->next = NULL;
	for (i = 0; i < 2; i++)//输入两个链表的元素
	{
		printf("input the %d num\n", i + 1);
		while ((n = getchar()) != '\n')
		{
			list_head_insert(&head[i], &tail[i], n);
		}
	}
	while (head[0] != NULL || head[1] != NULL)//链表0和1有一者不为空时
	{
		ret = 0;
		//如果head[0]链表已经没有节点，就放入节点p，p的val设置为数值0
		if (head[0] == NULL)
		{
			ret = add_list_head(&head[2], &tail[2], head[1], p);//ret代表add函数的返回值，是否进位
			head[1] = head[1]->next;
			//如果进位，就先加到head[0]链表
			if (ret == 1)
			{
				if (head[0] == NULL)
				{
					list_head_insert(&head[0], &tail[0], '1');//?给head[0]中加入每一位元素加入'1'
				}
				else {
					head[0]->num += 1;
				}
			}
		}
		//如果head[1]链表已经没有节点，就放入节点p，p的val设置为数值0
		else if (head[1] == NULL)
		{
			ret = add_list_head(&head[2], &tail[2], head[0], p);//?p代表什么
			head[0] = head[0]->next;
			//如果进位，就先加到head[0]链表
			if (ret == 1)//?ret代表什么
			{
				if (head[0] == NULL)
				{
					list_head_insert(&head[0], &tail[0], '1');//?给head[0]中加入每一位元素加入'1'
				}
				else {
					head[0]->num += 1;
				}
			}
		}
		else {//head[0],[1]都有节点，利用add函数进行加和
			ret = add_list_head(&head[2], &tail[2], head[0], head[1]);
			head[0] = head[0]->next;
			head[1] = head[1]->next;
			//如果进位，就先加到head[0]链表
			if (ret == 1)//ret==1代表进位
			{
				if (head[0] == NULL)
				{
					list_head_insert(&head[0], &tail[0], '1');
				}
				else {
					head[0]->num += 1;
				}
			}
		}
	}
	printf("result=");
	lprint(head[2]);
	system("pause");
	return 0;
}
