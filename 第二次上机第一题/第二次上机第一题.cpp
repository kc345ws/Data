#include"第二次上机第一题.h"
#include<iostream>
#include<queue>

using namespace std;
BinaryTree<char> *BT;
void Menu();

int main()
{
	
}

void Menu()
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
}

template<typename T>
BinaryTree<T>::BinaryTree()
{
	Root = new BinaryTreeNode<T>();
	Root->Left = new BinaryTreeNode<T>();
	Root->Right = new BinaryTreeNode<T>();
}

template<typename T>
BinaryTree<T>::BinaryTree(T &item)
{
	Root = new BinaryTreeNode<T>();
	Root->Data = item;
	Root->Left = new BinaryTreeNode<T>();
	Root->Right = new BinaryTreeNode<T>();
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
BinaryTreeNode<T>* BinaryTree<T>::ReturnRoot()const
{
	return Root;
}

template<typename T>
void BinaryTree<T>::DeleteBT(const BinaryTreeNode<T> *root)
{
	if (root)
	{
		DeleteBT(root->Left);
		DeleteBT(root->Left);
		delete root;
	}
}

template<typename T>
BinaryTreeNode<T> *BinaryTree<T>::Find(const BinaryTreeNode<T>*root,const T &item)const
{
	BinaryTreeNode<T>* Tempnode;
	if (!Root)//如果根节点为空
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



