#include<iostream>
#include<string>
using namespace std;

void test01()
{
	string s1;//此为空
	cout<<"str1="<<s1<<endl;
	
	const char*str="hello world";
	string s2(str);//将c_string转换为了string
	cout<<"str2="<<s2<<endl;
	
	string s3(s2);//调用拷贝构造函数
	cout<<"str3="<<s3<<endl;
	
	string s4(10,'a');
	cout<<"str3="<<s3<<endl;
	
}

int main()
{
	test01();
	
	
	system("pause");
	return 0;
}
