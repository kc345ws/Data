#include"�ڶ����ϻ���һ��.h"
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
		cout << "1.����������" << endl;
		cout << "2.�ȸ�����" << endl;
		cout << "3.�и�����" << endl;
		cout << "4.�������" << endl;
		cout << "5.��α���" << endl;
		cout << "6.�鿴������" << endl;
		cout << "7.���ĸ߶�" << endl;
		cout << "8.ɾ��������" << endl;
		cout << "9.����ڵ�" << endl;
		cout << "10.�鿴Ҷ�ӽ��" << endl;
		cout << "11.ɾ��ָ����㼰�����Һ���" << endl;
		cout << "12.�鿴ָ�����ĸ��ڵ�" << endl;
		cout << "13.����ָ������Ƿ����" << endl;
		
		
		cin >> select;//�������������
		
		if (!std::cin || select == '#')
		{
			cin.clear();
			cin.get();
			cin >> select;
		}

		


		switch (select)
		{
		case 1:
			cout << "���ȸ�����˳������ÿ������ֵ(#Ϊ��)" << endl;
			//A B # C D # # # E F # # #
			BT = new BinaryTree<char>();
			BT->CreateBT(BT->ReturnRoot());
			cout << endl;
			cout << "�������" << endl;
			Menu();
			break;
		case 2:
			cout << "�ȸ�����:" << endl;
			BT->Preorder(BT->ReturnRoot());
			cout << endl;
			Menu();
			break;
		case 3:
			cout << "�и�����" << endl;
			BT->Inorder(BT->ReturnRoot());
			cout << endl;
			Menu();
			break;
		case 4:
			cout << "�������" << endl;
			BT->Postorder(BT->ReturnRoot());
			cout << endl;
			Menu();
			break;
		case 5:
			cout << "��α���" << endl;
			BT->Levelorder(BT->ReturnRoot());
			cout << endl;
			Menu();
			break;
		case 6:
			cout << "������" << endl;
			cout << BT->GetNodeNumber() << endl;;
			Menu();
			break;
		case 7:
			cout << "���ĸ߶�" << endl;
			cout << BT->GetHeight(BT->ReturnRoot()) - 1 << endl;;
			Menu();
			break;
		case 8:
			BT->DeleteBT(BT->ReturnRoot());
			cout << "ɾ�����" << endl;
			Menu();
			break;
		case 9:
			cout << "������������ֵ" << endl;
			char insertitem;
			cin >> insertitem;
			cout << "���뱻�������ֵ" << endl;
			char inserteditem;
			cin >> inserteditem;
			if (!BT->InsertLL(insertitem, inserteditem))
			{
				cout << "û�иý��" << endl;
			}
			cout << "������ȸ�����" << endl;
			BT->Preorder(BT->ReturnRoot());
			cout << endl;
			Menu();
			break;
			/*case 9:
				delete(sllisttest);
				cout << "ɾ�����" << endl;
				Menu();
				break;*/
		case 10:
			cout << "Ҷ�ӽڵ�" << endl;
			BT->GetLeaves(BT->ReturnRoot());
			cout << endl;
			Menu();
			break;
		case 11:
			cout << "������Ҫɾ������ֵ" << endl;
			char del;
			cin >> del;
			if (!BT->DST(BT->ReturnRoot(), del))
			{
				cout << "û�иý��" << endl;
			}
			cout << "ɾ�����ȸ��������" << endl;
			BT->Preorder(BT->ReturnRoot());
			cout << endl;
			Menu();
			break;
		case 12:
			cout << "������Ҫ���Ҹ��ڵ����ֵ" << endl;
			char ch1;
			cin >> ch1;
			if (!BT->Parent(BT->ReturnRoot(), ch1))
			{
				cout << "�ý�㲻���ڸ��ڵ�" << endl;
			}
			if (BT->Parent(BT->ReturnRoot(), ch1))
			{
				cout << "�ý��ĸ��ڵ�" << endl;
				cout << BT->Parent(BT->ReturnRoot(), ch1)->Data << endl;
			}
			cout << endl;
			Menu();
			break;
		case 13:
			cout << "������Ҫ���ҽ���ֵ" << endl;
			char ch2;
			cin >> ch2;
			if (!BT->Find(BT->ReturnRoot(), ch2))
			{
				cout << "�ý�㲻����" << endl;
			}
			if (BT->Find(BT->ReturnRoot(), ch2))
			{
				cout << "�ý�����" << endl;
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
	cout << "������" << endl;
	cout << BT->GetNodeNumber();
	cout << endl;
	cout << "�������" << endl;
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
		NodeNumber++;
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
	if (!root)//������ڵ�Ϊ��
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
		return 0;//�������ǿյ��򷵻�0
	}
	else
	{
		int LeftHeight = GetHeight(root->Left) + 1;//���������ֱ�ݹ����
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

template<typename T>//Ѱ��ֵΪitem���ĸ��ڵ�
BinaryTreeNode<T>* BinaryTree<T>::Parent(BinaryTreeNode<T>* root, const T &item)const
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
		if (Tempnode->Left&&Tempnode->Left->Data == item)
		{
			return Tempnode;
		}
		if (Tempnode->Right&&Tempnode->Right->Data == item)
		{
			return Tempnode;
		}
		
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
	return nullptr;
}

template<typename T>//����ڵ� ��������
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
		GetLeaves(root->Left);//�ݹ�������ӽ��
		GetLeaves(root->Right);//�ݹ�������ӽ��
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



