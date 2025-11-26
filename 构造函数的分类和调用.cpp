#include<iostream>
using namespace std;

class person
{
public:
	//构造函数,析构函数
	person()//无参构造（默认）
	{
		cout<<"person 的有参构造函数调用"<<endl;
	}
	person(int a)//有参构造
	{
		age=a;
		cout<<"person 的无参构造函数调用"<<endl;
	}
	//拷贝构造函数
	person(const person &p)
	{
		//人身上的属性copy到我身上
		age=p.age;
	}
	~person()
	{
		cout<<"person 的析构函数调用"<<endl;
	}
	int age;
};
//调用
void test01()
{
	//1  括号法
	person p1;//默认函数的调用，此时调用不要写（）
	person p2(10);//调用有参的构造函数
	person p3(p2);//拷贝构造函数
	cout<<"p2的年龄"<<p2.age<<endl;
	cout<<"p3的年龄"<<p3.age<<endl;
	//2  显示法
	person p4;
	person p5=person(10);//有参构造
	//拷贝构造
	person p6=person(p5);
	person (10);//匿名对象,当前行执行结束后系统立即回收
	  
	//3  隐式转换法
	person p7=10;
	person p8=p7;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
