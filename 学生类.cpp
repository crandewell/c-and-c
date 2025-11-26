#include<iostream>
#include<string>
using namespace std;
class student
{
	
public:
	string m_Name;
	int m_ID;
	
	//行为
	//显示姓名和学号
	void showstudent()
	{
		cout<<"姓名是:  "<<m_Name<<"  学号是:"<<m_ID<<endl;
	}
	//传进来name，之后改m——name
	void setName(string name)
	{
		//是m_Name
		m_Name=name;
	}
	void setID(int id)
	{
		m_ID=id;
	}
};
	
int main()
{
	//实例化对象
	student s1;
	s1.setName("张三");
	s1.setID(1); 
	s1.showstudent();
	
	student s2;
	s2.m_Name="李四";
	s2.m_ID=2;
	s2.showstudent();
	system("pause");
	return 0;
}
