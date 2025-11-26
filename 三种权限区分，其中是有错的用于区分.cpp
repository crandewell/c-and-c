#include<iostream>
#include<string>
using namespace std;

class Person
{
	//公共
public:
	string m_name;
	//保护
protected:
	string m_car;
	//私有
private:
	int m_password;

public:
	void func()
	{
		m_name="张三";
		m_car="图拉集";
		m_password=123456;
	}
};
int main()
{
	Person p1;
	p1.m_name="李四";
	p1.m_car="奔驰";//保护在类外访问不到
	p1.m_password=123;//私有权限在类外访问不到
	p1.func();
	system("pause");
	return 0;
}
