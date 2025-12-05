#include<iostream>
using namespace std;

class cpu
{
public:
	//抽象的计算函数
	virtual void calculate()=0;
	virtual ~cpu(){}
};

class videocard
{
public:
	//抽象的显示函数
	virtual void display()=0;
	virtual ~videocard(){}
};

class memory
{
public:
	//抽象的存储函数
	virtual void storage()=0;
	virtual ~memory(){}
};

class computer
{
public:
	computer(cpu*cpu,videocard *vc,memory *mem)
	{
		m_cpu=cpu;
		m_vc=vc;
		m_mem=mem;
	}
	void work()
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	//提供析构函数 释放3个电脑零件
	~computer()
	{
		//释放cpu零件
		if(m_cpu!=NULL)
		{
			delete m_cpu;
			m_cpu=NULL;
		}
		if(m_vc!=NULL)
		{
			delete m_vc;
			m_vc=NULL;
		}
		if(m_mem!=NULL)
		{
			delete m_mem;
			m_mem=NULL;
		}
	}
private:
	cpu *m_cpu;
	videocard *m_vc;
	memory *m_mem;
};
//具体的厂商
//Intel
class intelcpu:public cpu
{
public:
	virtual void calculate()
	{
		cout<<"Intel的cpu开始计算了"<<endl;
	}
};
class intelvideocard:public videocard
{
public:
	virtual void display()
	{
		cout<<"Intel的显卡开始显示了"<<endl;
	}
};
class intelmemory:public memory
{
public:
	virtual void storage()
	{
		cout<<"Intel的内存条开始存储了"<<endl;
	}
};
//lenovo
class lenovocpu:public cpu
{
public:
	virtual void calculate()
	{
		cout<<"lenovo的cpu开始计算了"<<endl;
	}
};
class lenovovideocard:public videocard
{
public:
	virtual void display()
	{
		cout<<"lenovo的显卡开始显示了"<<endl;
	}
};
class lenovomemory:public memory
{
public:
	virtual void storage()
	{
		cout<<"lenovo的内存条开始存储了"<<endl;
	}
};
void test01()
{
	//第一台电脑零件
	cpu * intelCpu = new intelcpu;          // 改为小写
	videocard * intelCard = new intelvideocard;  // 改为小写
	memory * intelMem = new intelmemory;         // 改为小写
	
	cout << "第一台电脑开始工作：" << endl;
	//创建第一台电脑
	computer * computer1 = new computer(intelCpu, intelCard, intelMem);
	computer1->work();
	delete computer1;
	
	cout << "-----------------------" << endl;
	cout << "第二台电脑开始工作：" << endl;
	//第二台电脑组装
	computer * computer2 = new computer(new lenovocpu, new lenovovideocard, new lenovomemory);
	computer2->work();
	delete computer2;
	
	cout << "-----------------------" << endl;
	cout << "第三台电脑开始工作：" << endl;
	//第三台电脑组装
	computer * computer3 = new computer(new lenovocpu, new intelvideocard, new lenovomemory);
	computer3->work();
	delete computer3;
}


int main()
{
	
	test01();
	
	system("pause");
}
