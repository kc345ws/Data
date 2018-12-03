#include<iostream>
#include"�ڶ����ϻ��ڶ���.h"
#include<queue>
using namespace std;
Tree<char>* tree;
Forest<char>* forest;
Tree<char>*trees[];
int FORESTSIZE;
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
	cout << "1.������" << endl;
	cout << "2.�����ȸ������ݹ��㷨" << endl;
	cout << "3.���ĺ�������ݹ��㷨" << endl;
	cout << "4.���Ĳ�α���" << endl;
	cout << "5.�����ȸ����������㷨" << endl;
	cout << "6.���ĺ�����������㷨" << endl;
	cout << "7.����ɭ��" << endl;
	cout << "8.�����ȸ������ݹ��㷨" << endl;
	cout << "9.ɭ�ֺ�������ݹ��㷨" << endl;
	cout << "10.ɭ�ֵĲ�α����㷨" << endl;
	cout << "11.�����ȸ����������㷨" << endl;
	cout << "12.���ĺ�����������㷨" << endl;
	cin >> select;
	switch (select)
	{
	case 1:
		cout << "���ȸ�����˳������ÿ������ֵ(#Ϊ��)" << endl;
		//A B # C D # # # E F # # #
		//Q M # E F # # # P G # # #
		tree = new Tree<char>();
		tree->CreateTree(tree->ReturnRoot());
		cout << endl;
		cout << "�������" << endl;
		Menu();
		break;
	case 2:
		cout << "�����ȸ������ݹ��㷨���:" << endl;
		tree->Preorder(tree->ReturnRoot());
		cout << endl;
		Menu();
		break;
	case 3:
		cout << "���ĺ�������ݹ��㷨���:" << endl;
		tree->Postorder(tree->ReturnRoot());
		cout << endl;
		Menu();
		break;
	case 4:
		cout << "���Ĳ�α������:" << endl;
		tree->Levelorder(tree->ReturnRoot());
		cout << endl;
		Menu();
		break;

	case 5:
		cout << "�����ȸ����������㷨���:" << endl;
		tree->NPO(tree->ReturnRoot());
		cout << endl;
		Menu();
		break;

	case 6:
		cout << "���ĺ�����������㷨���:" << endl;
		tree->NPT(tree->ReturnRoot());
		cout << endl;
		Menu();
		break;
	case 7:
		//forest = new Forest<char>();
		//forest->CreateForest();
		//cout << "����ɭ�������ĸ���" << endl;
		//cin >> FORESTSIZE;
	
		forest = new Forest<char>();
		forest->CreateForest();
		Menu();
		break;

	case 8:
		forest->Pos(forest->Root);
		cout << endl;
		Menu();
		break;

	case 9:
		forest->Pre(forest->Root);
		cout << endl;
		Menu();
		break;

	case 10:
		forest->Level(forest->Root);

		cout << endl;
		Menu();
		break;
	case 11:
		forest->Pos(forest->Root);

		cout << endl;
		Menu();
		break;

	case 12:
		forest->Pre(forest->Root);
		cout << endl;
		Menu();
		break;
	default:
		break;
	}
}

template<typename T>
inline Tree<T>::Tree()
{
	Root = new TreeNode<T>();
	Root->FirstChild = new TreeNode<T>();
	Root->NextBother = new TreeNode<T>();
}

template<typename T>
inline Tree<T>::Tree(T & item)
{
	Root = new TreeNode<T>();
	Root->Data = item;
	Root->Left = new TreeNode<T>();
	Root->Right = new TreeNode<T>();
}

template<typename T>
TreeNode<T> *Tree<T>::CreateTree(TreeNode<T> *root)
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
			root = new TreeNode<T>();
		}

		root->Data = nodedata;
		root->FirstChild = CreateTree(root->FirstChild);
		root->NextBother = CreateTree(root->NextBother);
	}
	return root;
}

template<typename T>
void Tree<T>::Preorder(TreeNode<T>* root) const
{
	if (root)
	{
		cout << root->Data << " ";
		Postorder(root->FirstChild);//�ݹ����
		Postorder(root->NextBother);//�ݹ����
	}
}

template<typename T>
void Tree<T>::Postorder(TreeNode<T>* root) const
{
	if (root)
	{
		Postorder(root->FirstChild);//�ݹ����
		Postorder(root->NextBother);//�ݹ����
		cout << root->Data << " ";
	}
}

template<typename T>
void Tree<T>::Levelorder(TreeNode<T>* root) const
{
	TreeNode<T> *Tempnode;
	queue<TreeNode<T>*> Queue;//�����¶�������������
	
	if (root)
	{
		Queue.push(root);//�����㲻���򽫽�����
	}
	
	while (!Queue.empty())//������в���
	{
		Tempnode = Queue.front();
		cout << Tempnode->Data << " ";
		Queue.pop();//��������һ����һ��Ԫ�ص���
		if (Tempnode->FirstChild)
		{
			Queue.push(Tempnode->FirstChild);
		}
		if (Tempnode->NextBother)
		{
			Queue.push(Tempnode->NextBother);

		}
	}





	
}



template<typename T>
void Tree<T>::NPO(TreeNode<T>* root)
{
	TreeNode<T>*Tempnode;
	queue<TreeNode<T>*>Queue;
	Tempnode = root;
	while (!Tempnode)
	{
		while (Tempnode)
		{
			cout << Tempnode->Data << " ";
			Queue.push(Tempnode);
			Tempnode = Tempnode->FirstChild;
		}
		while (!Tempnode && !Queue.empty())
		{
			Tempnode = Queue.front();
			Queue.pop();
			Tempnode = Tempnode->NextBother;
		}
		if (Queue.empty())
		{
			break;
		}

	}
























	if (root)
	{
		cout << root->Data << " ";
		Postorder(root->FirstChild);//�ݹ����
		Postorder(root->NextBother);//�ݹ����
	}
}

template<typename T>
TreeNode<T>* Tree<T>::GFC(TreeNode<T>* root)
{
	if (root && root->FirstChild)
	{
		return root->FirstChild;
	}
	else
	{
		return nullptr;
	}
}

template<typename T>
TreeNode<T>* Tree<T>::GNC(TreeNode<T>* root)
{
	if (root && root->NextBother)
	{
		return root->NextBother;
	}
	else
	{
		return nullptr;
	}
}

template<typename T>
void Tree<T>::NPT(TreeNode<T>* root)
{
	TreeNode<T>*Tempnode;
	queue<TreeNode<T>*>Queue;
	Tempnode = root;
	while (!Tempnode)
	{
		while (Tempnode)
		{
			Queue.push(Tempnode);
			Tempnode = Tempnode->FirstChild;
			cout << Tempnode->Data << " ";
		}
		while (!Tempnode && !Queue.empty())
		{
			Tempnode = Queue.front();
			Queue.pop();
			Tempnode = Tempnode->NextBother;
		}
		if (Queue.empty())
		{
			break;
		}

	}









	if (root)
	{
		Postorder(root->FirstChild);//�ݹ����
		Postorder(root->NextBother);//�ݹ����
		cout << root->Data << " ";
	}
}




template<typename T>
inline Forest<T>::Forest()
{
	cout << "������ɭ�������ĸ���" << endl;
	int size;
	cin >> size;
	ForestSize = size;
	for (int i = 0; i < ForestSize; i++)
	{
		Root[i] = new TreeNode<T>();
		Root[i]->FirstChild = new TreeNode<T>();
		Root[i]->NextBother = new TreeNode<T>();
	}
}

template<typename T>
void Forest<T>::CreateForest()
{
	T nodedata;
	for (int i = 0; i < ForestSize; i++)
	{
		cout << "�밴���ȸ����������" << i + 1 << "������ֵ" << endl;
		CreateForestTree(Root[i]);
	}
}

template<typename T>
TreeNode<T>* Forest<T>::CreateForestTree(TreeNode<T>* root)
{
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
			root = new TreeNode<T>();
		}

		root->Data = nodedata;
		root->FirstChild = CreateForestTree(root->FirstChild);
		root->NextBother = CreateForestTree(root->NextBother);
	}
	return root;
}

template<typename T>
void Forest<T>::ForestPreorder(TreeNode<T>* root) const
{
	if (root)
	{
		cout << root->Data << " ";
		ForestPreorder(root->FirstChild);//�ݹ����
		ForestPreorder(root->NextBother);//�ݹ����
	}
}

template<typename T>
void Forest<T>::Pre(TreeNode<T>* root[])
{
	for (int i = 0; i < ForestSize; i++)
	{
		cout << "��" << i + 1 << "�������ȸ��������" << endl;
		ForestPreorder(root[i]);
	}
}

template<typename T>
void Forest<T>::ForestPostorder(TreeNode<T>* root) const
{
	if (root)
	{
		ForestPostorder(root->FirstChild);//�ݹ����
		ForestPostorder(root->NextBother);//�ݹ����
		cout << root->Data << " ";
	}
}

template<typename T>
void Forest<T>::Pos(TreeNode<T>* root[])
{
	for (int i = 0; i < ForestSize; i++)
	{
		cout << "��" << i + 1 << "�����ĺ���������" << endl;
		ForestPostorder(root[i]);
	}
}

template<typename T>
void Forest<T>::ForestLevelorder(TreeNode<T>* root) const
{
}

template<typename T>
void Forest<T>::ForestNPO(TreeNode<T>* root)
{
}

template<typename T>
void Forest<T>::ForestNPT(TreeNode<T>* root)
{
}

template<typename T>
void Forest<T>::Levelorder(TreeNode<T>* root) const
{
	TreeNode<T> *Tempnode;
	queue<TreeNode<T>*> Queue;//�����¶�������������

	if (root)
	{
		Queue.push(root);//�����㲻���򽫽�����
	}

	while (!Queue.empty())//������в���
	{
		Tempnode = Queue.front();
		cout << Tempnode->Data << " ";
		Queue.pop();//��������һ����һ��Ԫ�ص���
		if (Tempnode->FirstChild)
		{
			Queue.push(Tempnode->FirstChild);
		}
		if (Tempnode->NextBother)
		{
			Queue.push(Tempnode->NextBother);

		}
	}
}

template<typename T>
void Forest<T>::Level(TreeNode<T>* root[])
{
	for (int i = 0; i < ForestSize; i++)
	{
		cout << "��" << i + 1 << "�����Ĳ�α������" << endl;
		Levelorder(root[i]);
	}
}

template<typename T>
void Forest<T>::NPO(TreeNode<T>* root)
{
	TreeNode<T>*Tempnode;
	queue<TreeNode<T>*>Queue;
	Tempnode = root;
	while (!Tempnode)
	{
		while (Tempnode)
		{
			cout << Tempnode->Data << " ";
			Queue.push(Tempnode);
			Tempnode = Tempnode->FirstChild;
		}
		while (!Tempnode && !Queue.empty())
		{
			Tempnode = Queue.front();
			Queue.pop();
			Tempnode = Tempnode->NextBother;
		}
		if (Queue.empty())
		{
			break;
		}

	}















}

template<typename T>
void Forest<T>::NPT(TreeNode<T>* root)
{
	TreeNode<T>*Tempnode;
	queue<TreeNode<T>*>Queue;
	Tempnode = root;
	while (!Tempnode)
	{
		while (Tempnode)
		{
			
			Queue.push(Tempnode);
			Tempnode = Tempnode->FirstChild;
			cout << Tempnode->Data << " ";
		}
		while (!Tempnode && !Queue.empty())
		{
			Tempnode = Queue.front();
			Queue.pop();
			Tempnode = Tempnode->NextBother;
		}
		if (Queue.empty())
		{
			break;
		}

	}















}


