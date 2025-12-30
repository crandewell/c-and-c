#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>&v)
{
	for(vector<int>::iterator it=v.begin();it!=v.end();it++)
	{
		cout<<*it<<" ";//若是换成it呢，因为it是迭代器而不是数值，所以要用*来解出值才可以正常输出
	}
	cout<<endl;
}
void test01()
{
	vector<int>v1;
	for(int i=0;i<10;i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	
	vector<int>v2;
	v2=v1;
	printVector(v2);
	
	vector<int>v3;
	v3.assign(v1.begin(),v1.end());
	printVector(v3);
	
	vector<int>v4;
	v4.assign(10,100);
	printVector(v4);
}

int main()
{
	test01();
	
	system("pause");
	return 0;
}
