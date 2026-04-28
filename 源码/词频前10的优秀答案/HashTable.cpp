#include"HashTable.h"

//计算字符串的哈希值
static unsigned int hash_33(  char* key)
{
	unsigned int hash = 0;
	//用*key遍历字符串key
	while (*key) {
		hash = (hash << 5) + hash + *key++;
	}
	return hash;
}


//初始化哈希表
void hash_table_init(HashTable *t)
{
	if (t == NULL)
		return;
	for (int i = 0; i < BUCKETCOUNT; i++)
	{
		t->bucket[i].key = NULL;
		t->bucket[i].next = NULL;
		t->bucket[i].value = 1;
	}
}


//删除一个节点
void free_entry(entry *kv)
{
	if (kv->key) {
		if (kv->value) {
			kv->value = 1;
		}
		free(kv->key);
		kv->key = NULL;
	}
}

//删除整个表
void hash_table_delete(HashTable* ht)
{
	if (ht) {
		if (ht->bucket) {
			int i = 0;
			for (i = 0; i<BUCKETCOUNT; i++) {
				entry* p =& ht->bucket[i];
				entry* q = NULL;
				while (p) {
					q = p->next;
					free_entry(p);
					p = q;
				}
			}
		}
	}
}

//根据key存入
int hash_table_put(HashTable* ht,   char* key)
{
	if (ht == NULL || key == NULL)
		return -1;
	int index = hash_33(key) % BUCKETCOUNT;
	if (ht->bucket[index].key == NULL)
	{
		ht->bucket[index].key = strdup(key);
		ht->bucket[index].value = 1;
	}
	//冲突
	else
	{
		entry *pcur, *ppre;
		pcur = ppre = &ht->bucket[index];
		//是否是相同key的插入，如果是就更新
		while (pcur)
		{
			if (strcmp(pcur->key, key) == 0) {
				//找到key所在，替换值
				pcur->value ++;
				return index;   //插入完成了
			}
			ppre=pcur;			//当在当前桶里找不到时，pcur空，ppre保存了尾指针
			pcur = pcur->next;
		}
		//没有在当前桶中找到
		//创建条目加入
		pcur = (entry*)malloc(sizeof(entry));
		pcur->key = strdup(key);
		pcur->value = 1;
		pcur->next = NULL;
		ppre->next = pcur;
	}
	return index;
}

//根据Key获取
int hash_table_get(HashTable* ht,   char* key)
{
	int index;
	  entry* e;
	if (ht == NULL || key == NULL) {
		return -1;	
	}
	index = hash_33(key)%BUCKETCOUNT;
	e = &(ht->bucket[index]);
	if (e->key == NULL) return -1;//这个桶还没有元素
	while (e) {
		if (0 == strcmp(key, e->key)) {
			return e->value;    //找到了，返回值
		}
		e = e->next;
	}
	return -1;		//找不到返回空
}

//根据key删除
void hash_table_rm(HashTable* t,  char* key)
{
	int index;
	entry* e, *ep;   //查找的时候，把ep作为返回值
	if (t == NULL || key == NULL) {
		return ;
	}
	index = hash_33(key)%BUCKETCOUNT;
	e = &(t->bucket[index]);
	while (e != NULL) {
		if (0 == strcmp(key, e->key)) {
			//如果是桶的第一个
			if (e == &(t->bucket[index])) {
				//如果这个桶有两个或以上元素
				//交换第一个和第二个，然后移除第二个
				ep = e->next;
				if (ep != NULL) {
					entry tmp = *e; //做浅拷贝交换
					*e = *ep;//相当于链表的头节点已经移除
					*ep = tmp;  //这就是移除下来的链表头节点
					ep->next = NULL;
				}
				else {//这个桶只有第一个元素
					ep = (entry*)malloc(sizeof(entry));
					*ep = *e;
					e->key  = NULL;
					e->value = 1;
					e->next = NULL;
				}
			}
			else {
				//如果不是桶的第一个元素
				//找到它的前一个(这是前面设计不佳导致的多余操作)
				ep = &(t->bucket[index]);
				while (ep->next != e)ep = ep->next;
				//将e从中拿出来
				ep->next = e->next;
				e->next = NULL;
				ep = e;
			}
		}
		e = e->next;
	}
}

//查看是否为空
int hash_table_is_empty(HashTable *ht)
{
	int i;
	for (i = 0; i < BUCKETCOUNT; i++)
	{
		if (ht->bucket[i].key == NULL)
			continue;
		else
			break;
	}
	if (i == BUCKETCOUNT)
		return 1;
	else
		return 0;
}