#include<iostream>
using namespace std;
//vector容器
//算法为for_each
//迭代器 vector<int>::iterator
#include<vector>
#include<algorithm>

void MyPrint(int val)
{
	cout<<val<<endl;
}

void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	
	vector<int>::iterator pBegin=v.begin();
	vector<int>::iterator pEnd=v.end();
	
	//第一种遍历的方式
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
	{
		cout<<*it<<endl;
	}
	cout<<endl;

	//二
	while(pBegin!=pEnd)
	{
		cout<<*pBegin<<endl;
		pBegin++;
	}
	
	//三
	for_each(v.begin(),v.end(),MyPrint);
}
int main()
{
	test01();
	system("pause");
	return 0;
}
