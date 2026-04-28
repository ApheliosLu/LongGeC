#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 5
typedef struct student//定义一个结构体变量类型STU
{
	int stuID;
	char name[20];
	double score[3];
}STU;
void Print_Info(STU*);//对打印函数的声明，传入STU*即结构体变量STU的的地址（即该变量的指针）
void print_RankstuID(STU*);//（1）按照学号递增顺序输出全部学生的信息
void Print_MaxScoreOfOne(STU*);//（2）输出每门课程最高分的学生的信息
void print_AvegerScore(STU*);//（3）输出每门课程的平均分
void print_RankOfTotal(STU*);//（4）按照总分输出学生排名
int main()
{
	STU stus[5];//定义STU类型的变量stus的数组
	int i = 0;
	for (; i < 5; i++)//输入五名学生的数据
	{
		scanf("%d%s%lf%lf%lf", &stus[i].stuID, stus[i].name, &stus[i].score[0], &stus[i].score[1], &stus[i].score[2]);
		//?上行使用scanf_s会中断
	}
	print_RankstuID(stus);//（1）按照学号递增顺序输出全部学生的信息
	printf("------------------------------------------------------\n");
	Print_MaxScoreOfOne(stus);//（2）输出每门课程最高分的学生的信息
	printf("------------------------------------------------------\n");
	print_AvegerScore(stus);//（3）输出每门课程的平均分
	printf("------------------------------------------------------\n");
	print_RankOfTotal(stus);//（4）按照总分输出学生排名
	printf("------------------------------------------------------\n");
	system("pause");
	return 0;
}

//打印学生信息
void Print_Info(STU*stus)
{
	int i = 0;
	for (; i < N; i++)
	{
		printf("学号：%d    姓名：%s    分数1：%5.2f    分数2：%5.2f    分数3：%5.2f    总分：%5.2f\n", stus[i].stuID,
			stus[i].name, stus[i].score[0], stus[i].score[1], stus[i].score[2], stus[i].score[0] + stus[i].score[1] + stus[i].score[2]);
	}
}

//（1）按照学号递增顺序输出全部学生的信息
void print_RankstuID(STU*stus)
{
	int i = 0,j = 0;//冒泡法排序
	for (i = N; i > 0; i--)//外层控制无序数的数量；一共比较五个无序量“学号”，最终输出无论信息
	{
		for (j = 0; j < i - 1; j++)//内层控制比较；五个量进行比较，最大处为j=3 j+1=4
		{
			if (stus[j].stuID > stus[j + 1].stuID)//大的放后面，从小到大排序
			{
				STU s = stus[j];
				stus[j] = stus[j + 1];
				stus[j + 1] = s;
			}
		}
	}
	printf("按照学生的学号排序如下：\n");
	Print_Info(stus);//传入实参stus，类型是结构体数组，本身带有地址；与形参STU*stus级别相同
}

//（2）输出每门课程最高分的学生的信息
void Print_MaxScoreOfOne(STU*stus)
{
	STU* s;//定义一个结构体指针s
	int i = 0, j = 0;
	for (i = 0; i < 3; i++)//三个无序量“三门课程”；最终输出三轮信息
	{
		s = &stus[0];//认为第1个是最大的，让s始终指向最大的
		printf("课程%d最高分的学生信息为：\n", i + 1);//?
		for (j = 0; j < N; j++)//内层真正进行五个学生的每一门课程成绩的比较
		{
			if (stus[j].score[i] > s->score[i])
			{
				s = &stus[j];
			}
		}
		printf("学号：%d   姓名：%s   分数1：%5.2lf  分数2：%5.2lf   分数3：%5.2lf总分：%5.2lf\n",
			s->stuID, s->name, s->score[0], s->score[1], s->score[2], s->score[0] + s->score[1] + s->score[2]);
	}
}

//（3）输出每门课程的平均分
void print_AvegerScore(STU*stus)
{
	int i = 0, j = 0;
	double ave = 0;
	for (i = 0; i < 3; i++)//输出三轮信息，即三门课程的每一个平均分
	{
		ave = 0;
		for (j = 0; j < N; j++)
		{
			ave += stus[j].score[i];
		}
		ave /= N;
		printf("课程%d的平均分为%5.2lf\n", i + 1, ave);
	}
}

//（4）按照总分输出学生排名
void print_RankOfTotal(STU*stus)
{
	int i = 0, j = 0;
	for (i = 0; i < N - 1; i++)//控制比较轮数,四轮，stus[3]和stus[4]比是最后一轮
	{
		for (j = 0; j < N - 1 - i; j++)
		{
			if (stus[j].score[0] + stus[j].score[1] + stus[j].score[2] <
				stus[j + 1].score[0] + stus[j + 1].score[1] + stus[j + 1].score[2])
			{
				STU s = stus[j];
				stus[j] = stus[j + 1];
				stus[j + 1]=s;
			}
		}
	}
	printf("按照学生的总分排名如下：\n");
	Print_Info(stus);
}