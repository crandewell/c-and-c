#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void myPrint(int val)
{
	cout<<val<<" ";                                  
}

void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	v.push_back(20);
	v.push_back(50);
	
	//sort默认是从小到大来排序
	sort(v.begin(),v.end());
	for_each(v.begin(),v.end(),myPrint);//这是输出结果么,类似与cout吧
	cout<<endl;
	
	//若是从大到小的实现
	sort(v.begin(),v.end(),greater<int>());
	for_each(v.begin(),v.end(),myPrint);
	cout<<endl;
}

int main()
{
	
	test01();
	system("pause");
}
