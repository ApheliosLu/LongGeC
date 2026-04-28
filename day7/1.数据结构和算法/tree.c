#include"tree.h"

void pre_order(pTNode tree)//前序遍历打印二叉树
{
	if (tree)//先判断是否为空
	{
		putchar(tree->c);
		pre_order(tree->pleft);
		pre_order(tree->pright);
	}
}

void mid_order(pTNode tree)//中序
{
	if (tree)//先判断是否为空
	{
		mid_order(tree->pleft);
		putchar(tree->c);
		mid_order(tree->pright);
	}
}

void lat_order(pTNode tree)//后序
{
	if (tree)//先判断是否为空
	{
		lat_order(tree->pleft);
		lat_order(tree->pright);
		putchar(tree->c);
	}
}

//传入参数：二级指针树根tt_root（因为树根会改变，所以要传入树根的地址）；二级指针类型的队列头尾指针；插入的值val
void build_binary_tree(pTNode* tt_root, pQueue_t* qhead, pQueue_t* qtail, char val)
{
	pTNode tree_new = (pTNode)calloc(1, sizeof(TNode));//为树新生成的结点申请空间
	tree_new->c = val;//将新插入的数据赋给新的结点
	pQueue_t que_new = (pQueue_t)calloc(1, sizeof(Queue_t));//为辅助队列的新结点申请空间
	pTNode pcur = NULL;//定义pcur，指向要插入的元素结点，给哪个元素结点放孩子
	pQueue_t qcur = NULL;
	que_new->insert_Pos = tree_new;//将每一次新生成的树的结点的地址（系一级指针类型的pTNode tree_new)赋给辅助队列的新结点；以记录二叉树结点的地址
	//判断树是否为空
	if (!*tt_root)//对树根的地址取反，表示树为空
	{
		*tt_root = tree_new;//新结点赋成树根
		*qhead = *qtail = que_new;//辅助队列的“新结点的地址”赋给队列的头尾结点
	}
	else {//树不为空时，此时相当于要将“B”放入队列中了
		(*qtail)->pNext = que_new;//将que_new赋给队列原尾指针的pNext项
		*qtail = que_new;//成为新的尾指针，即通过尾插法将新结点放入队列尾
		pcur = (*qhead)->insert_Pos;
		if (NULL == pcur->pleft)//(*qhead)->insert_Pos为树新生成的结点的地址，例子中为“A的地址”
		{
			pcur->pleft = tree_new;//pcur（即队列的头指针中存储的树的结点的地址）指向的左结点的地址pleft，将树新生成的结点赋予其
		}
		else if (NULL == pcur->pright)
		{
			pcur->pright = tree_new;//左子结点不为空则放右子结点
			//树某个结点左右子节点都有了之后，出队（列）
			qcur = *qhead;//保存头部
			*qhead = qcur->pNext;//队列头指针指向下一个，这时准备处理“C”的插入
			free(qcur);//处理掉A
			qcur = NULL;//树的某个结点满了之后，让队列往后移动并free掉前面队列的结点，只使用qhead来插入
		}
	}
}
