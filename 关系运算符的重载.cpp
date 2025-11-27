#include<iostream>
using namespace std;

//关系运算重载

class person
{
	
public:
	person(string name,int age)
	{
		m_name=name;
		m_age=age;
	}
	//在类中重载==号
	
	bool operator==(person &p)
	{
		if(this->m_name==p.m_name&&this->m_age==p.m_age)
		{
			return true;
		}
		return false;
	}
	
	string m_name;
	int m_age;
};

void test01()
{
	person p1("Tom",18);
	person p2("Tom",18);
	
	if(p1==p2)
	{
		cout<<"p1=p2"<<endl;
	}
}

int main()
{
	test01();
	
	
	system("pause");
	return 0;
}
