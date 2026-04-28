#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	char c;
	struct node* left;//指向左边的结点
	struct node* right;
}BinaryTreeNode,*pBinaryTreeNode;

void MirrorRecursively(pBinaryTreeNode pNode)//用于调换二叉树每个结点的左右子结点的递归函数;传入一级指针pNode
{
	BinaryTreeNode* pTemp;//建立临时结点，用于交换左右子结点
	if (pNode == NULL)
		return;
	if (pNode->left == NULL && pNode->right == NULL)
		return;
	pTemp = pNode->left;//当前元素的左右子结点调换
	pNode->left = pNode->right;
	pNode->right = pTemp;
	if (pNode->left)//如果左边节点为真，调换左边
		MirrorRecursively(pNode->left);//递归
	if (pNode->right)
		MirrorRecursively(pNode->right);
}

//通过中序遍历，刚好打印树从左到右，这样镜像的结果就是逆序
void midOrder(pBinaryTreeNode p)
{
	if (p)
	{
		midOrder(p->left);//
		putchar(p->c);
		midOrder(p->right);
	}
}

#define N 7
int main()
{
	char c[N + 1] = "4261357";
	int i, j;
	pBinaryTreeNode p[N];//指针数组
	pBinaryTreeNode tree;
	for (i = 0; i < N; i++)
	{
		p[i] = (pBinaryTreeNode)calloc(1, sizeof(BinaryTreeNode));
		p[i]->c = c[i];//将c[i]的值放到对应的p[i]的c项中
	}
	tree = p[0];//树根结点的指针tree
	j = 0;//j用来记录元素将要放到哪个结点
	for (i = 1; i < N; i++)//循环实现层次建树
	{
		if (p[j]->left == NULL)
		{
			p[j]->left = p[i];
		}
		else if (p[j]->right == NULL)
		{
			p[j]->right = p[i];
			j++;
		}
	}
	printf("调换前\n");
	midOrder(tree);
	printf("\n-------\n");
	MirrorRecursively(tree);
	printf("调换后\n");
	midOrder(tree);
	printf("\n");
	system("pause");
}