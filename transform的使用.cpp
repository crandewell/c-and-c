#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class TransForm
{
public:
	int operator()(int val)
	{
		return val;
	}
};
class MyPrint
{
public:
	void operator()(int val)
	{
		cout<<val<<" ";
	}
};
void test01()
{
	vector<int>v;
	for(int i=0;i<10;i++)
	{
		v.push_back(i);
	}
	vector<int>vTarget;
	vTarget.resize(v.size());//目标容器要提前开辟空间才可以进行转移
	transform(v.begin(),v.end(),vTarget.begin(),TransForm());
	for_each(vTarget.begin(),vTarget.end(),MyPrint());
}
int main()
{
	test01();
	system("pause");
	return 0;
}
