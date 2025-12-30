#include<string>
#include<iostream>
using namespace std;

void test01()
{
	string s1="hello";
	string s2="aello";
	
	int ret=s1.compare(s2);//注意s1 s2 的顺序
	
	if(ret==0)
	{
		cout<<"s1等于s2"<<endl;
	}
	else if(ret>0)
	{
		cout<<"s1大于s2"<<endl;
	}
	else
	{
		cout<<"s1小于s2"<<endl;
	}
}

int main()
{
	
	test01();
	
	system("pause");
	return 0;
}
