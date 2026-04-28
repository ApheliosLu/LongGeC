#include"queue.h"

void InitQueue(SqQueue* q)//队列的初始化
{
	q->front = q->rear = 0;//队列头尾都指向数组的0号元素
}

void EnQueue(SqQueue* q, ElemType1 val)//入队，传入参数：队列指针q以及入队的值基础类型的val
{
	//判断循环队列是否满了
	if ((q->rear + 1) % MaxSize == q->front)//若相等则说明队列满了
	{
		printf("sq is full\n");//打印队列已经满了
	}
	q->data[q->rear] = val;//将数据放在q的数组data项里的rear元素位置
	q->rear = (q->rear + 1) % MaxSize;//入队后，对队尾加一后取余，取余的目的是因为要考虑循环的问题
}

int DeQueue(SqQueue* q)
{
	ElemType1 val;
	//出队时，先判断队列是否为空
	if (q->front=q->rear)//若rear与front相等，则代表循环队列为空；不为空时，头和尾之间至少相隔一个元素
		//!注意此处必须是front和rear相比较
	{
		printf("sq is empty\n");
		return;//没有元素，return
	}
	val = q->data[q->front];//将队列q的data项内包含的front即队列头元素的位置，赋予val
	q->front = (q->front + 1) % MaxSize;//与入队时类似，入队时rear+1后移一位，出队时front+1后移一位，均要取余以确保数组的下标仍在0~4内
	return val;//返回要打印输出的val
}