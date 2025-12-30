#include<iostream>
using namespace std;
template<class T>
class base
{
	T m;
};

class son:public base<int>//子继承父类，必须是要指定一个模板的
{
// 而且编译器给子类分配内存的时候必须要知道父类中的T的类型才可以向下继承	
};

void test01()
{
	son c;
}

template<class T1,class T2>

class son2:public base<T2>
{
public:
	son2()
	{
		cout<<typeid(T1).name()<<endl;
		cout<<typeid(T2).name()<<endl;
	}
};
	
void test02()
{
	son2<int,char>child1;
}

int main()
{
	test01();
	test02();
	
	system("pause");
	return 0;
}
