#include<iostream>
using namespace std;

class base1
{
public:
	base1()
	{
		m_a=100;
	}
public:
	int m_a;
};

class base2
{
public:
	base2()
	{
		m_a=200;
	}
public:
	int m_a;
};

class son:public base1,public base2
{
public:
	son()
	{
		m_c=300;
		m_d=400;
	}
public:
	int m_c;
	int m_d;
};
void test01()
{
	son s;
	cout<<"sizeof son="<<sizeof(s)<<endl;
	cout<<s.base1::m_a<<endl;
	cout<<s.base2::m_a<<endl;
}

int main()
{
	test01();
	system("pause");
	return 0;
}
