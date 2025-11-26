//点与圆形的关系实现代码
#include<iostream>
using namespace std;

class point
{
private:
	int m_x;
	int m_y;
public:
	//设置x，y的坐标
	void setx(int x)
	{
		m_x=x;
	}
	void sety(int y)
	{
		m_y=y;
	}
	//获取x，y的坐标
	int getx()
	{
		return m_x;
	}
	int gety()
	{
		return m_y;
	}
};

class circle
{
private:
	int m_r;
	point m_center;
public:
	//设置半径和圆心
	void setr(int r)
	{
		m_r=r;
	}
	void setcenter(point center)//center 本身就是一个point 类型的变量，可以这么认为,所以要注意传入的具体参数是什么东西
	{
		m_center=center;
	}
	//获取半径和圆心
	int getr()
	{
		return m_r;
	}
	point getcenter()//此处也是类型是point，返回的是center的值
	{
		return m_center;
	}
};
//判断点和圆形的关系
void isincircle(circle &c,point &p)
{
	int distancesquared=(c.getcenter().getx()-p.getx())*(c.getcenter().getx()-p.getx())+(c.getcenter().gety()-p.gety())*(c.getcenter().gety()-p.gety());
	int rsquared=c.getr()*c.getr();
//判断关系
	if (distancesquared == rsquared) {
		cout << "点在圆上" << endl;
	} else if (distancesquared < rsquared) {
		cout << "点在圆内" << endl;
	} else {
		cout << "点在圆外" << endl;
	}
}
//注意这个函数的位置写好地方
int main()
{
	//创建一个圆对象
	circle circle;
	circle.setr(10);
	
	point center;
	center.setx(10);
	center.sety(10);
	circle.setcenter(center);
	
	//以下代码还没看了，明天记得看且反思
	point p1, p2, p3;
	
	//点在圆内的情况
	p1.setx(10);
	p1.sety(15);
	cout << "点p1(10,15)：";
	isincircle(circle, p1);
	
	//点在圆上的情况
	p2.setx(20);
	p2.sety(10);
	cout << "点p2(20,10)：";
	isincircle(circle, p2);
	
	//点在圆外的情况
	p3.setx(30);
	p3.sety(30);
	cout << "点p3(30,30)：";
	isincircle(circle, p3);
	system("pause");
	return 0;
}
