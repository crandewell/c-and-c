#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void test01()
{
	vector<int>v;
	for(int i=0;i<10;i++)
	{
		v.push_back(i);
	}
	//二分查找
	bool ret=binary_search(v.begin(),v.end(),2);//返回的是布尔值所以不是单纯的数字
	if(ret)
	{
		cout<<"找到了"<<endl;
	}
	else
	{
		cout<<"未找到"<<endl;
	}
}
int main()
{
	test01();	
	system("pause");
	return 0;
}
