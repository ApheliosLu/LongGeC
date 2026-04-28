#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 3
typedef struct student
{
	char id[10];
	char name[10];
	char sex[6];
	int score[3], sum;
	struct Student* next;
}student, * pstu;

//有序插入新建链表
void list_sort_insert(pstu *head, pstu* tail, pstu stu)//???全为一级指针类型
{
	pstu pcur;
	pstu ppre;
	pstu pnew;
	pnew = (pstu)malloc(sizeof(student));
	memset(pnew, 0, sizeof(student));
	pnew = stu;//传入的stu赋给pnew
	pcur = *head;
	ppre = *head;
	if (NULL == pcur)//判断链表是否为空
	{
		*head = pnew;
		*tail = pnew;
	}
	else if (pnew->sum > pcur->sum)//判断i大于头部数据，插入头部
	{
		pnew->next = pcur;//原有链表的头指针赋给新结点的next
		*head = pnew;//新结点变为链表头部
	}
	else {
		while (pcur != NULL)//插入中间
		{
			if (pnew->sum - pcur->sum > 0)
			{
				ppre->next = pnew;//
				pnew->next = pcur;
				break;
			}
			ppre = pcur;//前指针先赋给后指针.直至满足上述if条件
			pcur = pcur->next;
		}
		if (NULL == pcur)//未插到中间，就是插入尾部
		{
			(*tail)->next = pnew;//将新结点的地址赋给尾结点的next
			*tail = pnew;//新结点变为尾指针
		}
	}
}

//将链表内容写入文件
void Print(const pstu* head, const char* file_name)
{
	FILE* fp;
	pstu pcur;
	printf("--------------按照总分递减输出全部学生信息--------------\n");
	fp = fopen(file_name, "w+");
	if (fp == NULL)
	{
		perror("fopen");
		fclose(fp);
		return;
	}
	pcur = *head;
	while (pcur != NULL)
	{
		fprintf(fp, "%s\t %s\t %s\t %3d\t %3d\t %3d\n",
			pcur->id, pcur->name, pcur->sex, pcur->score[0],
			pcur->score[1], pcur->score[2], pcur->sum);
		pcur = pcur->next;
	}
	fclose(fp);
}

int main()
{
	const char* file_name = "data.txt";
	FILE* fp;
	pstu head = NULL, tail = NULL;
	student stu[N];
	int i;
	fp = fopen(file_name, "r+");
	if (fp == NULL)
	{
		perror("fopen");
		return 1;
	}
	for (i = 0; i < N; i++)
	{
		fscanf(fp, "%s %s %s %d %d %d", stu[i].id,stu[i].name, stu[i].sex,
			&stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
		stu[i].sum = stu[i].score[0] + stu[i].score[1] + stu[i].score[2];
		stu[i].next = NULL;
		list_sort_insert(&head, &tail, &stu[i]);
	}
	fclose(fp);
	Print(&head, file_name);
	system("pause");
	return 0;
}