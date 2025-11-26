#include<iostream>
using namespace std;
const double PI=3.14;

//设计类求周长
//半径是属性
class circle
{
	//访问权限
public://是冒号注意
	//属性
	int m_r;
	//行为
	//获取的周长，函数
	double calculateZC()
	{
		return 2*PI*m_r;
	}
	
};
int main()
{
	//创建具体(对象)
	circle c1;//实例化，创建具体的对象
	//属性的赋值
	c1.m_r=10;
	
	cout<<"圆的周长为"<<c1.calculateZC()<<endl;
	
	system("pause");
}
