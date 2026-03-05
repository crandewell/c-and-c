#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node*left;
	Node*right;
	
	//构造函数====为什么，什么语法
	Node(int val):data(val),left(nullptr),right(nullptr){}
};


//二叉搜索树类
class BinarySearchTree
{
private:
	Node*root;//根节点指针
	//私有辅助函数
	//插入节点（内部递归的版本）
	
	void insert(Node* &node,int val)//这俩参数
	{
		if(node==nullptr)	//若当前的子树为空则创建一个新的节点
		{
			node=new Node(val);
			return;
		}
		if(val<node->data)//传入的值小于当前的节点则插入左子树
		{
			insert(node->left,val);
		}
		else if(val>node->data)//值大于当前节点则插入右子树,这是为啥
		{
			insert(node->right,val);
		}
		//如果相等则可以不插入
	}
	//查找节点（内部递归）
	bool search(Node*node,int val)const
	{
		if(node==nullptr)
		{
			return false;
		}
		else if(val==node->data)
		{
			return true;
		}
		else if(val<node->data)
		{
			return search(node->left,val);//小于当前节点则在左子树中查找
		}
		else
		{
			return search(node->right,val);//大于当前的节点在右子树中查找
		}
	}
	//中序遍历 左-根-右
	void inorder(Node*node)const
	{
		if(node==nullptr)
		{
			return;
		}
		inorder(node->left);//什么意思
		cout<<node->data<<" ";
		inorder(node->right);
	}
	
	//前序遍历
	void preorder(Node*node)const
	{
		if(node==nullptr)
		{
			return;
		}
		cout<<node->data<<" ";
		preorder(node->left);
		preorder(node->right);
		cout<<"node->data"<<" ";
	}
	//后序遍历
	void postorder(Node* node)const
	{
		if(node==nullptr)
		{
			return;
		}
		postorder(node->left);
		postorder(node->right);
		cout<<node->data<<" ";
	}
	//释放整棵树的内存(递归删除节点)
	void clear(Node* node)
	{
		if(node==nullptr)
		{
			return;
		}
		clear(node->left);
		clear(node->right);
		delete node;
	}
	//计算树的高度（最大深度）
	int height(Node*node)const
	{
		if(node==nullptr)
		{
			return 0;
		}
		int leftHeight=height(node->left);
		int rightHeight=height(node->right);
		return max(leftHeight,rightHeight)+1;
	}
	//统计树中的节点总数
	int countNodes(Node*node)const
	{
		if(node==nullptr)
		{
			return 0;
		}
		return 1+countNodes(node->left)+countNodes(node->right);
	}
public:
	//构造函数：初始化空树
	BinarySearchTree():root(nullptr){}
	
	~BinarySearchTree()
	{
		clear(root);
	}
	//公有接口：查找值是否存在
	bool search(int val)const
	{
		return search(root,val);
	}
	//公有接口:中序遍历(打印)
	void inorder()const
	{
		cout<<"中序遍历"<<endl;
		inorder(root);
		cout<<endl;
	}
	//公有接口：后序遍历(打印)
	void postorder()const
	{
		cout<<"后序遍历:";
		postorder(root);
		cout<<endl;
	}
	void preorder()const
	{
		cout<<"前序遍历"<<endl;
		preorder(root);
		cout<<endl;
	}
	//公有接口: 获取树的高度
	int height()const
	{
		return height(root);
	}
	//公有节点：获取节点的总数
	int countNodes()const
	{
		return countNodes(root);
	}
	void insert(int val)
	{
		insert(root,val);
	}
};

//主函数演示二叉树的基本用法
int main()
{
	BinarySearchTree bst;
	//插入一些测试数据
	int values[]={50,30,70,20,40,60,80};
	for(int v:values)//这又是什么表达
	{
		bst.insert(v);
	}
	//遍历输出
	bst.preorder();
	bst.inorder();
	bst.postorder();
	//查找测试
	int key=40;
	if(bst.search(key))
	{
		cout<<"找到元素"<<key<<endl;
	}
	else
	{
		cout<<"未找到元素"<<key<<endl;
	}
	
	key=100;
	if(bst.search(key))
	{
		cout<<"找到元素"<<key<<endl;
	}
	else
	{
		cout<<"未找到元素"<<key<<endl;
	}
	//树的基本信息
	cout<<"树的高度:"<<bst.height()<<endl;
	cout<<"节点总数:"<<bst.countNodes()<<endl;
	cin.get();
	return 0;
}
