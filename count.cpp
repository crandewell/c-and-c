#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void test01()
{
	vector<int>v;
	for(int i=0;i<10;i++)
	{
		v.push_back(i);
	}
	v.push_back(4);
	
	int num=count(v.begin(),v.end(),4);
	
	cout<<"4的个数为:"<<num<<endl;
}

//对于自定义类型
class person
{
public:
	person(string name,int age)
	{
		this->m_Name=name;
		this->m_Age=age;
	}
	bool operator==(const person&p)//为啥在类内重载，在类外可以吗
	{
		if(this->m_Age==p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string m_Name;
	int m_Age;
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
	
	person p("诸葛亮",35);
	
	int num=count(v.begin(),v.end(),p);//什么意思写一个p
	
	cout<<"num="<<num<<endl;
}
int main()
{
	
	test01();
	test02();
	system("pause");
	return 0;
}
