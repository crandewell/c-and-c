#include<iostream>
using namespace std;
class animal
{
public:
	animal()
	{
		cout<<"animal 构造函数的调用!"<<endl;
	}
	virtual void speak()=0;
	//析构函数加上virtual关键字,变成虚析构函数 
	virtual~animal()=0;
};
animal::~animal()
{
	cout<<"animal 纯析构函数的调用!"<<endl;
}

class cat:public animal
{
public:
	cat(string name)
	{
		cout<<"cat 构造函数调用!"<<endl;
		m_name=new string(name);
	}
	virtual void speak()
	{
		cout<<*m_name<<"小猫在说话!"<<endl;
	}
	~cat()
	{
		cout<<"cat 析构函数调用!"<<endl;
		if(this->m_name!=NULL)
		{
			delete m_name;
			m_name=NULL;
		}
	}
public:
	string *m_name;
};

void test01()
{
	animal *animal=new cat("Tom");
	animal->speak();
	delete animal;
}
int main()
{
	test01();
	
	system("pause");
	return 0;
}
//通过父类指针去释放，会导致子类对象可能清理不干净，造成内存的泄露
//可以给父类增加一个虚析构函数
//虚析构函数就是用来解决通过父类指针释放子类对象
