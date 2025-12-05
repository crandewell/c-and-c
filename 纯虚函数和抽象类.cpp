#include<iostream>
using namespace std;
class base
{
public:
	virtual void func()=0;
};
class son:public base
{
public:
	virtual void func()
	{
		cout<<"func的调用"<<endl;
	}
};
void test01()
{
	base *base=NULL;
	base=new son;
	base->func();
	delete base;
}

int main()
{
	
	test01();
	
	system("pause");
	return 0;
}

