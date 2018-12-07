#include"第二次上机第一题.h"
#include<iostream>
#include<queue>

using namespace std;
BinaryTree<char> *BT;
void Menu();

int main()
{
	Menu();
}

void Menu()
{
	int select;
	int k;
	int item;
	int temp;
	while (1)
	{
		cout << "1.创建二叉树" << endl;
		cout << "2.先根遍历" << endl;
		cout << "3.中根遍历" << endl;
		cout << "4.后根遍历" << endl;
		cout << "5.层次遍历" << endl;
		cout << "6.查看结点个数" << endl;
		cout << "7.树的高度" << endl;
		cout << "8.删除二叉树" << endl;
		cout << "9.插入节点" << endl;
		cout << "10.查看叶子结点" << endl;
		cout << "11.删除指定结点及其左右孩子" << endl;
		cout << "12.查看指定结点的父节点" << endl;
		cout << "13.查找指定结点是否存在" << endl;
		
		
		cin >> select;//必须清除缓存区
		
		if (!std::cin || select == '#')
		{
			cin.clear();
			cin.get();
			cin >> select;
		}

		


		switch (select)
		{
		case 1:
			cout << "按先根遍历顺序输入每个结点的值(#为空)" << endl;
			//A B # C D # # # E F # # #
			BT = new BinaryTree<char>();
			BT->CreateBT(BT->ReturnRoot());
			cout << endl;
			cout << "创建完毕" << endl;
			Menu();
			break;
		case 2:
			cout << "先根遍历:" << endl;
			BT->Preorder(BT->ReturnRoot());
			cout << endl;
			Menu();
			break;
		case 3:
			cout << "中根遍历" << endl;
			BT->Inorder(BT->ReturnRoot());
			cout << endl;
			Menu();
			break;
		case 4:
			cout << "后根遍历" << endl;
			BT->Postorder(BT->ReturnRoot());
			cout << endl;
			Menu();
			break;
		case 5:
			cout << "层次遍历" << endl;
			BT->Levelorder(BT->ReturnRoot());
			cout << endl;
			Menu();
			break;
		case 6:
			cout << "结点个数" << endl;
			cout << BT->GetNodeNumber() << endl;;
			Menu();
			break;
		case 7:
			cout << "树的高度" << endl;
			cout << BT->GetHeight(BT->ReturnRoot()) - 1 << endl;;
			Menu();
			break;
		case 8:
			BT->DeleteBT(BT->ReturnRoot());
			cout << "删除完毕" << endl;
			Menu();
			break;
		case 9:
			cout << "请输入插入结点的值" << endl;
			char insertitem;
			cin >> insertitem;
			cout << "输入被插入结点的值" << endl;
			char inserteditem;
			cin >> inserteditem;
			if (!BT->InsertLL(insertitem, inserteditem))
			{
				cout << "没有该结点" << endl;
			}
			cout << "插入后先根遍历" << endl;
			BT->Preorder(BT->ReturnRoot());
			cout << endl;
			Menu();
			break;
			/*case 9:
				delete(sllisttest);
				cout << "删除完毕" << endl;
				Menu();
				break;*/
		case 10:
			cout << "叶子节点" << endl;
			BT->GetLeaves(BT->ReturnRoot());
			cout << endl;
			Menu();
			break;
		case 11:
			cout << "请输入要删除结点的值" << endl;
			char del;
			cin >> del;
			if (!BT->DST(BT->ReturnRoot(), del))
			{
				cout << "没有该结点" << endl;
			}
			cout << "删除后先根遍历结果" << endl;
			BT->Preorder(BT->ReturnRoot());
			cout << endl;
			Menu();
			break;
		case 12:
			cout << "请输入要查找父节点结点的值" << endl;
			char ch1;
			cin >> ch1;
			if (!BT->Parent(BT->ReturnRoot(), ch1))
			{
				cout << "该结点不存在父节点" << endl;
			}
			if (BT->Parent(BT->ReturnRoot(), ch1))
			{
				cout << "该结点的父节点" << endl;
				cout << BT->Parent(BT->ReturnRoot(), ch1)->Data << endl;
			}
			cout << endl;
			Menu();
			break;
		case 13:
			cout << "请输入要查找结点的值" << endl;
			char ch2;
			cin >> ch2;
			if (!BT->Find(BT->ReturnRoot(), ch2))
			{
				cout << "该结点不存在" << endl;
			}
			if (BT->Find(BT->ReturnRoot(), ch2))
			{
				cout << "该结点存在" << endl;
			}
			cout << endl;
			Menu();
			break;
		default:
			break;
		}
		
	}
}


/*void Menu()
{
	BT = new BinaryTree<char>();
	BT->CreateBT(BT->ReturnRoot());
	cout << "先根遍历" << endl;
	BT->Preorder(BT->ReturnRoot());
	cout << endl;
	cout << "中跟遍历" << endl;
	BT->Inorder(BT->ReturnRoot());
	cout << endl;
	cout << "后跟遍历" << endl;
	BT->Postorder(BT->ReturnRoot());
	cout << endl;
	cout << "层次遍历" << endl;
	BT->Levelorder(BT->ReturnRoot());
	cout << endl;
	cout << "结点个数" << endl;
	cout << BT->GetNodeNumber();
	cout << endl;
	cout << "树的深度" << endl;
	cout << BT->GetHeight(BT->ReturnRoot()) -1;
	cout << endl;
}*/

template<typename T>
BinaryTree<T>::BinaryTree()
{
	Root = new BinaryTreeNode<T>();
	Root->Left = new BinaryTreeNode<T>();
	Root->Right = new BinaryTreeNode<T>();
	NodeNumber = 0;
	Height = 0;
}

template<typename T>
BinaryTree<T>::BinaryTree(T &item)
{
	Root = new BinaryTreeNode<T>();
	Root->Data = item;
	Root->Left = new BinaryTreeNode<T>();
	Root->Right = new BinaryTreeNode<T>();
	NodeNumber = 0;
	Height = 0;
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
	delete Root;
}

template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::CreateBT(BinaryTreeNode<T> *root)
{
	//BinaryTreeNode<T> *Tempnode = root;
	T nodedata;
	cin >> nodedata;
	
	if (nodedata == '#')//如果输入#则将该结点设为空
	{
		root = nullptr;
	}
	else
	{
		if (!root)
		{
			root = new BinaryTreeNode<T>();
		}
		NodeNumber++;
		root->Data = nodedata;
		root->Left = CreateBT(root->Left);
		root->Right = CreateBT(root->Right);
	}
	return root;
}

template<typename T>
void BinaryTree<T>::Preorder(BinaryTreeNode<T> *root)const//先根遍历
{
	if (root)
	{
		cout << root->Data << " ";
		Preorder(root->Left);//递归遍历左子结点
		Preorder(root->Right);//递归遍历右子结点
	}
}

template<typename T>
void BinaryTree<T>::Inorder(BinaryTreeNode<T> *root)const//中根遍历
{
	if (root)
	{
		Inorder(root->Left);
		cout << root->Data << " ";
		Inorder(root->Right);
	}
}

template<typename T>
void BinaryTree<T>::Postorder(BinaryTreeNode<T> *root)const//后根遍历
{
	if (root)
	{
		Postorder(root->Left);
		Postorder(root->Right);
		cout << root->Data << " ";
	}
}

template<typename T>
void BinaryTree<T>::Levelorder(BinaryTreeNode<T>* root)const//层次遍历
{
	BinaryTreeNode<T> *Tempnode;
	queue<BinaryTreeNode<T>*> Queue;//创建新队列用来保存结点
	if (root)
	{
		Queue.push(root);//如果结点不空则将结点入队
	}
	while (!Queue.empty())//如果队列不空
	{
		Tempnode = Queue.front();
		cout << Tempnode->Data<<" ";
		Queue.pop();//将队列中一个第一个元素弹出
		if (Tempnode->Left)
		{
			Queue.push(Tempnode->Left);
		}
		if (Tempnode->Right)
		{
			Queue.push(Tempnode->Right);
			//如果右子结点为空则将右子结点入队
		}
	}
}

template<typename T>
void BinaryTree<T>::DeleteBT(const BinaryTreeNode<T> *root)
{
	if (root)
	{
		DeleteBT(root->Left);
		DeleteBT(root->Right);
		delete root;
	}
	Root = nullptr;
}

template<typename T>
BinaryTreeNode<T> *BinaryTree<T>::Find(BinaryTreeNode<T>*root,const T &item)const
{
	BinaryTreeNode<T>* Tempnode;
	if (!root)//如果根节点为空
	{
		return nullptr;
	}
	else if (root->Data == item)
	{
		return root;
	}
	else
	{
		Tempnode = Find(root->Left,item);
		if (!Tempnode)
		{
			Tempnode = Find(root->Right, item);
		}
		return Tempnode;
	}
}

template<typename T>
int BinaryTree<T>::GetHeight(const BinaryTreeNode<T>* root)
{
	if (!root)
	{
		return 0;//如果结点是空的则返回0
	}
	else
	{
		int LeftHeight = GetHeight(root->Left) + 1;//左右子树分别递归求解
		int RightHeight = GetHeight(root->Right) + 1;
		if (LeftHeight > RightHeight)
		{
			return LeftHeight;
		}
		else
		{
			return RightHeight;
		}
	}
}

template<typename T>//寻找值为item结点的父节点
BinaryTreeNode<T>* BinaryTree<T>::Parent(BinaryTreeNode<T>* root, const T &item)const
{
	BinaryTreeNode<T> *Tempnode;
	queue<BinaryTreeNode<T>*> Queue;//创建新队列用来保存结点
	if (root)
	{
		Queue.push(root);//如果结点不空则将结点入队
	}
	while (!Queue.empty())//如果队列不空
	{
		Tempnode = Queue.front();
		if (Tempnode->Left&&Tempnode->Left->Data == item)
		{
			return Tempnode;
		}
		if (Tempnode->Right&&Tempnode->Right->Data == item)
		{
			return Tempnode;
		}
		
		Queue.pop();//将队列中一个第一个元素弹出
		if (Tempnode->Left)
		{
			Queue.push(Tempnode->Left);
		}
		if (Tempnode->Right)
		{
			Queue.push(Tempnode->Right);
			//如果右子结点为空则将右子结点入队
		}
	}
	return nullptr;
}

template<typename T>//插入节点 被插入结点
bool BinaryTree<T>::InsertLL(T& insert,T& inserted)
{
	BinaryTreeNode<T>* insertednode = Find(Root, inserted);
	if (!insertednode)
	{
		return false;
	}
	BinaryTreeNode<T>* insertnode = new BinaryTreeNode<T>();
	insertnode->Data = insert;
	insertnode->Left = insertednode->Left;
	insertednode->Left = insertnode;
	return true;
}


template<typename T>
void BinaryTree<T>::GetLeaves(BinaryTreeNode<T>* root)
{
	if (root)
	{
		if (root->Left==nullptr && root->Right==nullptr)
		{
			cout << root->Data << " ";
		}
		GetLeaves(root->Left);//递归遍历左子结点
		GetLeaves(root->Right);//递归遍历右子结点
	}
}

template<typename T>
bool BinaryTree<T>::DST(BinaryTreeNode<T>* root, T & item)
{
	BinaryTreeNode<T>* Father = Parent(root, item);
	
	BinaryTreeNode<T>* delnode = Find(root, item);
	if (!delnode)
	{
		return false;
	}
	else
	{
		if (Father->Left == delnode)
		{
			Father->Left = nullptr;
			delete delnode;
		}
		else if (Father->Right == delnode)
		{
			Father->Right = nullptr;
			delete delnode;
		}
		else if (Father == delnode)
		{
			delnode = nullptr;
			delete delnode;
		}
		return true;
	}
}



