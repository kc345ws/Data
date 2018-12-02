#pragma once
#ifndef _HEAD
#define _HEAD

template<typename T>
class BinaryTreeNode//二叉树结点定义
{
public:
	T Data;//数据域
	BinaryTreeNode *Right;//右子结点
	BinaryTreeNode *Left;//左子结点
};

template<typename T>
class BinaryTree
{
private:
	BinaryTreeNode<T> *Root;//二叉树根结点
	int NodeNumber;
	int Height;
public:
	BinaryTree();
	BinaryTree(T &item);
	~BinaryTree();
	BinaryTreeNode<T>* CreateBT(BinaryTreeNode<T> *root);//创建二叉树
	void Inorder(BinaryTreeNode<T> *root)const;//中根遍历
	void Preorder(BinaryTreeNode<T> *root)const;//先根遍历
	void Postorder(BinaryTreeNode<T> *root)const;//后根遍历
	void Levelorder(BinaryTreeNode<T> *root)const;//层次遍历
	BinaryTreeNode<T> *ReturnRoot()const { return Root; }//返回根节点
	void DeleteBT(const BinaryTreeNode<T> *root);//删除二叉树
	BinaryTreeNode<T>* Find(BinaryTreeNode<T>* root,const T &item)const;//查找值为item的结点
	int GetNodeNumber() { return NodeNumber; }//二叉树中结点的个数
	int GetHeight(const BinaryTreeNode<T>* root);//获得二叉树的高度
	BinaryTreeNode<T>* Parent(BinaryTreeNode<T>* root, const T &item)const;//寻找值为item结点的父节点
	bool InsertLL(T& insert, T& inserted);//插入结点位做儿子节点，原左二子作为插入结点的左儿子
	bool DST(BinaryTreeNode<T>* root, T &item);//删除指定结点及其左右孩子
	void GetLeaves(BinaryTreeNode<T>*root);//获取所有叶子结点
};
#endif

