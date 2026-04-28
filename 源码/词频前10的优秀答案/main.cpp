//统计” The_Holy_Bible_Res.txt “ 中字符的个数，行数，单词的个数，
//统计单词的词频并打印输出词频最高的前 10 个单词及其词频。

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "rbtree.h"
#include "HashTable.h"


#define N 5000
#define WORD_LEN 200


//最右边的结点就是最大的
Node* maximum(RBTree tree)
{
	if (tree == NULL)
		return NULL;

	while (tree->right != NULL)
		tree = tree->right;
	return tree;
}

int main()
{
	FILE *fp;
	HashTable t;
	hash_table_init(&t);
	entry *pnew = NULL;
	char word[WORD_LEN] = { 0 };
	const char *file_name = "The_Holy_Bible_Res.txt";
	fp = fopen(file_name, "r");
	if (fp == NULL)
	{
		perror("fopen");
		exit(1);
	}
	char Buffer[N];
	int count = 0;//字符数
	int line = 0;//行数
	int word_num = 0;//不重复单词数量
	int all_word_num = 0;
	//遍历，建立哈希
	while (fgets(Buffer, sizeof(Buffer), fp) != NULL)
	{
		int i = 0;
		line++;
		while (Buffer[i] != '\0') {
			if (!isalpha(Buffer[i]))
			{
				count++;
				i++;
				continue;
			}
			int j = 0;
			while (isalpha(Buffer[i]))
			{
				count++;
				word[j++] = Buffer[i];
				i++;
			}
			//存入单词到哈希表中
			hash_table_put(&t, word);
			all_word_num++;

			//初始化单词
			if (j > 0)
			{
				memset(word, 0, sizeof(word));
			}
			else
				i++;
		}
	}
	//遍历哈希表进行，放入红黑树，进行排序
	RBRoot *root = NULL;
	root = create_rbtree();
	for (int i = 0; i < BUCKETCOUNT; i++)
	{
		if (t.bucket[i].key != NULL) {
			entry *pcur =&t.bucket[i];
			while (pcur != NULL) {
				insert_rbtree(root, *pcur);
				pcur = pcur->next;
				word_num++;
			}
		}
	}
	printf("字符个数：%d\n", count);
	printf("\n行数：%d\n", line);
	printf("\n总的单词个数：%d\n", all_word_num);
	printf("\n不重复的单词个数：%d\n", word_num);
	printf("\n10个词频最大的单词：\n");
	Node *max = maximum(root->node);
	//在红黑树中找到最大的，打印，打印后删除最大的
	for (int i = 0; i < 10; i++)
	{
		printf("单词：%s\t词频：%d\n", max->key.key, max->key.value);
		rbtree_delete(root, max);
		max = maximum(root->node);
	}
	printf("\n");
	system("pause");
	return 0;
}