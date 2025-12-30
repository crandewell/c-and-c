#include<iostream>
#include<string>
using namespace std;

void test01()
{
	string str1="我";
	str1+="爱玩游戏";
	cout<<"str1="<<str1<<endl;
	
	str1+=':';
	cout<<"str1="<<str1<<endl;
	
	string str2="LOL DNF";
	str1+=str2;
	
	cout<<"str1="<<str1<<endl;
	
	string str3="I";
	str3.append("love");
	str3.append("game abcde",4);
	str3.append(str2,4,3);
	cout<<"str3="<<str3<<endl;
}


int main()
{
	test01();
	
	system("pause");
	return 0;
}
