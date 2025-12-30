#include<iostream>
#include<list>
using namespace std;

void printList(const list<int>&L)
{
	for(list<int>::const_iterator it=L.begin();it!=L.end();it++)//不用const修饰可以吗
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	if(L1.empty())
	{
		cout<<"L1为空"<<endl;
	}
	else
	{
		cout<<"L1不为空"<<endl;
		cout<<"L1的大小为:"<<L1.size()<<endl;
	}
	
	L1.resize(10);
	printList(L1);
	L1.resize(2);
	printList(L1);
}
int main()
{
	test01();
	system("pause");
	return 0;
}
