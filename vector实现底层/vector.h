#pragma once

#ifndef VECTOR_H
#define VECTOR_H
#include<stddef.h>

typedef struct
{
	int* data;
	size_t capacity;
	size_t size;

}Vector;
//创建并初始化一个空的vector
Vector* vector_create(void);

//销毁并且释放内存
void vector_destory(Vector* vec);

//尾部插入元素
int vector_push_back(Vector* vec,int value);

//删除尾部元素
int vector_pop_back(Vector* vec);

//在指定索引位置插入元素（索引从0开始）
int vector_insert(Vector* vec,size_t index,int value);

//删除指定位置的索引
int vector_erase(Vector* vec,size_t index);

//在索引位置插入元素
int vector_insert(Vector* vec, size_t index,int value);//通过指针传出来避免返回内部指针--hyw

//删除指定索引位置的元素
int vector_erase(Vector* vec,size_t index);

//获取指定索引位置的元素
int vector_at(const Vector* vec,size_t index,int* out);//传出避免这是什么意思

//修改指定索引位置的元素值
size_t vector_size(const Vector* vec);

//返回当前数组中的元素个数
size_tvector_capacity(const Vector* vec);

//判断vector是否为空
int vector_empty(const Vector* vec);


#endif
//VECTOR_H

