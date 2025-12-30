#include<iostream>
#include<stack>
using namespace std;
void test01()
{
	//stack栈容器
	stack<int>s;
	
	s.push(10);
	s.push(20);
	s.push(30);
	
	while(!s.empty())
	{
		cout<<"栈顶的元素为:"<<s.top()<<endl;
		//弹出栈顶元素
		s.pop();
	}
	cout<<"栈的大小为:"<<s.size()<<endl;
}
int main()
{
	test01();
	
	system("pause");
	return 0;
}
