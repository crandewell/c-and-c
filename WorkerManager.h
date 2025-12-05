#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define FILENAME "empFile.txt"

class Worker;

class WorkerManager
{

public:
	//构造函数
	WorkerManager();

	//析构函数
	~WorkerManager();

	//展示菜单
	void Show_Menu();

	//退出系统
	void exitSystem();

	//添加职工
	void Add_Emp();

	//保存文件
	void save();

	//统计人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示职工
	void Show_Emp();
	
	//删除职工
	void Del_Emp();

	//按照职工编号来判断职工是否存在，存在则返回在数组中的位置，否则返回-1
	int IsExist(int id);

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//排序职工
	void Sort_Emp();

	//清空文件
	void Clean_File();

private:
	//记录文件中的人数
	int m_EmpNum;
	
	//员工数组的指针
	Worker** m_EmpArray;

	//标志文件是否为空
	bool m_FileIsEmpty;
};
