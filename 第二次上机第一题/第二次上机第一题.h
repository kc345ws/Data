#pragma once
#ifndef _HEAD
#define _HEAD

template<typename T>
class BinaryTreeNode//��������㶨��
{
public:
	T Data;//������
	BinaryTreeNode *Right;//���ӽ��
	BinaryTreeNode *Left;//���ӽ��
};

template<typename T>
class BinaryTree
{
private:
	BinaryTreeNode<T> *Root;//�����������

public:
	BinaryTree();
	BinaryTree(T &item);
	~BinaryTree();
	BinaryTreeNode<T>* CreateBT(BinaryTreeNode<T> *root);//����������
	void Inorder(BinaryTreeNode<T> *root)const;//�и�����
	void Preorder(BinaryTreeNode<T> *root)const;//�ȸ�����
	void Postorder(BinaryTreeNode<T> *root)const;//�������
	void Levelorder(BinaryTreeNode<T> *root)const;//��α���
	BinaryTreeNode<T> *ReturnRoot()const;//���ظ��ڵ�
	void DeleteBT(const BinaryTreeNode<T> *root);//ɾ��������
	BinaryTreeNode<T>* Find(const BinaryTreeNode<T>* root,const T &item)const;//����ֵΪitem�Ľ��
};
#endif

