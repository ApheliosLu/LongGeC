#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUCKETCOUNT 50 //先默认定义50个桶
struct hashEntry
{
	char* key;
	int value;
	struct hashEntry* next;
};
typedef struct hashEntry entry;

struct hashTable
{
	entry bucket[BUCKETCOUNT];  
};
typedef struct hashTable HashTable;

//散列函数
static unsigned int hash_33(char* key);

//初始化哈希表
void hash_table_init(HashTable *ht);

//删除
void hash_table_delete(HashTable* ht);

//根据key存入
int hash_table_put(HashTable* ht,   char* key);

//根据Key获取value
int hash_table_get(HashTable* ht,   char* key);

//根据key删除
void hash_table_rm(HashTable* ht,   char* key);

//查看是否为空
int hash_table_is_empty(HashTable *ht);