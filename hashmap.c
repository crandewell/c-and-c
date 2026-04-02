#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//定义链表节点（存储key——value值）
typedef struct Node
{
	char* key;//键-字符串
	int value;//值-整数
	struct Node* next;//指向下一个节点的指针
	
}Node;

//定义哈希表的结构
typedef struct HashTable
{
	Node** buckets;//桶数组，每个元素是一个链表的头指针
	int size;//桶的大小，哈希表的大小--key-value个数？
	int count;//当前存储的元素个数
	
}HashTable;

//哈希函数:将字符串key映射成0-size-1的整数
unsigned int hash(const char*key,int size)
{
	unsigned long h=5381;//这是什么意思
	int c;
	while((c=*key++))//依次取出字符串中的每个字符-\0结束
	{
		h=((h<<5)+h)+c;//左移五位就是乘个32，加上自身33--再加当前字符的ASCII值
	}//最终h%size作为下标
	return h%size;
}

//创建哈希表
HashTable* createHashTable(int size)
{
	HashTable* ht=(HashTable*)malloc(sizeof(HashTable));
	if(!ht)return NULL;
	ht->size=size;
	ht->count=0;
	ht->buckets=(Node**)calloc(size,sizeof(Node*));
	
	if(!ht->buckets)
	{
		free(ht);
		return NULL;//这个什么意思
	}
	return ht;
}

//插入key-value,若是存在键则更新值
void insert(HashTable* ht,const char* key,int value)
{
	if(!ht||!key)return;
	
	int idx=hash(key,ht->size);
	
	Node* p=ht->buckets[idx];
	//先查找是否存在相同的键
	while(p)
	{
		if(strcmp(p->key,key)==0)
		{
			p->value=value;//有则改，无则加
			return;
		}
		p=p->next;
	}
	
	//不存在则创建新的节点并且插入链表的头部
	Node* newNode=(Node*)malloc(sizeof(Node));
	if(!newNode)return;
	newNode->key=(char*)malloc(strlen(key)+1);
	
	if(!newNode->key)//---->实则为空则执行
	{
		free(newNode);
		return;
	}
	
	strcpy(newNode->key,key);//strcpy也是会覆盖的
	newNode->value=value;
	newNode->next=ht->buckets[idx];//---->这一步是什么意思
	ht->buckets[idx]=newNode;//同样的
	ht->count++;
}

//查找键对应的值，找不到返回-1（假设值都是非负整数）-------6
int find(HashTable* ht,const char* key)//传key值，通过找到这个表，然后返回p-value
{
	if(!ht||!key)return -1;
	int idx=hash(key,ht->size);
	Node* p=ht->buckets[idx];//-----这一步,取出了这个值对应的头指针，便于后序通过p来遍历各种操作
	while(p)
	{
		if(strcmp(p->key,key)==0)//相等
		{
			return p->value;
		}
		p=p->next;
	}
	return -1;
}

//删除key-value 成功返回1失败返回0
int delete(HashTable* ht,const char* key)//const修饰*key key可动，*key不可动---这里的用处
{
	if(!ht||!key)return 0;
	int idx=hash(key,ht->size);
	Node* p=ht->buckets[idx];
	Node* prev=NULL;
	while(p)
	{
		if(strcmp(p->key,key)==0)//这个删除的也要分情况
		{
			if(prev==NULL)
			{
				//删除的是链表头
				ht->buckets[idx]=p->next;
			}
			else
			{
				prev->next=p->next;
			}
			free(p->key);
			free(p);//这个属于临时取出的东西
			ht->count--;
			return 1;
		}
		prev=p;
		p=p->next;
	}
	return 0;
}

//打印整个哈希表用来调试
void printHashTable(HashTable* ht)
{
	if(!ht)return;
	
	printf("哈希表的大小:%d,元素的个数:%d\n",ht->size,ht->count);
	for(int i=0;i<ht->size;i++)
	{
		printf("bucket[%d]: ",i);
		Node* p=ht->buckets[i];
		
		while(p)
		{
			printf("%s,%d",p->key,p->value);
			p=p->next;
		}
		printf("\n");
	}
}

//释放哈希表的内存
void freeHashTable(HashTable* ht)
{
	if(!ht)return;
	for(int i=0;i<ht->size;i++)
	{
		Node* p=ht->buckets[i];
		
		while(p)
		{
			Node* tmp=p;
			p=p->next;
			free(tmp->key);
			free(tmp);//要注意释放的顺序
		}
	}
	free(ht->buckets);
	free(ht);
}

//测试程序
int main()
{
	//创建大小为7的哈希表
	HashTable* ht=createHashTable(7);//质数可以减少冲突
	
	insert(ht,"apple",10);
	insert(ht,"banana",20);
	insert(ht,"orange",30);
	insert(ht,"grape",40);
	insert(ht,"apple",15);//更新apple的值
	
	printHashTable(ht);
	
	printf("查找 apple: %d\n", find(ht, "apple"));   // 15
	printf("查找 banana: %d\n", find(ht, "banana")); // 20
	printf("查找 pear: %d\n", find(ht, "pear"));     // -1
	
	delete(ht,"banana");
	printf("\n删除banana 后:\n");
	printHashTable(ht);
	freeHashTable(ht);
	
	return 0;
}
