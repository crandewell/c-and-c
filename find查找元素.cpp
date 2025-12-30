#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
void test01()
{
	vector<int>v;
	for(int i=0;i<10;i++)
	{
		v.push_back(i+1);
	}
	vector<int>::iterator it=find(v.begin(),v.end(),5);//查找是否有这个元素，返回的是迭代器的位置
	if(it==v.end())
	{
		cout<<"没有找到!"<<endl;
	}
	else
	{
		cout<<"找到:"<<endl;
	}
}
class Person
{
public:
	Person(string name,int age)
	{
		this->m_Name=name;
		this->m_Age=age;
	}
	//重载==，让编译器知道如何进行比较
	bool operator==(const Person &p)
	{
		if(this->m_Name==p.m_Name&&this->m_Age==p.m_Age)
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
	vector<Person>v;
	Person p1("aaa",10);
	Person p2("bbb",20);
	Person p3("ccc",30);
	Person p4("ddd",40);
	
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	
	vector<Person>::iterator it=find(v.begin(),v.end(),p2);//什么意思
	if(it==v.end())
	{
		cout<<"没有找到!"<<endl;                    
	}
	else
	{
		cout<<"找到姓名:"<<it->m_Name<<"年龄:"<<it->m_Age<<endl;
	}
}
int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
}
