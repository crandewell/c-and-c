#include<iostream>
using namespace std;

class basepage
{
public:
	void header()
	{
		cout<<"首页，公开课，登录..."<<endl;
	}
	void footer()
	{
		cout<<"帮助中心，交流合作，站内地图"<<endl;
	}
	void left()
	{
		cout<<"java，python，cpp"<<endl;
	}
};

//java
class java:public basepage
{
public:
	void content()
	{
		cout<<"java学科视频"<<endl;
	}
};
//python
class python:public basepage
{
public:
	void content()
	{
		cout<<"python学科视频"<<endl;
	}
};
//cpp
class cpp:public basepage
{
public:
	void content()
	{
		cout<<"cpp学科视频"<<endl;
	}
};

void test01()
{
	cout<<"java学科视频如下"<<endl;
	java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout<<"-------------------------------"<<endl;
	
	cout<<"python学科视频如下"<<endl;
	python py;
	py.header();
	py.footer();
	py.left();
	py.content();
	cout<<"-------------------------------"<<endl;
	
	cout<<"cpp学科视频如下"<<endl;
	cpp cp;
	cp.header();
	cp.footer();
	cp.left();
	cp.content();
	cout<<"-------------------------------"<<endl;
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
