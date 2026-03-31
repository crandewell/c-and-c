#include"LinkedList.h"
#include<iostream>

int main()
{
	LinkedList list;

	//插入数据
	list.pushBack(10);
	list.pushBack(20);
	list.pushFront(5);
	list.insertAt(2,15);//在位置2插入15

	std::cout << "链表:";
	list.print();

	//删除操作
	list.removeByValue(10);
	std::cout << "删除10后:";
	list.print();//5-->15-->20

	list.removeAt(2);
	std::cout << "删除位置2后:";
	list.print();

	//修改
	list.updateAt(1,100);
	std::cout << "修改位置1为100";
	list.print();//输出:100--->20

	//查找
	std::cout << "是否包含20?" << (list.contains(20) ? "是" : "否") << std::endl;
	Node* node = list.findNode(20);
	if (node)std::cout << "找到值为20的节点，地址:" << node << std::endl;

	int idx = list.findIndex(20);
	std::cout << "20的下标:" << idx << std::endl;//1
	
	std::cout << "链表长度:" << list.size() << std::endl;//2
	
	return 0;
}