#include<iostream>
using namespace std;

class abstractcalculator
{
public:
	
	virtual int getresult()
	{
		return 0;
	}
	int m_num1;
	int m_num2;
};

class addcalculator:public abstractcalculator
{
public:
	int getresult()
	{
		return m_num1+m_num2;
	}
};

class subcaculator:public abstractcalculator
{
public:
	int getresult()
	{
		return m_num1-m_num2;
	}
};

class mucalculator:public abstractcalculator
{
public:
	int getresult()
	{
		return m_num1*m_num2;
	}
};

void test02()
{
	abstractcalculator*abc=new addcalculator;
	abc->m_num1=10;
	abc->m_num2=10;
	cout<<abc->m_num1<<"+"<<abc->m_num2<<"="<<abc->getresult()<<endl;//属性继承的
	delete abc;
	
	abc=new subcaculator;
	abc->m_num1=10;
	abc->m_num2=10;
	cout<<abc->m_num1<<"-"<<abc->m_num2<<"="<<abc->getresult()<<endl;//属性继承的,利用不同的指针来操作
	delete abc;
	
	abc=new mucalculator;
	abc->m_num1=10;
	abc->m_num2=10;
	cout<<abc->m_num1<<"*"<<abc->m_num2<<"="<<abc->getresult()<<endl;//属性继承的
	delete abc;
}

int main()
{
	test02();
	
	
	system("pause");
	return 0;
}
