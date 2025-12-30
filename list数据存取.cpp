#include<list>
#include<iostream>
using namespace std;
void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	
	cout<<"第一个元素为:"<<L1.front()<<endl;
	cout<<"最后一个元素为:"<<L1.back()<<endl;
	
	list<int>::iterator it=L1.begin();
}
int main()
{
	test01();
	
	system("pause");
	return 0;
}
