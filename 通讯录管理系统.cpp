#include<iostream>
#include<string>
using namespace std;

#define MAX 1000

//联系人结构体

struct Person{
	string m_name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_addr;
};
//通讯录结构体

struct Addressbooks{
	struct Person personArray[MAX];
	int m_size;
};

//菜单界面

void showmenu(){
	cout<<"************************"<<endl;
	cout<<"************************"<<endl;
	cout<<"***** 1.添加联系人 *****"<<endl;
	cout<<"***** 2.显示联系人 *****"<<endl;
	cout<<"***** 3.删除联系人 *****"<<endl;
	cout<<"***** 4.查找联系人 *****"<<endl;
	cout<<"***** 5.修改联系人 *****"<<endl;
	cout<<"***** 6.清空联系人 *****"<<endl;
	cout<<"***** 0.退出通讯录 *****"<<endl;
	cout<<"************************"<<endl;
	cout<<"************************"<<endl;
}

//添加联系人

void addPerson(Addressbooks *abs){
	if(abs->m_size==MAX){
		cout<<"通讯录已满，不能再添加."<<endl;
		return;
	}
	string name;
	cout<<"请输入姓名:"<<endl;
	cin>>name;
	abs->personArray[abs->m_size].m_name=name;
	
	int sex=0;
	cout<<"请输入性别(1-男 2-女)："<<endl;
	while(true){
		cin>>sex;
		if(sex==1||sex==2){
			abs->personArray[abs->m_size].m_sex=sex;
			break;
		}
		cout<<"输入有错误，请重新输入："<<endl;
	}
	
	int age=0;
	cout<<"请输入年龄:"<<endl;
	cin>>age;
	abs->personArray[abs->m_size].m_age=age;
	
	string phone;
	cout<<"请输入联系电话："<<endl;
	cin>>phone;
	abs->personArray[abs->m_size].m_phone=phone;
	
	string addr;
	cout<<"请输入地址:"<<endl;
	cin>>addr;
	abs->personArray[abs->m_size].m_addr=addr;
	
	abs->m_size++;
	cout<<"添加成功."<<endl;
	system("pause");
	system("cls");
}

//检查联系人是否存在（返回位置若不存在则返回-1

int isExist(Addressbooks*abs,string name){
	for(int i=0;i<abs->m_size;i++){
		if(abs->personArray[i].m_name==name){
			return i;
		}
	}
	return -1;/**why**/
}

//查找联系人

void findPerson(Addressbooks*abs){
	cout<<"请输入你要查找的联系人:"<<endl;
	string name;
	cin>>name;
	
	int ret=isExist(abs,name);
	if(ret!=-1){
		cout<<"姓名："<<abs->personArray[ret].m_name<<"\t";
		cout<<"性别："<<(abs->personArray[ret].m_sex==1?"男":"女")<<"\t"; //若sex为1则返回男否则返回女
		cout<<"年龄:"<<abs->personArray[ret].m_age<<"\t";
		cout<<"电话："<<abs->personArray[ret].m_phone<<"\t";
		cout<<"住址："<<abs->personArray[ret].m_addr<<endl;
	}else{
		cout<<"查无此人."<<endl;
	}
	system("pause");
	system("cls");
}

//删除联系人

void deletePerson(Addressbooks*abs){
	cout<<"请输入要删除的联系人："<<endl;
	string name;
	cin>>name;
	
	int ret=isExist(abs,name);
	if(ret!=-1){
		for(int i=ret;i<abs->m_size;i++){
			abs->personArray[i]=abs->personArray[i+1];
		}
		abs->m_size--;
		cout<<"删除成功."<<endl;
	}else{
		cout<<"查无此人."<<endl;
	}
	system("pause");
	system("cls");
}
//查找联系人

void modifyPerson(Addressbooks*abs){
	cout<<"请输入你要修改的联系人:"<<endl;
	string name;
	cin>>name;
	
	int ret=isExist(abs,name);
	if(ret!=-1){
		string name;
		cin>>name;
		
		int ret=isExist(abs,name);
		if(ret!=-1){
			string name;
			cout<<"请输入姓名:"<<endl;
			cin>>name;
			abs->personArray[ret].m_name=name;
			
			int sex=0;
			cout<<"(请输入性别.1-男 2-女)"<<endl;
			while(true){
				cin>>sex;
				if(sex==1||sex==2){
					abs->personArray[ret].m_sex=sex;
					break;
				}
				cout<<"输入有错误，请重新输入."<<endl;
			}
			int age=0;
			cout<<"请输入年龄"<<endl;
			cin>>age;
			abs->personArray[ret].m_age=age;
			
			string phone;
			cout<<"请输入联系的电话:"<<endl;
			cin>>phone;
			abs->personArray[ret].m_phone=phone;
			
			string address;
			cout<<"请输入家庭地址："<<endl;
			cin>>address;
			abs->personArray[ret].m_addr=address;
			cout<<"修改成功"<<endl;
		}
		else{
			cout<<"查无此人."<<endl;
		}
	}
	system("pause");
	system("cls");
}

//显示所有的联系人

void showPerson(Addressbooks*abs){
	if(abs->m_size==0){
		cout<<"当前记录为空."<<endl;
	}
	else{
		for(int i=0;i<abs->m_size;i++){
			//此处的制表符也要加上“”
			//三目运算注意括号
			cout<<"姓名："<<abs->personArray[i].m_name<<"\t";
			cout<<"性别："<<(abs->personArray[i].m_sex==1?"男":"女")<<"\t";//若sex为1则返回男否则返回女
			cout<<"年龄:"<<abs->personArray[i].m_age<<"\t";
			cout<<"电话："<<abs->personArray[i].m_phone<<"\t";
			cout<<"住址："<<abs->personArray[i].m_addr<<endl;
		}
	}
	system("pause");
	system("cls");
}

//清空联系人

void cleanPerson(Addressbooks*abs){
	abs->m_size=0;
	cout<<"通讯录已经清空了."<<endl;
	system("pause");
	system("cls");
}

int main()
{
	Addressbooks abs;
	abs.m_size=0;
	
	int select=0;
	
	while(true){
		showmenu();
		cin>>select;
		switch (select) {
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
			cout<<"欢迎下次的使用."<<endl;
			system("pause");
			return 0;
		default:
			cout<<"输入错误，请重新输入"<<endl;
			system("pause");
			system("cls");
			break;
		}
	}

	return 0;
}
