#pragma once
#ifndef LINKEDLIST_H

#include<iostream>

//单链表的结构体实现

struct Node {

	int data;
	Node* next;
	Node(int val) :data(val), next(nullptr){}

};

class LinkedList
{
private:

	Node* head;//头指针

public:
	LinkedList();//构造

	~LinkedList();//销毁

	void print()const;//打印

	void pushFront(int val);//头插

	void pushBack(int val);//尾插

	bool insertAt(int pos, int val);//在某个位置插入

	bool removeByValue(int val);//根据值删除节点

	bool removeAt(int pos);//从位置1开始，删除节点

	bool updateAt(int pos, int newVal);//修改某个地方

	bool contains(int val)const;//查找数据

	Node* findNode(int val)const;//根据值返回节点指针

	int findIndex(int val)const;//根据索引

	int size()const;//辅助函数
};

#endif //LINKEDLIST_H

