#include"stack.h"
#include"queue.h"
#include"tree.h"

void use_stack()//栈部分
{
	//先定义一个栈，栈很小时无需malloc堆空间，直接使用栈空间即可
	Stack s;//定义一个栈
	init_stack(&s);//传入实参栈“s的地址”&s，对其进行初始化
	push(&s, 2);
	push(&s, 3);
	printf("stack size=%d\n", stack_size(&s));
	printf("%d\n", top(&s));//返回3
	pop(&s);
	printf("%d\n", top(&s));//返回2
	printf("%d\n", empty(&s));//判断栈是否为空;返回0即假，说明不为空
}

void use_sq()//队列部分
{
	SqQueue q;//定义一个队列
	InitQueue(&q);
	EnQueue(&q, 1);
	EnQueue(&q, 2);
	EnQueue(&q, 3);
	EnQueue(&q, 4);
	EnQueue(&q, 5);//打印sq is full
	printf("出队元素 %d\n",DeQueue(&q));//打印1
}

#define N 10
void build_tree()//（用数组队列）建二叉树
{
	pTNode tree_root=NULL;//定义一个pTNode(二叉树结点指针类型的变量，树根tree_root);赋NULL，初始化二叉树，无结点
	char c[N + 1] = "ABCDEFGHIJ";
	pTNode p[N + 1];//定义一个（二叉树节点类型的）指针数组队列，用于申请和分配空间；与之前使用的各种链表队列对应;辅助（数组）队列
	int i,j;
	for (i = 0; i < N; i++)//建立一个循环，为树的每一个节点，利用指针数组队列（相当于半个辅助队列）来申请和分配空间
	{
		p[i] = (pTNode)calloc(1, sizeof(TNode));//申请空间
		p[i]->c = c[i];//申请空间后，将对应的元素值填入
	}
	for (i = 0; i < N; i++)//利用循环，把结点放到树上
	{
		//判断树是否为空，利用树根是否为NULL来判断
		if (NULL == tree_root)//如果树为空
		{
			tree_root = p[i];
			j = 0;//写成j=i亦可
		}
		else {//j始终记录当前要插入的结点
			if (NULL == p[j]->pleft)//先判断要插入的节点j的左子结点是否为空
			{
				p[j]->pleft = p[i];
			}else if(NULL == p[j]->pright)
			{
				p[j]->pright = p[i];
				j++;
			}
		}
	}
	//原则：子节点要与自己的父结点相邻，一层一层写
	pre_order(tree_root);//先序遍历，输出ABDHIEJCFG
	printf("\n----------------------------\n");
	mid_order(tree_root);//中序，输出HDIBJEAFCG（将树踩平，从左到右写）
	printf("\n----------------------------\n");
	lat_order(tree_root);//后序，输出HIDJEBFGCA
	printf("\n");
}

void use_new_tree()//元素个数不限的二叉树
{
	pTNode tree_root = NULL;
	char c;
	pQueue_t que_head=NULL, que_tail=NULL;//定义辅助队列的头尾指针
	while (scanf("%c", &c) != EOF)
	{
		if (c == '\n')//scanf到\n时break
			break;
		build_binary_tree(&tree_root, &que_head, &que_tail, c);
	}
	pre_order(tree_root);//先序遍历，输出ABDHIEJCFG
	printf("\n----------------------------\n");
	mid_order(tree_root);//中序，输出HDIBJEAFCG（将树踩平，从左到右写）
	printf("\n----------------------------\n");
	lat_order(tree_root);//后序，输出HIDJEBFGCA
	printf("\n");
}

int main()
{
	//use_stack();//栈部分
	//use_sq();//队列部分
	//build_tree();//（用数组队列）建二叉树
	//use_new_tree();//元素个数不限的二叉树

	system("pause");
}