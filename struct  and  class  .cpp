#include<iostream>
#include<string>
using namespace std;

class C1
{
	//默认是private权限
	int m_a;
	
};
struct C2
{
	//默认是public权限
	int m_a;
};
int main()
{
	//struct和class的区别
	C1 c1;
	//c1.m_a=100;//因为私有所以会报错
	C2 c2;//但是struct默认权限是公共，所以类外是可以访问的
	c2.m_a=100;
	
	system("pause");
	return 0;
}
