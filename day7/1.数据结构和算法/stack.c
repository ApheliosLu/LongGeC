#include"stack.h"

void init_stack(pStack s)
{
	memset(s, 0, sizeof(Stack));//初始化：既对s->phead=NULL,也对s->size=0
}

void push(pStack s, ElemType val)//一级指针（pStack栈指针类型)s，通过s->phead即可访问栈的头指针（无需二级指针）
{   //1.申请空间
	pNode pnew = (pNode)calloc(1, sizeof(Node));//申请一个节点大小的空间
	pnew->m_val = val;//将传入的val赋值给pnew的m_val项
	//2.判断链表是否为空
	if (!s->phead)//若链表的头指针(s->phead)不存在(为真）,即栈为空
	{
		s->phead = pnew;//将新插入的pnew赋为链表头
	}
	else {//若链表不为空
		pnew->next = s->phead;//pnew指向原本的头即s->phead
		s->phead = pnew;//使pnew成为新的头
	}
	s->size++;//放入元素后，栈的元素（大小）加1
}

ElemType top(pStack s)//返回栈顶元素，不弹出
{
	return s->phead->m_val;//返回栈的头指针（即栈顶）的m_val项
}

void pop(pStack s)
{
	//判断栈是否为空，再弹栈
	pNode pcur = s->phead;//定义一个pcur，赋予栈的头指针
	if(!s->size)//s->size=0即栈为空，此时s->size为假，!s->size为真
	{
		printf("stack is empty\n");
		return;//不弹
	}
	//return之后，无需else判断
	s->phead = pcur->next;//原本栈内存储的头指针phead，现在变为原头指针指向的next项的指针
	s->size--;//size减一
	free(pcur);//free掉pcur
}

int empty(pStack s)
{
	return !s->size;
}

int stack_size(pStack s)
{
	return s->size;
}