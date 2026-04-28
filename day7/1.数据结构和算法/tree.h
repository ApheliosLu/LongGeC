#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	char c;
	struct node* pleft;
	struct node* pright;
}TNode,*pTNode;

typedef struct queue_t {//定义辅助队列
	pTNode insert_Pos;//辅助队列里存储二叉树结点的指针地址，以快速确定树中的结点
	struct queue_t* pNext;//存储辅助队列里每一项指向的下一项的位置
}Queue_t,*pQueue_t;//辅助队列的缩写名以及对应类型的指针


void pre_order(pTNode tree);
void mid_order(pTNode tree);
void lat_order(pTNode tree);
void build_binary_tree(pTNode* tt_root, pQueue_t* qhead, pQueue_t* qtail, char val);