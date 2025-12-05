#include<iostream>
using namespace std;
class base
{
public:
	static void func()
	{
		cout<<"base-static void func()"<<endl;
	}
	static void func(int a)
	{
		cout<<"base-static void func(int a)"<<endl;
	}
	static int m_a;
};
int base::m_a=100;//为什么不能在类内定义

class son:public base
{
public:
	static void func()
	{
		cout<<"son-static void func()"<<endl;
	}
	static int m_a;
};
int son::m_a=200;

void test01()
{
	//通过对象访问
	cout<<"通过对象访问"<<endl;
	son s;
	cout<<"son 下m_a="<<s.m_a<<endl;
	cout<<"base 下m_a="<<endl;
	//通过类名访问
	cout<<"通过类名访问"<<endl;
	cout<<"son 下m_a="<<son::base::m_a<<endl;
}
void test02()
{
	//通过对象访问
	cout<<"通过对象访问:"<<endl;
	son s;
	s.func();
	s.base::func();
	//通过类名访问
	cout<<"通过类名访问"<<endl;
	son::func();
	son::base::func();
	son::base::func(100);
}
int main()
{
	
	test01();
	test02();
	
	system("pause");
	return 0;
}
