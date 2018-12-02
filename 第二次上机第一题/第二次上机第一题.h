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

public:
	BinaryTree();
	BinaryTree(T &item);
	~BinaryTree();
	BinaryTreeNode<T>* CreateBT(BinaryTreeNode<T> *root);//创建二叉树
	void Inorder(BinaryTreeNode<T> *root)const;//中根遍历
	void Preorder(BinaryTreeNode<T> *root)const;//先根遍历
	void Postorder(BinaryTreeNode<T> *root)const;//后根遍历
	void Levelorder(BinaryTreeNode<T> *root)const;//层次遍历
	BinaryTreeNode<T> *ReturnRoot()const;//返回根节点
	void DeleteBT(const BinaryTreeNode<T> *root);//删除二叉树
	BinaryTreeNode<T>* Find(const BinaryTreeNode<T>* root,const T &item)const;//查找值为item的结点
};
#endif

