#include<iostream>
#include"第二次上机第二题.h"
#include<queue>
#include<deque>
#include<list>
#define FILE_BUFFER_LENGTH 3000000
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
	cout << "1.创建树" << endl;
	cout << "2.树的先根遍历递归算法" << endl;
	cout << "3.树的后根遍历递归算法" << endl;
	cout << "4.树的层次遍历" << endl;
	cout << "5.树的先根遍历迭代算法" << endl;
	cout << "6.树的后根遍历迭代算法" << endl;
	cout << "7.创建森林" << endl;
	cout << "8.深林先根遍历递归算法" << endl;
	cout << "9.森林后跟遍历递归算法" << endl;
	cout << "10.树的后根遍历迭代算法" << endl;
	cout << "11.树的先根遍历迭代算法" << endl;
	cout << "12.森林的层次遍历算法" << endl;
	
	while (1)
	{

		cin >> select;

		if (!std::cin || select == '#')
		{
			cin.clear();
			cin.get();
			cout << "请重新输入" << endl;
			cin >> select;
		}
		switch (select)
		{
		case 1:
			cout << "按先根遍历顺序输入每个结点的值(#为空)" << endl;
			//A B # C D # # # E F # # #
			//Q M # E F # # # P G # # #
			tree = new Tree<char>();
			tree->CreateTree(tree->ReturnRoot());
			cout << endl;
			cout << "创建完毕" << endl;
			Menu();
			break;
		case 2:
			cout << "树的先根遍历递归算法结果:" << endl;
			tree->Preorder(tree->ReturnRoot());
			cout << endl;
			Menu();
			break;
		case 3:
			cout << "树的后根遍历递归算法结果:" << endl;
			tree->Postorder(tree->ReturnRoot());
			cout << endl;
			Menu();
			break;
		case 4:
			cout << "树的层次遍历结果:" << endl;
			tree->Levelorder(tree->ReturnRoot());
			cout << endl;
			Menu();
			break;

		case 5:
			cout << "树的先根遍历迭代算法结果:" << endl;
			tree->NPO(tree->ReturnRoot());
			cout << endl;
			Menu();
			break;

		case 6:
			cout << "树的后根遍历迭代算法结果:" << endl;
			tree->NPT(tree->ReturnRoot());
			cout << endl;
			Menu();
			break;
		case 7:
			//forest = new Forest<char>();
			//forest->CreateForest();
			//cout << "输入森林中树的个数" << endl;
			//cin >> FORESTSIZE;

			forest = new Forest<char>();
			forest->CreateForest();
			Menu();
			break;

		case 8:
			//forest->Pos(forest->Root);
			forest->Pre(forest->Root);
			cout << endl;
			Menu();
			break;

		case 9:
			//forest->Pre(forest->Root);
			forest->Pos(forest->Root);
			cout << endl;
			Menu();
			break;




		case 10:
			forest->Pos(forest->Root);

			cout << endl;
			Menu();
			break;

		case 11:
			forest->Pre(forest->Root);
			//forest->NPOF(forest->Root);
			cout << endl;
			Menu();
			break;

		case 12:
			forest->Levelorder(forest->Root);

			cout << endl;
			Menu();
			break;

		default:
			break;
		}
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

	if (nodedata == '#')//如果输入#则将该结点设为空
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
//R A D # E # # B # C F G # H # K # # # # #
}

template<typename T>
void Tree<T>::Preorder(TreeNode<T>* root)
{
	TreeNode<T> *child;
	if (root)
	{
		cout << root->Data << " ";
		child = GFC(root);
		while (child)
		{
			Preorder(child);
			child = GNB(child);
		}
	}
	//A B # C E # F # # D # # #
	//A B # C E # F # # D # # #         A B C E F D
}

template<typename T>
void Tree<T>::Postorder(TreeNode<T>* root)
{
	TreeNode<T> *child;
	if (root)
	{
		child = GFC(root);
		while (child)
		{
			Postorder(child);
			child = GNB(child);
		}
		cout << root->Data << " ";
	}
}//A B # C E # F # # D # # #         B E F C D A

template<typename T>
void Tree<T>::Levelorder(TreeNode<T>* root) const
{
	TreeNode<T> *Tempnode;
	queue<TreeNode<T>*> Queue;//创建新队列用来保存结点
	if (root)
	{
		Queue.push(root);//如果结点不空则将结点入队
	}
	while (!Queue.empty())//如果队列不空
	{
		Tempnode = Queue.front();
		Queue.pop();//将队列中一个第一个元素弹出
		while (Tempnode)
		{
			cout << Tempnode->Data << " ";
			if (Tempnode->FirstChild)
			{
				Queue.push(Tempnode->FirstChild);
			}
			Tempnode = Tempnode->NextBother;
		}
	}
}//A B # 




template<typename T>//树的先根遍历迭代算法
void Tree<T>::NPO(TreeNode<T>* root)
{
	TreeNode<T>*Tempnode;
	queue<TreeNode<T>*>Queue;
	deque<TreeNode<T>*>Deque;
	list<TreeNode<T>*>List;
	Tempnode = root;
	do
	{
		while (Tempnode)
		{
			cout << Tempnode->Data << " ";
			//Queue.push(Tempnode);
			//Tempnode = Tempnode->FirstChild;
			List.push_back(Tempnode);
			Tempnode = Tempnode->FirstChild;
		}
		while (!Tempnode && !List.empty())
		{
			//Tempnode = Queue.back();
			//Queue.pop();
			Tempnode = List.back();
			List.pop_back();
			Tempnode = Tempnode->NextBother;
		}
	} while (!List.empty());
}//A B # C E # F # # D # # #         A B C E F D



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
TreeNode<T>* Tree<T>::GNB(TreeNode<T>* root)
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

template<typename T>//后根遍历迭代算法
void Tree<T>::NPT(TreeNode<T>* root)
{
	TreeNode<T>*Tempnode;
	queue<TreeNode<T>*>Queue;
	deque<TreeNode<T>*>Deque;
	list<TreeNode<T>*>List;
	Tempnode = root;
	do
	{
		while (Tempnode)
		{
			//Queue.push(Tempnode);
			//Tempnode = Tempnode->FirstChild;
			List.push_back(Tempnode);
			Tempnode = Tempnode->FirstChild;
		}
		while (!Tempnode && !List.empty())
		{
			//Tempnode = Queue.back();
			//Queue.pop();
			Tempnode = List.back();
			List.pop_back();
			cout << Tempnode->Data << " ";
			Tempnode = Tempnode->NextBother;
		}
	} while (!List.empty());
}//A B # C E # F # # D # # #         B E F C D A




template<typename T>
inline Forest<T>::Forest()
{
	cout << "请输入森林中树的个数" << endl;
	int size;
	cin >> size;
	ForestSize = size;
	//Root = new TreeNode<T>[size];
	for (int i = 0; i < ForestSize; i++)
	{
		Root[i] = new TreeNode<T>();
		Root[i]->FirstChild = new TreeNode<T>();
		Root[i]->NextBother = new TreeNode<T>();
	}

	/*TreeNode<T> *Temp;
	VirtualRoot = new TreeNode<T>();
	VirtualRoot->FirstChild = Root[0];
	Temp = VirtualRoot->FirstChild;	
	for (int i = 1; i < ForestSize; i++)
	{
		Temp->NextBother = Root[i];
		Temp = Temp->NextBother;
	}*/
}

template<typename T>
void Forest<T>::CreateForest()
{
	T nodedata;
	for (int i = 0; i < ForestSize; i++)
	{
		cout << "请按照先根遍历输入第" << i + 1 << "棵树的值" << endl;
		CreateForestTree(Root[i]);
	}
}

template<typename T>
TreeNode<T>* Forest<T>::CreateForestTree(TreeNode<T>* root)
{
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
			root = new TreeNode<T>();
		}

		root->Data = nodedata;
		root->FirstChild = CreateForestTree(root->FirstChild);
		root->NextBother = CreateForestTree(root->NextBother);
	}
	return root;
}

template<typename T>
void Forest<T>::ForestPreorder(TreeNode<T>* root)
{
	TreeNode<T> *child;
	if (root)
	{
		cout << root->Data << " ";
		child = GFC(root);
		while (child)
		{
			ForestPreorder(child);
			child = GNB(child);
		}
	}
	//3 
	//A B # C # D # # # 
	//E F # # # 
	//G H # I J # # # #
}

template<typename T>
void Forest<T>::Pre(TreeNode<T>* root[])
{
	for (int i = 0; i < ForestSize; i++)
	{
		cout << "第" << i + 1 << "棵树的先根遍历结果" << endl;
		ForestPreorder(root[i]);
		cout << endl;
	}
}

template<typename T>
void Forest<T>::ForestPostorder(TreeNode<T>* root)
{
	TreeNode<T> *child;
	if (root)
	{
		child = GFC(root);
		while (child)
		{
			ForestPostorder(child);
			child = GNB(child);
		}
		cout << root->Data << " ";
	}
	//3 
	//A B # C # D # # # 
	//E F # # # 
	//G H # I J # # # #
}

template<typename T>
void Forest<T>::Pos(TreeNode<T>* root[])
{   
	for (int i = 0; i < ForestSize; i++)
	{
		cout << "第" << i + 1 << "棵树的后根遍历结果" << endl;
		ForestPostorder(root[i]);
		cout << endl;
	}
}

template<typename T>
void Forest<T>::ForestLevelorder(TreeNode<T>* root)
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
void Forest<T>::Levelorder(TreeNode<T>*root[])
{

	for (int i = 0; i < ForestSize-1; i++)
	{
		root[i]->NextBother = root[i + 1];
	}

	TreeNode<T> *Tempnode;
	queue<TreeNode<T>*> Queue;//创建新队列用来保存结点
	if (root[0])
	{
		Queue.push(root[0]);//如果结点不空则将结点入队
	}
	while (!Queue.empty())//如果队列不空
	{
		Tempnode = Queue.front();
		Queue.pop();//将队列中一个第一个元素弹出
		while (Tempnode)
		{
			cout << Tempnode->Data << " ";
			if (Tempnode->FirstChild)
			{
				Queue.push(Tempnode->FirstChild);
			}
			Tempnode = Tempnode->NextBother;
		}
	}

	for (int i = 0; i < ForestSize; i++)
	{
		root[i]->NextBother = new TreeNode<T>();
	}
}

template<typename T>
void Forest<T>::Level(TreeNode<T>* root[])
{
	/*for (int i = 0; i < ForestSize; i++)
	{
		cout << "第" << i + 1 << "棵树的层次遍历结果" << endl;
		Levelorder(root[i]);
	}*/
}

template<typename T>
void Forest<T>::NPO(TreeNode<T>* root)
{
	TreeNode<T>*Tempnode;
	queue<TreeNode<T>*>Queue;
	deque<TreeNode<T>*>Deque;
	list<TreeNode<T>*>List;
	Tempnode = root;
	do
	{
		while (Tempnode)
		{
			cout << Tempnode->Data << " ";
			//Queue.push(Tempnode);
			//Tempnode = Tempnode->FirstChild;
			List.push_back(Tempnode);
			Tempnode = Tempnode->FirstChild;
		}
		while (!Tempnode && !List.empty())
		{
			//Tempnode = Queue.back();
			//Queue.pop();
			Tempnode = List.back();
			List.pop_back();
			Tempnode = Tempnode->NextBother;
		}
	} while (!List.empty());
}

template<typename T>
void Forest<T>::NPT(TreeNode<T>* root)
{
	TreeNode<T>*Tempnode;
	queue<TreeNode<T>*>Queue;
	deque<TreeNode<T>*>Deque;
	list<TreeNode<T>*>List;
	Tempnode = root;
	do
	{
		while (Tempnode)
		{
			//Queue.push(Tempnode);
			//Tempnode = Tempnode->FirstChild;
			List.push_back(Tempnode);
			Tempnode = Tempnode->FirstChild;
		}
		while (!Tempnode && !List.empty())
		{
			//Tempnode = Queue.back();
			//Queue.pop();
			Tempnode = List.back();
			List.pop_back();
			cout << Tempnode->Data << " ";
			Tempnode = Tempnode->NextBother;
		}
	} while (!List.empty());
}



template<typename T>
TreeNode<T>* Forest<T>::GFC(TreeNode<T>* root)
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
TreeNode<T>* Forest<T>::GNB(TreeNode<T>* root)
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
void Forest<T>::NPOF(TreeNode<T>* root[])
{
	for (int i = 0; i < ForestSize; i++)
	{
		cout << "第" << i + 1 << "棵树的先根遍历结果" << endl;
		NPO(root[i]);
		cout << endl;
	}
}

template<typename T>
void Forest<T>::NPTF(TreeNode<T>* root[])
{
	for (int i = 0; i < ForestSize; i++)
	{
		cout << "第" << i + 1 << "棵树的后根遍历结果" << endl;
		NPT(root[i]);
		cout << endl;
	}
}


