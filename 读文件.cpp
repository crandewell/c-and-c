#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//1，包含头文件
//2，创建流对象
//3，打开文件并判断文件是否打开成功
//4，读数据
//5，关闭文件
void test01()
{
	ifstream ifs;
	ifs.open("test.txt",ios::in);
	
	if(!ifs.is_open())//is_open函数可以打开文件成功与否的检测
	{
		cout<<"打开文件失败"<<endl;
		return;//hyw
	}
	/*//第一种方式
	char buf1[1024]={0};
	while(ifs>>buf1)
	{
		cout<<"buf"<<endl;
	}
	//第二种方式
	char buf2[1024]={0};
	while(ifs.getline(buf2,sizeof(buf2)))//是ifs文件流对象的下属函数，要把内容放在哪里，准备了多少空间--getline函数
	{
		cout<<buf2<<endl;
	}*/
	//第三种方式,我觉得这种好用
	string buf;//string 一个对象
	while(getline(ifs,buf))
	{
		cout<<buf<<endl;
	}
	/*//第四种方式
	char c;
	while((c=ifs.get())!=EOF)
	{
		cout<<c;
	}
	ifs.close();*/
}

int main()
{
	
	test01();
	
	system("pause");
	return 0;
}
