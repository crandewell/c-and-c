#include<iostream>
#include<string>
using namespace std;

const int MAX_STR=100;

//定义图书结构体
struct Book
{
	string ISBN;//图书的编号
	string title;//书名
	string author;//作者
	double price;//价格
	int quantity;//库存数量
	
	Book* next;//指向下一本书，书类的指针
	
	Book()
	{
		next=nullptr;//和null有什么区别
		price=0.0;
		quantity=0;
	}
};
//图书管理系统
class BookSystem
{
private://为什么要加私人作用
	Book* head;
	int count;//图书的数量
public:
	
	BookSystem()
	{
		head=nullptr;
		count=0;
	}
	
	~BookSystem()
	{
		clearAll();//这个函数的实现是库函数吗
	}
	
	void showMenu()
	{
		cout << "\n===== 图书管理系统 =====" << endl;
		cout << "1. 添加图书" << endl;
		cout << "2. 删除图书" << endl;
		cout << "3. 修改图书" << endl;
		cout << "4. 查找图书" << endl;
		cout << "5. 显示所有图书" << endl;
		cout << "6. 显示统计信息" << endl;
		cout << "7. 按书名查找" << endl;
		cout << "8. 按作者查找" << endl;
		cout << "0. 退出系统" << endl;
		cout << "请选择操作: ";
	}
	
	//添加图书
	void addBook()
	{
		Book* newBook=new Book;
		
		cout<<"\n---添加图书---"<<endl;//hyw报错
		cout<<"请输入ISBN号";
		cin>>newBook->ISBN;//操作符 . 何时用，此处指针是箭头
		
		//检查是否已经存在
		if(findBookByISBN(newBook->ISBN))
		{
			cout<<"错误，该ISBN已经存在"<<endl;
			delete newBook;
			return;
		}
		
		cout<<"请输入书名"<<endl;
		//下面的用法语法不清楚，返回来总结------》在C++中，当混合使用 cin >> 和 getline() 时，会遇到输入缓冲区的问题
		//因为cin会在缓冲区内留下\n换行符，但是getline遇到\n要结束
		cin.ignore();//什么函数---->cin的成员函数
		getline(cin,newBook->title);
		
		cout<<"请输入作者"<<endl;
		cin.ignore();
		getline(cin,newBook->author);//读取前面给了后者
		
		cout<<"请输入价格"<<endl;
		cin>>newBook->price;
		
		cout<<"请输入库存数量"<<endl;
		cin>>newBook->quantity;
		
		//插入到链表的头部
		newBook->next=head;//因为改变的是指针走向，而不是结点的本身
		head=newBook;
		count++;
		
		cout<<"添加成功"<<endl;
	}
	
	//删除图书
	void deleteBook()
	{
		if(head==nullptr)
		{
			cout<<"图书库为空!"<<endl;
			return;
		}
		
		string isbn;
		cout<<"\n----删除图书----"<<endl;
		cout<<"请输入要删除的图书ISBN"<<endl;
		cin>>isbn;
		
		Book* current=head;  //这一段也要注意               
		Book* prev=nullptr;
		
		while(current!=nullptr)
		{
			if(current->ISBN==isbn)
			{
				if(prev==nullptr)//这是何意味
				{
					//删除头结点
					head=current->next;
				}
				else
				{
					prev->next=current->next;
				}
				
				delete current;
				count--;
				cout<<"删除成功!"<<endl;
				return;
			}
			prev=current;
			current=current->next;
		}
		cout<<"未找到该图书！"<<endl;
	}
	
	//修改图书
	void modifyBook()
	{
		if(head==nullptr)
		{
			cout<<"图书库为空!"<<endl;//头空则整体空
			return;
		}
		string isbn;
		cout<<"\n----修改图书----"<<endl;
		cout<<"请输入要修改的图书ISBN"<<endl;
		cin>>isbn;
		
		Book* book=findBookByISBN(isbn);
		
		if(book==nullptr)
		{
			cout<<"未找到该图书!"<<endl;
			return;
		}
		
		cout<<"\n当前图书信息:"<<endl;
		showBookInfo(book);
		
		cout<<"\n请输入新信息"<<endl;
		cout<<"书名为:"<<book->title<<endl;
		cin.ignore();//这个库函数什么意思
		
		string temp;
		getline(cin,temp);
		if(!temp.empty())
		{
			book->title=temp;
		}
		cout<<"作者:"<<book->author<<endl;
		
		getline(cin,temp);
		if(!temp.empty())
		{
			book->author=temp;//为啥temp用了两次，这是什么意思，其实两次getline是两次读入
		}
		
		cout<<"价格:"<<book->price<<endl;
		string priceStr;
		getline(cin,priceStr);//因为你输入的时候string类型，要输出数字只能getline
		if(!priceStr.empty())
		{
			book->price=stod(priceStr);//就是相当于输入了
		}
		
		cout<<"库存:"<<book->quantity<<endl;
		string qtyStr;//记住什么是指针，而什么是对象，确定操作符的使用
		getline(cin,qtyStr);
		if(!qtyStr.empty())
		{
			book->quantity=stoi(qtyStr);
		}
		cout<<"修改成功"<<endl; 
	}
	//按ISBN查找图书
	void searchByISBN()
	{
		if(head==nullptr)
		{
			cout<<"图书库为空!"<<endl;
			return;
		}
		string isbn;
		cout<<"\n----按ISBN查找图书----"<<endl;
		cout<<"请输入查找的图书ISBN:"<<endl;
		cin>>isbn;
		
		Book* book=findBookByISBN(isbn);
		if(book!=nullptr)
		{
			cout<<"\n找到图书"<<endl;
			showBookInfo(book);
		}
		else
		{
			cout<<"未找到该图书!"<<endl;
		}
	}
	//按照书名进行查找
	void searchByTitle()
	{
		if(head==nullptr)
		{
			cout<<"图书库为空!"<<endl;
			return;
		}
		
		string title;
		cout<<"\n请输入要查找的书名(或部分书名)"<<endl;
		cin.ignore();
		getline(cin,title);
		
		bool found=false;
		Book* current=head;
		
		while(current!=nullptr)
		{
			//查找字符串的部分匹配
			if(current->title.find(title)!=string::npos)//这一句什么意思// npos 是 string 类的一个静态常量, 表示"不存在的位置
            {
				if(!found)//bool found=false;
				{
					cout<<"\n找到以下的图书:"<<endl;
				}
				showBookInfo(current);
				found=true;
			}              
			current=current->next;
		}
		if(!found)//意思是循环以后如果还是false那么就是没找到
		{
			cout<<"未找到相关图书!"<<endl;
		}
	}
	
	//按作者查找
	void searchByAuthor()
	{
		if(head==nullptr)
		{
			cout<<"图书库为空!"<<endl;
			return;
		}
		//学习这种按部分查找
		string author;
		cout<<"\n---按作者查书---"<<endl;
		cout<<"请输入要查找的作者(或者部分作者名)"<<endl;
		cin.ignore();
		getline(cin,author);
		
		bool found=false;
		Book* current=head;
		
		while(current!=nullptr)
		{
			if(current->author.find(author)!=string::npos)
			{
				if(!found)//这个found哪来的
				{
					cout<<"\n找到以下的图书"<<endl;
				}
				showBookInfo(current);
				found=true;
			}
			current=current->next;
		}
		if(!found)
		{
			cout<<"未找到相关图书!"<<endl;
		}
	}
	
	void showAllBooks()
	{
		if(head==nullptr)
		{
			cout<<"图书库为空~"<<endl;
			return;
		}
		cout<<"\n-----所有的图书-----"<<endl;
		cout<<"共"<<count<<"本图书"<<endl;
		cout<<"==========================="<<endl;
		
		Book* current=head;
		int index=1;
		while(current!=nullptr)
		{
			cout<<"["<<index<<"]"<<endl;
			showBookInfo(current);
			current=current->next;
			index++;
		}
	}
	//显示统计信息
	void showStats()
	{
		cout<<"\n---统计信息---"<<endl;
		cout<<"图书总数:"<<endl;
		
		if(head==nullptr)
		{
			return;
		}
		
		//计算总价值和平均的价格
		double totalValue=0;
		double totalPrice=0;
		Book* current=head;
		
		while(current!=nullptr)
		{
			totalValue+=current->price*current->quantity;
			totalPrice+=current->price;
			current=current->next;
		}
		double avgPrice=(count>0)?totalPrice/count:0;
		
		cout<<"图书总价值:"<<totalValue<<endl;
		cout<<"平均价格:"<<avgPrice<<endl;
		//查找最贵的书和最便宜的书
		current=head;
		Book* mostExpensive=head;
		Book* mostcheapest=current;
		
		while(current!=nullptr)
		{
			if(current->price>mostExpensive->price)
			{
				mostExpensive=current;
			}
			if(current->price<mostcheapest->price)
			{
				mostcheapest=current;
			}
			current=current->next;
		}
		cout<<"最贵的书:"<<endl;
		cout<<"最便宜的书:"<<endl;
	}
	
	//清空所有的图书
	void clearAll()
	{
		Book* current=head;
		while(current!=nullptr)
		{
			Book* temp=current;
			current=current->next;
			delete temp;
		}
		head=nullptr;
		count=0;
		cout<<"已经清空所有图书!"<<endl;
	}
private:
	//根据isbn来查找图书
	Book* findBookByISBN(const string &isbn)
	{
		Book* current=head;
		while(current!=nullptr)
		{
			if(current->ISBN==isbn)
			{
				return current;
			}
			current=current->next;
		}
		return nullptr;
	}
	
	//显示单本图书的信息
	void showBookInfo(Book* book)
	{
		if(book==nullptr)
		{
			return;
		}
		cout<<"ISBN:"<<book->ISBN<<endl;
		cout<<"书名:"<<book->title<<endl;
		cout<<"作者:"<<book->author<<endl;
		cout<<"价格:"<<book->price<<endl;
		cout<<"库存:"<<book->quantity<<endl;
		cout<<"---------------------------------------"<<endl;
	}
};

//主函数
int main()
{
	BookSystem booksystem;
	
	int choice;
	
	do{
		booksystem.showMenu();
		cin>>choice;
	switch (choice) {
	case 1:
		booksystem.addBook();
		break;
	case 2:
		booksystem.deleteBook();
		break;
	case 3:
		booksystem.deleteBook();
		break;
	case 4:
		booksystem.searchByISBN();
		break;
	case 5:
		booksystem.showAllBooks();
		break;
	case 6:
		booksystem.showStats();
		break;
	case 7:
		booksystem.searchByTitle();
		break;
	case 8:
		booksystem.searchByAuthor();
		break;
	case 0:
		cout<<"感谢使用，再见"<<endl;
	default:
		cout<<"无效的选择，请重新输入"<<endl;
	}
	}	
	while(choice!=0);//这个switch while语句比较新奇，可以用于选择的循环控制
	return 0;
}
