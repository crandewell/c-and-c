#include<iostream>
using namespace std;

class person
{
public:
	person()
	{
		cout<<"person的默认构造函数调用"<<endl;
	}
	person(int age)
	{
		cout<<"person的有参构造函数调用"<<endl;
		m_age=age;
	}
	person(const person & p)
	{
		cout<<"person的拷贝构造函数调用"<<endl;
		m_age=p.m_age;//传入的是进来的p这里面的age变量
	}
	~person()
	{
		cout<<"person的析构函数调用"<<endl;
	}
	
	int m_age;
};
//使用一个已创建完毕的对象来初始化一个新的对象，最为常用
void test01()
{
	person p1(20);
	person p2(p1);
	
	cout<<"p2的年龄为："<<p2.m_age<<endl;
}
//值传递的方式给函数的参数传值
void dowork(person p)//person p是值传递
{
	
}
void test02()
{
	person p; 
	dowork(p);
}
//用值方式返回局部对象

person dowork2()
{
	person p1;
	cout<<(int*)&p1<<endl;
	return p1;
}

void test03()
{
	person p=dowork2();
	cout<<(int*)&p<<endl;
}
int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}
