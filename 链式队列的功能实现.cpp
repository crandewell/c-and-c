#include<iostream>
using namespace std;

class LinkedQueue
{
private:
	struct Node
	{
		int data;
		Node* next;
	};
	
	Node* front;
	Node* rear;
	
public:
	LinkedQueue()
	{
		front=nullptr;
		rear=nullptr;
	}
	//入队操作
	void enqueue(int value)
	{
		Node* newNode=new Node;
		newNode->data=value;
		newNode->next=nullptr;//这是要干啥
		
		//如果队列是空的，新节点既是队头又是队尾
		if(front==nullptr)
		{
			front=newNode;
			rear=newNode;
		}
		else
		{
			rear->next=newNode;
			rear=newNode;
		}
	}
	//出队的操作
	void dequeue()
	{
		if(front==nullptr)
		{
			std::cout<<"队列为空，不能出队"<<endl;
			return;
		}
		//保存要删除的节点
		Node* temp=front;
		//移动头指针
		front=front->next;
		//队头如果为空，队列已空，队尾也要设置为空
		if(front==nullptr)
		{
			rear=nullptr;
		}
		delete temp;
	}
	
	//获取队头的元素
	int getFront()
	{
		if(front==nullptr)
		{
			std::cout<<"队列为空!"<<endl;
			return -1;
		}
		return front->data;
	}
	
	//获取队尾的元素
	int getRear()
	{
		if(rear==nullptr)
		{
			std::cout<<"队列为空!"<<endl;
		}
		return rear->data;
	}
	
	//判断队列是否为空
	bool isEmpty()
	{
		return front==nullptr;
	}
	
	//显示队列的内容
	void display()
	{
		if(front==nullptr)
		{
			std::cout<<"队列为空!"<<endl;
			return;
		}
		
		std::cout<<"队头到队尾输出元素"<<endl;
		Node* current=front;
		while(current!=nullptr)
		{
			std::cout<<current->data;
			current=current->next;
		}
		std::cout<<std::endl;
	}
	
	//清空队列
	void clear()
	{
		while(front!=nullptr)
		{
			dequeue();
		}
	}	
	
	~LinkedQueue()
	{
		clear();
	}
	
};

int main()
{
	
}
