#include<iostream>
using namespace std;
//1.定义结构体:结点
struct Node
{
	int data;//节点存储的数据
	Node* next;//指向下一个节点的数据
	//构造函数：创建新节点时候初始化
	Node(int value)
	{
		data=value;//设置节点的数据
		next=nullptr;//nullptr  c++11中关键字，用来表示一个空指针，新结点默认不指向任何节点
	}
};
//2.创建链表类
class LinkedList
{
private:
	Node* head;//链表的头指针，指向的是第一个节点
public:
	//构造函数初始化空链表
	LinkedList()
	{
		head=nullptr;//空链表是头指针不指向任何结点
		cout<<"初始状态为空的链表创建成功！"<<endl;
	}
	//核心方法1.判断链表是否为空
	bool isEmpty()
	{
		//原理在于如果头指针为nullptr，说明链表为空
		return head==nullptr;//这就判断了，若是头为空的，那么就是空的才对
	}
	
	
	//法2:在链表的末尾添加节点
	void append(int value)
	{//创建一个新的结点
		Node*newNode=new Node(value);//new的操作规则
		//情况1：如果链表为空
		if(isEmpty())
		{
			head=newNode;//新结点成为了第一个结点
			cout<<"添加了第一个结点，数据为："<<value<<endl;
		}
		else//情况2：链表不为空，需要找到最后一个结点
		{
			Node* temp=head;//从头开始
			//遍历找到最后一个节点，特征为next指针为nullptr
			while(temp->next!=nullptr)
			{
				temp=temp->next;
			}
			temp->next=newNode;//现在temp指向了最后一个节点，将新结点链接到最后一个结点后
			cout<<"在末尾添加了新结点，数据为："<<value<<endl;
		}
	}
	//方法3:在链表的开头添加节点
	void prepend(int value)
	{
		Node* newNode=new Node(value);
		//新结点的next指向原来的第一个节点
		newNode->next=head;
		//头指针指向新节点
		head=newNode;
		cout<<"在开头添加了新的节点，数据为："<<value<<endl;
	}
	//法4:显示链表的所有结点
	void display()
	{
		if(isEmpty())
		{
			cout<<"链表为空!"<<endl;
			return;
		}
		cout<<"链表的内容";
		Node* temp=head;
		while(temp!=nullptr)
		{
			cout<<temp->data<<"->";//输出的是它的数据即可
			temp=temp->next;
		}
		cout<<"NULL"<<endl;//表示链表的结束
	}
	//法5：获取链表的长度
	int getLength()
	{
		int count=1;//计数器
		Node* temp=head;
		while(temp!=nullptr)
		{
			count++;//起始值0为操作次数，但是应该是长度才对，起始值不应该是1吗
			temp=temp->next;
		}
		return count;
	}
	//法6：删除头结点
	void deleteFirst()
	{
		if(isEmpty())
		{
			cout<<"链表为空，无法删除！"<<endl;
			return;
		}
		Node* temp=head;//临时保存要删除的结点
		head=head->next;//next是结构体结点定义的东西，让头指针指向第二个结点
		cout<<"删除了头节点，数据为:"<<temp->data<<endl;
		delete temp;
	}
	//法7：删除尾结点
	void deleteLast()
	{
		if(isEmpty())
		{
			cout<<"链表为空，无法删除!"<<endl;
			return;
		}
		//特殊情况是只有一个结点的时候
		if(head->next==nullptr)
		{
			cout<<"删除了唯一的一个结点，数据为:"<<head->data<<endl;
			delete head;
			head=nullptr;//非得是两步么
			return;//这是回到哪里了
		}
		//找到倒数第二个结点
		Node* temp=head;
		while(temp->next->next!=nullptr)//如果是==什么后果
		{
			temp=temp->next;
		}
		//现在temp是倒数第二个节点
		temp->next=nullptr;//作图解释
	}
	//法8：查找元素是否存在
	bool search(int value)
	{
		Node* temp=head;
		while(temp!=nullptr)
		{
			if(temp->data==value)
			{
				return true;
			}
			temp=temp->next;
		}
		return false;
	}
	//法9：插入结点到指定的位置，从0来开始
	void insertAt(int value,int position)
	{
		if(position<0||position>getLength())
		{
			cout<<"插入的位置无效!"<<endl;
		}
		if(position==0)
		{
			prepend(value);
			return;
		}
		if(position==getLength())
		{
			append(value);
			return;
		}
		Node* newNode=new Node(value);
		Node* temp=head;
		
		//找到要插入的位置的前一个结点
		for(int i=0;i<position-1;i++)
		{
			temp=temp->next;
		}
		temp->next=newNode;
		cout<<"在位置"<<position<<"插入了结点，数据为:"<<value<<endl;
		
	}
	//法10：删除指定位置的结点
	void deleteAt(int position)
	{
		if(isEmpty())
		{
			cout<<"链表为空，无法进行删除!"<<endl;
			return;
		}
		if(position<0||position>=getLength())
		{
			cout<<"删除位置是无效的!"<<endl;
			return;
		}
		if(position==0)
		{
			deleteFirst();
			return;
		}
		Node* temp=head;
		//找到要删除结点的前一个结点
		for(int i=0;i<position-1;i++)
		{
			temp=temp->next;
		}
		Node* nodeToDelete=temp->next;
		temp->next=nodeToDelete->next;//转接链表的这一个结点，与后续的作链接
		cout<<"删除了位置为"<<position<<"的结点，其数据为:"<<nodeToDelete->data<<endl;
		delete nodeToDelete;
		//是否有必要将其置为空指针呢？
	}
	//法11：获取指定位置的结点数据
	int getDataAt(int position)
	{
		if(isEmpty()||position<0||position>=getLength())//为啥是大于等于
		{
			cout<<"位置是无效的"<<endl;
			return -1;//此处-1表示无效，不能直接return，和函数有没有返回值有关系
		}
		Node* temp=head;
		for(int i=0;i<position;i++)//找到指定位置结点
		{
			temp=temp->next;
		}
		return temp->data;
	}
	//法12：反转链表---------注意理解
	void reverse()
	{
		if(isEmpty()||head->next==nullptr)//注意前者是全空，而后者是只有一个结点
		{
			return;//空链表或者是只有一个结点，不需要反转
		}
		Node* prev=nullptr;
		Node*current=head;
		Node* next=nullptr;//这三个hyw
		
		while(current!=nullptr)
		{
			next=current->next;
			current->next=prev;//利用图像表示
			prev=current;
			current=next;
		}
		head=prev;
		cout<<"链表已经反转"<<endl;
	}
	~LinkedList()
	{
		cout<<"\n清理链表的内存"<<endl;
		//删除所有的结点
		while(!isEmpty())
		{
			deleteFirst();
		}
	}
};
//测试函数的编写
void testLinkedList()
{
	cout<<"测试开始"<<endl;
	LinkedList myList;
	//2.测试空链表
	cout<<"\n--1:空链表的时候"<<endl;
	cout<<"链表是否为空？"<<(myList.isEmpty()?"是":"否")<<endl;//注意三目运算整体加上（）不然不好读
	//3.添加第一个结点
	cout<<"\n--2:添加第一个结点的时候"<<endl;
	myList.append(10);
	cout<<"链表是否为空"<<(myList.isEmpty()?"是":"否")<<endl;
	cout<<"链表的长度为:"<<myList.getLength()<<endl;
	myList.display();//显示链表的所有结点
	//4.添加更多的结点
	cout<<"\n--3:添加更多的结点"<<endl;
	myList.append(20);
	myList.prepend(50);
	myList.prepend(15);
	cout<<"链表是否为空"<<(myList.isEmpty()?"是":"否")<<endl;
	cout<<"链表的长度为:"<<myList.getLength()<<endl;
	myList.display();
	//5.删除结点
	cout<<"\n4--删除结点的测试"<<endl;
	myList.deleteFirst();
	myList.deleteLast();
	cout<<"链表是否为空"<<(myList.isEmpty()?"是":"否")<<endl;
	cout<<"链表的长度为:"<<myList.getLength()<<endl;
	myList.display();
	//6.删除所有的结点
	cout<<"\n测试删除所有的"<<endl;
	myList.deleteFirst();
	myList.deleteLast();
	cout<<"链表是否为空"<<(myList.isEmpty()?"是":"否")<<endl;
	cout<<"链表的长度为:"<<myList.getLength()<<endl;
	myList.display();
	cout<<"测试完毕!"<<endl;
	//7.测试删除指定的位置
	cout<<"\n测试7--删除指定位置的结点"<<endl;
	myList.deleteAt(2);
	myList.deleteAt(0);
	cout<<"链表的长度:"<<myList.getLength()<<endl;
	myList.display();
	//8.测试反转链表
	cout<<"\n---8-反转链表"<<endl;
	cout<<"反转前:";
	myList.display();
	myList.reverse();
	cout<<"反转后";
	myList.display();
	//9.测试删除头尾结点
	cout<<"\n测试9---删除头尾结点"<<endl;
	myList.deleteFirst();
	myList.deleteLast();
	cout<<"链表的长度:"<<myList.getLength()<<endl;
	myList.display();
	
	cout<<"链表的测试结束"<<endl;
	
}
//第四步:交互性测试
void interactiveTest()
{
	//非框架的内容
	cout<<"=========链表的交互性测试=========="<<endl;
	LinkedList list;
	int choice,value,position;
	do
	{
	cout << "\n========== 菜单 ==========" << endl;
		cout << "1. 显示链表" << endl;
		cout << "2. 在末尾添加节点" << endl;
		cout << "3. 在开头添加节点" << endl;
		cout << "4. 在指定位置插入节点" << endl;
		cout << "5. 删除头节点" << endl;
		cout << "6. 删除尾节点" << endl;
		cout << "7. 删除指定位置节点" << endl;
		cout << "8. 查找元素" << endl;
		cout << "9. 获取链表长度" << endl;
		cout << "10. 反转链表" << endl;
		cout << "11. 获取指定位置数据" << endl;
		cout << "0. 退出" << endl;
		cout << "请输入选择: ";
		cin >> choice;
		
		switch (choice) {
		case 1:
			list.display();
			break;
		case 2:
			cout<<"请输入要添加的值:";
			cin>>value;
			list.append(value);
			break;
		case 3:
			cout<<"请输入要添加的值:";
			cin>>value;
			list.prepend(value);
			break;
		case 4:
			cout<<"请输入要插入的值:";
			cin>>value;
			cout<<"请输入要插入的位置0--"<<list.getLength()<<"区间"<<endl;//因为这个你可以加在末尾的后一位但是删除必须是已有的，认为这个东西是索引所以从0开始写
			cin>>position;
			list.insertAt(value,position);
			break;
		case 5:
			list.deleteFirst();
		case 6:
			list.deleteLast();
		case 7:
			cout<<"请输入要删除的位置0--"<<list.getLength()-1<<"区间"<<endl;//怎么这个地方要减去1的
		case 8:
			cout<<"请输入要查找的值:";
			cin>>value;
			if(list.search(value))
			{
				cout<<"元素"<<value<<"在链表中"<<endl;
			}
			else
			{
				cout<<"元素"<<value<<"不在链表中"<<endl;
			}
			break;
		case 9:
			cout<<"链表长度为"<<list.getLength()<<endl;
			break;
		case 10:
			list.reverse();
			break;
		case 11:
			cout<<"请输入要获取的数据的位置0--"<<list.getLength()-1<<endl;
			cin>>position;
			value=list.getDataAt(position);
			if(value!=1)
			{
				cout<<"位置"<<position<<"的数据为:"<<value<<endl;
			}
			break;
			
		case 0:
			cout<<"退出交互测试"<<endl;
			break;
		default:
			cout<<"检测到无效的输入，请重新输入"<<endl;
		}
	}while(choice!=0);//用来断定是否是合规的输入

}
int main()
{
	int choice;
	cout<<"=======链表系统======"<<endl;
	cout<<"请选择测试模式"<<endl;
	cout<<"1.自动测试"<<endl;
	cout<<"2.交互测试"<<endl;
	cout<<"请输入选择1，2"<<endl;
	cin>>choice;
	
	if(choice==1)
	{
		testLinkedList();
	}
	else if(choice==2)
	{
		interactiveTest();
	}
	else
	{
		cout<<"无效选择，运行自动测试"<<endl;
		testLinkedList();
	}
	
	system("pause");
	return 0;
}
