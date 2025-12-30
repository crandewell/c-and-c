#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Greater4
{
public:
	bool operator()(int val)
	{
		return val>=4;
	}
};

void test01()
{
	vector<int>v;
	
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
	
	int num=count_if(v.begin(),v.end(),Greater4());
	
	cout<<"大于4的个数为:"<<num<<endl;
}

//对于自定义的数据类型
class person
{
public:
	person(string name,int age)
	{
		this->m_Name=name;
		this->m_Age=age;
	}
	string m_Name;
	int m_Age;
};

class AgeLess35
{
public:
	bool operator()(const person&p)
	{
		return p.m_Age<35;//想要什么条件就重载返回什么样的条件
	}
};

void test02()
{
	
	vector<person>v;
	
	person p1("L",35);
	person p2("G",35);
	person p3("Z",35);
	person p4("Z",35);
	person p5("C",35);
	
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	
	int num=count_if(v.begin(),v.end(),AgeLess35());
	cout<<"小于35岁的个数:"<<num<<endl;
}
int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
}
