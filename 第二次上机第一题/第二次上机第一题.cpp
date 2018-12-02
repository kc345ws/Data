#include"�ڶ����ϻ���һ��.h"
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
	cout << "�ȸ�����" << endl;
	BT->Preorder(BT->ReturnRoot());
	cout << endl;
	cout << "�и�����" << endl;
	BT->Inorder(BT->ReturnRoot());
	cout << endl;
	cout << "�������" << endl;
	BT->Postorder(BT->ReturnRoot());
	cout << endl;
	cout << "��α���" << endl;
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
	
	if (nodedata == '#')//�������#�򽫸ý����Ϊ��
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
void BinaryTree<T>::Preorder(BinaryTreeNode<T> *root)const//�ȸ�����
{
	if (root)
	{
		cout << root->Data << " ";
		Preorder(root->Left);//�ݹ�������ӽ��
		Preorder(root->Right);//�ݹ�������ӽ��
	}
}

template<typename T>
void BinaryTree<T>::Inorder(BinaryTreeNode<T> *root)const//�и�����
{
	if (root)
	{
		Inorder(root->Left);
		cout << root->Data << " ";
		Inorder(root->Right);
	}
}

template<typename T>
void BinaryTree<T>::Postorder(BinaryTreeNode<T> *root)const//�������
{
	if (root)
	{
		Postorder(root->Left);
		Postorder(root->Right);
		cout << root->Data << " ";
	}
}

template<typename T>
void BinaryTree<T>::Levelorder(BinaryTreeNode<T>* root)const//��α���
{
	BinaryTreeNode<T> *Tempnode;
	queue<BinaryTreeNode<T>*> Queue;//�����¶�������������
	if (root)
	{
		Queue.push(root);//�����㲻���򽫽�����
	}
	while (!Queue.empty())//������в���
	{
		Tempnode = Queue.front();
		cout << Tempnode->Data<<" ";
		Queue.pop();//��������һ����һ��Ԫ�ص���
		if (Tempnode->Left)
		{
			Queue.push(Tempnode->Left);
		}
		if (Tempnode->Right)
		{
			Queue.push(Tempnode->Right);
			//������ӽ��Ϊ�������ӽ�����
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
	if (!Root)//������ڵ�Ϊ��
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



