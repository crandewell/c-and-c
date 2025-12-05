#include<iostream>
using namespace std;

class base
{
public:
	base()
	{
		cout<<"base 构造"<<endl;
	}
	~base()
	{
		cout<<"base 析构"<<endl;
	}
};
class son:public base
{
public:
	son()
	{
		cout<<"son 构造"<<endl;
	}
	~son()
	{
		cout<<"son 析构"<<endl;
	}
};

void test01()

{
	son s;
}
int main()
{
	test01();
	
	system("pause");
	return 0;
}
