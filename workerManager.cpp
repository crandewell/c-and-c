#include "WorkerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

WorkerManager::WorkerManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    // 文件不存在的情况处理
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }

    // 文件存在但是没有实际内容
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "文件为空" << endl;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;
    }

    int num = this->get_EmpNum();
    cout << "职工个数为" << num << endl;
    this->m_EmpNum = num;

    // 根据职工数来创建具体的数组
    this->m_EmpArray = new Worker * [this->m_EmpNum];
    // 初始化职工
    init_Emp();
}

WorkerManager::~WorkerManager()
{
    if (this->m_EmpArray != NULL)
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            if (this->m_EmpArray[i] != NULL)
            {
                delete this->m_EmpArray[i];
            }
        }
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}

void WorkerManager::Show_Menu()
{
    cout << "********************************************" << endl;
    cout << "********* 欢迎使用职工管理系统！ **********" << endl;
    cout << "************* 0.退出管理程序 *************" << endl;
    cout << "************* 1.增加职工信息 *************" << endl;
    cout << "************* 2.显示职工信息 *************" << endl;
    cout << "************* 3.删除离职职工 *************" << endl;
    cout << "************* 4.修改职工信息 *************" << endl;
    cout << "************* 5.查找职工信息 *************" << endl;
    cout << "************* 6.按照编号排序 *************" << endl;
    cout << "************* 7.清空所有文档 *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void WorkerManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("Pause");
    exit(0);
}

void WorkerManager::Add_Emp()
{
    cout << "请输入增加职工的数量" << endl;

    int addNum = 0;
    cin >> addNum;

    if (addNum > 0)
    {
        // 计算新空间的大小
        int newSize = this->m_EmpNum + addNum;

        // 开辟新空间
        Worker** newSpace = new Worker * [newSize];

        // 复制原有数据到新数组
        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)  // 修正：复制原有的 m_EmpNum 个数据
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        // 输入新的数据
        for (int i = 0; i < addNum; i++)
        {
            int id;
            string name;
            int dSelect;

            cout << "请输入第" << i + 1 << "个新职工的编号:" << endl;
            cin >> id;

            cout << "请输入第" << i + 1 << "个新职工的姓名:" << endl;
            cin >> name;

            cout << "请选择该职工的岗位:" << endl;
            cout << "1.普通职工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> dSelect;

            Worker* worker = NULL;
            switch (dSelect)
            {
            case 1:  // 修正：case 和数字之间要有空格
                worker = new Employee(id, name, 1);
                break;
            case 2:  // 修正：case 和数字之间要有空格
                worker = new Manager(id, name, 2);
                break;  // 修正：添加break语句
            case 3:  // 修正：case 和数字之间要有空格
                worker = new Boss(id, name, 3);
                break;
            default:
                break;
            }
            newSpace[this->m_EmpNum + i] = worker;
        }
        // 释放原有的空间
        delete[] this->m_EmpArray;

        // 更改新空间的指向
        this->m_EmpArray = newSpace;

        // 更新新的个数
        this->m_EmpNum = newSize;

        // 更新职工不为空的标志
        this->m_FileIsEmpty = false;

        // 保存到文件中
        this->save();

        cout << "成功添加" << addNum << "名新职工" << endl;
    }
    else
    {
        cout << "输出有误" << endl;
    }

    system("pause");
    system("cls");
}

void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << " "
            << endl;
    }
    ofs.close();
}

int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        num++;
    }
    ifs.close();
    return num;
}

void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0;  // 修正：初始化index为0
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker* worker = NULL;
        if (dId == 1)
        {
            worker = new Employee(id, name, dId);  // 修正：变量名改为小写worker
        }
        else if (dId == 2)
        {
            worker = new Manager(id, name, dId);
        }
        else
        {
            worker = new Boss(id, name, dId);
        }
        this->m_EmpArray[index] = worker;
        index++;
    }
    ifs.close();
}

void WorkerManager::Show_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或者记录为空!" << endl;
    }
    else
    {
        for (int i = 0; i < m_EmpNum; i++)
        {
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}

int WorkerManager::IsExist(int id)
{
    int index = -1;

    for (int i = 0; i < this->m_EmpNum; i++)
    {
        if (this->m_EmpArray[i]->m_Id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

void WorkerManager::Del_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或者记录为空!" << endl;
    }
    else
    {
        cout << "请输入想要删除的职工号:" << endl;

        int id = 0;
        cin >> id;
        int index = this->IsExist(id);
        if (index != -1)  // 修正：应该是 index != -1
        {
            for (int i = index; i < this->m_EmpNum - 1; i++)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--;
            this->save();
            cout << "删除成功!" << endl;
        }
        else
        {
            cout << "删除失败，未找到该职工" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::Mod_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或者记录为空" << endl;
    }
    else
    {
        cout << "请输入修改职工的编号" << endl;
        int id;
        cin >> id;
        int ret = this->IsExist(id);
        if (ret != -1)
        {
            delete this->m_EmpArray[ret];

            int newId = 0;
            string newName = "";
            int dSelect = 0;

            cout << "查到:" << id << "号职工,请输入新的职工号:" << endl;
            cin >> newId;

            cout << "请输入新姓名:" << endl;
            cin >> newName;
            cout << "请输入岗位:" << endl;
            cout << "1.普通职工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> dSelect;

            Worker* worker = NULL;
            switch (dSelect)
            {
            case 1:  // 修正：case 和数字之间要有空格
                worker = new Employee(newId, newName, dSelect);
                break;
            case 2:  // 修正：case 和数字之间要有空格
                worker = new Manager(newId, newName, dSelect);
                break;
            case 3:  // 修正：case 和数字之间要有空格
                worker = new Boss(newId, newName, dSelect);  // 修正：new Name应该是newName
                break;
            default:
                break;
            }
            this->m_EmpArray[ret] = worker;
            cout << "修改成功!" << endl;
            this->save();
        }
        else
        {
            cout << "修改失败，查无此人" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::Find_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或者记录为空!" << endl;
    }
    else
    {
        cout << "请输入查找的方式:" << endl;
        cout << "1.按职工编号查找" << endl;
        cout << "2.按姓名查找" << endl;

        int select = 0;
        cin >> select;

        if (select == 1)
        {
            int id;
            cout << "请输入查找的职工编号:" << endl;
            cin >> id;

            int ret = IsExist(id);
            if (ret != -1)  // 修正：应该是 ret != -1
            {
                cout << "查找成功,该职工的信息如下:" << endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else
            {
                cout << "查找失败,查无此人" << endl;
            }
        }
        else if (select == 2)
        {
            string name;
            cout << "请输入查找的姓名:" << endl;
            cin >> name;

            bool flag = false;
            for (int i = 0; i < m_EmpNum; i++)
            {
                if (m_EmpArray[i]->m_Name == name)  // 修正：Arrat应该是Array
                {
                    cout << "查找成功,职工编号为:"
                        << m_EmpArray[i]->m_Id
                        << "号的信息如下:" << endl;

                    flag = true;
                    this->m_EmpArray[i]->showInfo();
                }
            }
            if (flag == false)
            {
                cout << "查找失败,查无此人" << endl;
            }
        }
        else
        {
            cout << "输入选项有误" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::Sort_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或者记录为空!" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "请选择排序的方式:" << endl;
        cout << "1.按职工号进行升序" << endl;
        cout << "2.按职工号进行降序" << endl;

        int select = 0;
        cin >> select;

        for (int i = 0; i < m_EmpNum; i++)
        {
            int minOrMax = i;
            for (int j = i + 1; j < m_EmpNum; j++)  // 修正：j++ 不是 i++
            {
                if (select == 1)  // 升序
                {
                    if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)  // 修正：升序应该是大于号
                    {
                        minOrMax = j;
                    }
                }
                else if (select == 2)  // 降序
                {
                    if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id)
                    {
                        minOrMax = j;
                    }
                }
            }
            if (i != minOrMax)
            {
                Worker* temp = m_EmpArray[i];
                m_EmpArray[i] = m_EmpArray[minOrMax];
                m_EmpArray[minOrMax] = temp;
            }
        }
        cout << "排序成功，结果为:" << endl;
        this->save();
        this->Show_Emp();
    }
}

void WorkerManager::Clean_File()
{
    cout << "确认清空?" << endl;
    cout << "1.确认" << endl;
    cout << "2.返回" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if (this->m_EmpArray[i] == NULL)  // 修正：赋值=改为比较==
                {
                    delete this->m_EmpArray[i];
                }
            }
            this->m_EmpNum = 0;
            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_FileIsEmpty = true;
        }
        cout << "清空成功!" << endl;
    }
    system("pause");
    system("cls");
}