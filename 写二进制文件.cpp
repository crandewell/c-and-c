#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class person
{
public:
	char m_name[64];
	int m_age;
};

//二进制文件  写文件
void test01()
{
	ofstream ofs("person.txt",ios::out|ios::binary);//因为这个文件在创建时候就已经打开了
	//ofs.open("person.txt",ios::out|ios::binary);//为啥这个要注释
	person p={"张三",18};
	ofs.write((const char*) &p,sizeof(p));
	ofs.close();
}
int main()
{
	test01();
	system("pause");
	return 0;
}
