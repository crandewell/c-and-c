#include<iostream>
using namespace std;
class myinteger
{
	
	friend ostream &operator<<(ostream &cout,myinteger myint);
public:
	myinteger()
	{
		m_num=0;
	}

	myinteger &operator++()
	{
		m_num++;
		return *this;
	}
	myinteger operator++(int)
	{
		myinteger temp=*this;
		m_num++;
		return temp;
	}
private:
	int m_num;
};
void test01()
{
	myinteger myint;
	cout<<myint<<endl;
}
ostream &operator<<(ostream &cout,myinteger myint)
{
	cout<<myint.m_num;
	return cout;
}


int main()
{
	test01();
	
	system("pause");
	return 0;
}
