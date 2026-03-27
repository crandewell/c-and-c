#include<stdio.h>
#include<stdlib.h>//malloc realloc free
#include<string.h>
#include<stddef.h>
#include"vector.h"
//初始容量
#define INIT_CAPACITY 10

//扩容因子--工业常用二倍扩容
#define GROWTH_FACTOR 2

//创建vector
Vector *vector_create(void)
{
	//申请Vector结构体的内存
	Vector* vec = (Vector*)malloc(sizeof(Vector));//malloc 此处的意义
	if (vec == NULL)
	{
		return NULL;//判断是否为空从而分辨是否内存分配失败了
	}
	//申请数据存储空间（堆区）
	vec->data = (int*)malloc(INIT_CAPACITY * sizeof(int));//malloc 的语法复习
	if (vec->data == NULL)
	{
		free(vec);
		return NULL;
	}
	vec->capacity = INIT_CAPACITY;
	vec->size = 0;
	return vec;
}

//销毁vector
void vector_destroy(Vector* vec)
{
	if (vec == NULL)
		return;
	if (vec->data != NULL)
	{
		free(vec->data);
	}
	free(vec);
}

//内部扩容函数--静态辅助函数
static int expand_capacity(Vector* vec)
{
	if (vec == NULL)return -1;
	size_t new_capacity = vec->capacity * GROWTH_FACTOR;
	//realloc 返回新地址或者是原地扩容
	int* new_data = (int*)realloc(vec->data, new_capacity * sizeof(int));
	if (new_data == NULL)
	{
		return -1;//失败扩容但是原本数据依旧有效
	}
	vec->data = new_data;
	vec->capacity = new_capacity;
	return 0;
}

//尾部插入元素
int vector_push_back(Vector* vec, int value)
{
	if (vec == NULL)return -1;
	if (vec->size = vec->capacity)//已有的容量和上限一致
	{
		if (expand_capacity(vec) != 0)
		{
			return -1;//扩容失败
		}
	}
	vec->data[vec->size] = value;//这句是什么意思
	vec->size++;
	return 0;
}

//在指定位置插入元素(索引从0开始)
int vector_insert(Vector* vec, size_t index, int value)
{
	if (vec == NULL)return -1;
	if (index >= vec->size)
	{
		if (expand_capacity(vec) != 0)
		{
			return -1;
		}
	}
	//将index 以及之后的元素向后移动一位
	if (index < vec->size)
	{
		memmove(&vec->data[index + 1], &vec->data[index], (vec->size - index) * sizeof(int));//这个函数是什么意思
	}
	vec->data[index] = value;
	vec->size++;
	return 0;
}

//删除指定位置的元素
int vector_erase(Vector* vec, size_t index,int *out)
{
	if (vec == NULL || vec->size == 0)return -1;
	if (index >= vec->size)return -1;
	//将index+1以及之后的元素向前移动一位
	if (index < vec->size - 1)
	{
		memmove(&vec->data[index], &vec->data[index + 1], (vec->size - index - 1) * sizeof(int));
	}
	vec->size--;
	return 0;
}

//获取指定索引位置的元素值
int vector_at(const Vector* vec, size_t index, int* out)//这个out传出究竟有啥作用
{
	if (vec == NULL || out == NULL)return -1;
	if (index >= vec->size)return -1;
	*out = vec->data[index];
	return 0;
}

//修改指定索引位置的元素值
int vector_set(Vector* vec, size_t index, int value)
{
	if (vec == NULL)return -1;
	if (index >= vec->size)return -1;
	vec->data[index] = value;
	return 0;
}
//返回元素个数
size_t vector_size(const Vector* vec)
{
	return vec ? vec->size : 0;//三目运算符更好
}
//返回容量
size_t vector_capacity(const Vector* vec)
{
	return vec ? vec->capacity : 0;
}
//判断是否为空
int vector_empty(const Vector* vec)
{
	return vec ? (vec->size == 0) : 1;
}























