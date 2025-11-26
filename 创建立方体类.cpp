#include<iostream>
#include<string>
using namespace std;

class cube
{
private:
	int m_length;
	int m_width;
	int m_height;
public:
	//设置长宽高
	void setlength(int length)
	{
		m_length=length;
	}
	void setwidth(int width)
	{
		m_width=width;
	}
	void setheight(int height)
	{
		m_height=height;
	}
	//获取长宽高
	int getlength()
	{
		return m_length;
	}
	int getwidth()
	{
		return m_width;
	}
	int getheight()
	{
		return m_height;
	}
	//计算表面积
	int calcuateS()
	{
		return 2*(m_length*m_width+m_length*m_height+m_width*m_height);
	}
	int calculateV()
	{
		return m_length*m_height*m_width;
	}
	//成员函数的判断两个立方体是否相等
	bool isSameByClass(cube&c)
	{
		if(m_length==c.getlength()&&
		   m_height==c.getheight()&&
		   m_width==c.getwidth())
		{
			return true;
		}
		else
		{
			return false;
		}	
	}
};
//在类外是全局的函数
bool isSameByGlobal(cube &c1,cube &c2)
{
	if(c1.getlength()==c2.getlength()&&
	   c1.getwidth()==c2.getwidth()&&
	   c1.getheight()==c2.getheight())
	{
		return true;
	}
	else
	{
		return false;
	}	
}
int main()
{
	cube c1;
	c1.setlength(10);
	c1.setwidth(10);
	c1.setheight(10);
	
	cube c2;
	c2.setlength(10);
	c2.setwidth(10);
	c2.setheight(12);
	//作输出
	cout<<"c1的表面积为"<<c1.calcuateS()<<endl;
	cout<<"c2的表面积为"<<c2.calcuateS()<<endl;
	cout<<"c1的体积为"<<c1.calculateV()<<endl;
	cout<<"c2的体积为"<<c2.calculateV()<<endl;
	//利用成员函数和全局函数做比较
	cout<<"通过成员函数做比较"<<endl;
	
	if(c1.isSameByClass(c2))
	{
		cout<<"c1和c2相等"<<endl;
	}
	else
	{
		cout<<"c1和c2不相等"<<endl;
	}
	//利用全局函数做比较
	cout<<"通过全局函数做比较"<<endl;
	
	if(isSameByGlobal(c1,c2))
	{
		cout<<"c1和c2相等"<<endl;
	}
	else
	{
		cout<<"c1和c2不相等"<<endl;
	}

	system("pause");
	return 0;
}
