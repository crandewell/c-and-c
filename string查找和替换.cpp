#include<iostream>
#include<string>
using namespace std;

//查找和替换
void test01()
{
	//查找
	string str1="abcdefgde";
	int pos=str1.find("de");
	if(pos==-1)//没有找到的话是返回一个-1的
	{
		cout<<"未找到"<<endl;
	}
	else
	{
		cout<<"pos="<<pos<<endl;
	}
}
void test02()
{
	//替换
	string str1="abcdefgde";
	str1.replace(1,3,"1111");
	
	cout<<"str1="<<str1<<endl;
}

int main()
{
	
	test01();
	test02();
	system("pause");
	return 0;
}
