#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class person
{
public:
	char m_name[64];
	int m_age;
};

void test01()
{
	ifstream ifs("person.txt",ios::in|ios::binary);
	if(!ifs.is_open())//是is_open
	{
		cout<<"文件打开失败"<<endl;
	}
	person p;
	ifs.read((char*)&p,sizeof(p));
	
	cout<<"姓名:"<<p.m_name<<"  年龄:"<<p.m_name<<endl;
}


int main()
{
	test01();	
	system("pause");
	return 0;
}
