#include<iostream>
using namespace std;
class base
{
public:
	base()
	{
		m_a=100;
	}
	void func()
	{
		cout<<"base-func 调用"<<endl;
	}
	void func(int a)
	{
		cout<<" base-func(int a) 调用"<<endl;
	}
	
	int m_a;
};
class son:public base
{
public:
	son()
	{
		m_a=200;
	}
	void func()
	{
		cout<<"son-func()调用"<<endl;
	}
	int m_a;
};
void test01()
{
	son s;
	
	cout<<"son 下的m_a="<<s.m_a<<endl;//子类可以直接进行访问 
	cout<<"base 下的m_a"<<s.base::m_a<<endl;
	
	s.func();
	s.base::func();
	s.base::func(10);
}

int main()
{
	test01();
	
	system("pause");
}
