#include<iostream>
using namespace std;
//构造函数的调用规则
//1，创建一个类，则编译器给每个类子哦对你添加至少三个函数
//默认构造（空实现）
//析构构造（空实现）空实现的意思是函数内部是空的无代码
//拷贝构造（值拷贝）
class person
{
public:
	person()
	{
		cout<<"person默认构造函数调用"<<endl;
	}
	person(int age)
	{
		cout<<"person默认构造函数调用"<<endl;
		m_age=age;
	}
	person(const person &p)
	{
		m_age=p.m_age;
		cout<<"person拷贝构造函数调用"<<endl;
	}
	~ person()
	{
		cout<<"person析构函数调用"<<endl;
	}
	int m_age;
};
void test01()
{
	person p;
	p.m_age=18;
	
	person p2(p);
	cout<<"p2的年龄为"<<p2.m_age<<endl;
}
void test02()
{
	person p;
	
}
int main()
{
	test01();
	
	
	system("pause");
	return 0;
}
