#include"LinkedList.h"

#include<iostream>
//构造函数
LinkedList::LinkedList():head(nullptr){}
//析构函数的销毁
LinkedList::~LinkedList()
{
	Node* current = head;
	while (current != nullptr)
	{
		Node* next = current->next;
		delete current;
		current = next;
	}
	head = nullptr;
}

//打印链表
void LinkedList::print()const
{
	Node* current = head;
	if (current == nullptr)
	{
		std::cout << "链表为空" << std::endl;
		return;
	}
	while (current != nullptr)
	{
		std::cout << current->data;
		if (current->next != nullptr)
		{
			std::cout << "->";
		}
		current = current->next;
	}
	std::cout << std::endl;
}

//头插
void LinkedList::pushFront(int val)
{
	Node* newNode = new Node(val);
	newNode->next = head;
	head = newNode;
}

//尾插
void LinkedList::pushBack(int val)
{
	Node* newNode = new Node(val);
	if (head == nullptr)
	{
		head = newNode;
		return;
	}
	Node* current = head;

	while (current->next != nullptr)
	{
		current = current->next;
	}
	current->next = newNode;
}
//在指定位置插入，从1开始
bool LinkedList::insertAt(int pos, int val)
{
	if (pos < 1)
	{
		std::cerr << "错误" << std::endl;//cerr是错误信息
		return false;
	}
	//头插特殊
	if (pos == 1)
	{
		pushFront(val);
		return true;
	}
	Node* current = head;

	for (int i = 1; i < pos - 1 && current != nullptr; i++)
	{
		current = current->next;
	}
	if (current == nullptr)
	{
		std::cerr << "错误：插入位置超出链表+1" << std::endl;
		return false;
	}
	Node* newNode = new Node(val);
	newNode->next = current->next;
	current->next = newNode;
	return true;
}

//根据值删除第一个匹配的节点
bool LinkedList::removeByValue(int val)
{
	if (head == nullptr)
	{
		std::cerr << "错误：无效位置或链表为空" << std::endl;
		return false;
	}
	if (head->data==val)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		return true;
	}
	Node* current = head;
	while (current->next != nullptr && current->next->data != val)
	{
		current = current->next;
	}
	if (current == nullptr || current->next == nullptr)
	{
		std::cerr << "错误:超出了链表的长度" << std::endl;
		return false;
	}
	Node* temp = current->next;
	current->next = temp->next;
	delete temp;
	return true;
}
//根据位置删除节点
bool LinkedList::removeAt(int pos)
{
	if (pos < 1 || head == nullptr)
	{
		std::cerr << "错误:无效位置或链表为空" << std::endl;
		return false;
	}
	if (pos == 1)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		return true;
	}
	Node* current = head;

	//找到第pos-1个节点
	for (int i = 1; i < pos - 1 && current != nullptr; i++)
	{
		current = current->next;
	}
	if (current == nullptr || current->next == nullptr)
	{
		std::cerr << "错误：删除位置超出了链表长度" << std::endl;
		return false;
	}
	Node* temp = current->next;
	current->next = temp->next;
	delete temp;
	return true;
}


//修改某个位置的数据
bool LinkedList::updateAt(int pos, int newVal)
{
	if (pos < 1 || head == nullptr)
	{
		std::cerr << "错误:无效位置或者链表为空" << std::endl;
		return false;
	}
	Node* current = head;
	for (int i = 1; i < pos && current != nullptr; i++)
	{
		current = current->next;
	}
	if (current == nullptr)
	{
		std::cerr << "错误：修改位置超出了链表的长度" << std::endl;
		return false;
	}
	current->data = newVal;
	return true;
}

//查找数据
bool LinkedList::contains(int val)const
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data == val)return current;
		current = current->next;
	}
	return false;
}

//根据值返回节点指针（若存在，返回第一个匹配节点指针，否则返回nullptr）
Node* LinkedList::findNode(int val)const
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data == val)return current;
		current = current->next;
	}
	return nullptr;
}

//根据值返回下标---从0开始----不存在返回-1
int LinkedList::findIndex(int val)const
{
	Node* current = head;
	int index = 0;
	while (current != nullptr)
	{
		if (current->data == val)return index;
		current = current->next;
		index++;
	}
	return -1;
}

//获取链表长度
int LinkedList::size()const
{
	int count = 0;
	Node* current = head;
	while (current != nullptr)
	{
		count++;
		current = current->next;
	}
	return count;
}




