//函数调用运算符重载
#include<iostream>
using namespace std;

class myprint
{
public:
	void operator()(string text)
	{
		cout<<text<<endl;
	}
};
void test01()
{
	//重载的（）操作符称为仿函数
	myprint myfunc;
	myfunc("hello world");
}
class myadd
{
public:
	int operator()(int v1,int v2)
	{
		return v1+v2;
	}
};
void test02()
{
	myadd add;
	int ret=add(10,10);
	cout<<"ret="<<ret<<endl;
	//匿名对象调用
	cout<<"myadd()(100,100)="<<myadd()(100,100)<<endl;
}

int main()
{
	test01();
	test02();
	
	system("pasue");
	return 0;
}
