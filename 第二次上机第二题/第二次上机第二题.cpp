#include<iostream>
#include"第二次上机第二题.h"
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
	cout << "1.创建树" << endl;
	cout << "2.树的先根遍历递归算法" << endl;
	cout << "3.树的后根遍历递归算法" << endl;
	cout << "4.树的层次遍历" << endl;
	cout << "5.树的先根遍历迭代算法" << endl;
	cout << "6.树的后根遍历迭代算法" << endl;
	cout << "7.创建森林" << endl;
	cout << "8.深林先根遍历递归算法" << endl;
	cout << "9.森林后跟遍历递归算法" << endl;
	cout << "10.森林的层次遍历算法" << endl;
	cout << "11.树的先根遍历迭代算法" << endl;
	cout << "12.树的后根遍历迭代算法" << endl;
	cin >> select;
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
}

template<typename T>
void Tree<T>::Preorder(TreeNode<T>* root) const
{
	if (root)
	{
		cout << root->Data << " ";
		Postorder(root->FirstChild);//递归遍历
		Postorder(root->NextBother);//递归遍历
	}
}

template<typename T>
void Tree<T>::Postorder(TreeNode<T>* root) const
{
	if (root)
	{
		Postorder(root->FirstChild);//递归遍历
		Postorder(root->NextBother);//递归遍历
		cout << root->Data << " ";
	}
}

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
		cout << Tempnode->Data << " ";
		Queue.pop();//将队列中一个第一个元素弹出
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
		Postorder(root->FirstChild);//递归遍历
		Postorder(root->NextBother);//递归遍历
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
		Postorder(root->FirstChild);//递归遍历
		Postorder(root->NextBother);//递归遍历
		cout << root->Data << " ";
	}
}




template<typename T>
inline Forest<T>::Forest()
{
	cout << "请输入森林中树的个数" << endl;
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
void Forest<T>::ForestPreorder(TreeNode<T>* root) const
{
	if (root)
	{
		cout << root->Data << " ";
		ForestPreorder(root->FirstChild);//递归遍历
		ForestPreorder(root->NextBother);//递归遍历
	}
}

template<typename T>
void Forest<T>::Pre(TreeNode<T>* root[])
{
	for (int i = 0; i < ForestSize; i++)
	{
		cout << "第" << i + 1 << "棵树的先根遍历结果" << endl;
		ForestPreorder(root[i]);
	}
}

template<typename T>
void Forest<T>::ForestPostorder(TreeNode<T>* root) const
{
	if (root)
	{
		ForestPostorder(root->FirstChild);//递归遍历
		ForestPostorder(root->NextBother);//递归遍历
		cout << root->Data << " ";
	}
}

template<typename T>
void Forest<T>::Pos(TreeNode<T>* root[])
{
	for (int i = 0; i < ForestSize; i++)
	{
		cout << "第" << i + 1 << "棵树的后根遍历结果" << endl;
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
	queue<TreeNode<T>*> Queue;//创建新队列用来保存结点

	if (root)
	{
		Queue.push(root);//如果结点不空则将结点入队
	}

	while (!Queue.empty())//如果队列不空
	{
		Tempnode = Queue.front();
		cout << Tempnode->Data << " ";
		Queue.pop();//将队列中一个第一个元素弹出
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
		cout << "第" << i + 1 << "棵树的层次遍历结果" << endl;
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


