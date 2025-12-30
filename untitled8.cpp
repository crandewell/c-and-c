#include<iostream>
#include<list>
using namespace std;

void printList(const list<int>&L)
{//看清楚对应的字母代表是什么
	for(list<int>::const_iterator it=L.begin();it!=L.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

bool myCompare(int val1,int val2)
{
	return val1>val2;//如果val1>val2,返回的是true,表示val1应该在val2前面，val1是大的那个,这就是大的在前面了，总体是降序的
}

//反转和排序
void test01()
{
	list<int>L;
	L.push_back(90);
	L.push_back(30);
	L.push_back(70);
	L.push_back(20);
	printList(L);
	
	//反转容器的元素
	L.reverse();
	printList(L);
	//排序
	L.sort();//默认的排序规则从小到大
	printList(L);
	
	L.sort(myCompare);
	printList(L);
}

int main()
{
	
	test01();
	system("pause");
	return 0;
}
