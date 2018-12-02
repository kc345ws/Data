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
	int NodeNumber;
	int Height;
public:
	BinaryTree();
	BinaryTree(T &item);
	~BinaryTree();
	BinaryTreeNode<T>* CreateBT(BinaryTreeNode<T> *root);//����������
	void Inorder(BinaryTreeNode<T> *root)const;//�и�����
	void Preorder(BinaryTreeNode<T> *root)const;//�ȸ�����
	void Postorder(BinaryTreeNode<T> *root)const;//�������
	void Levelorder(BinaryTreeNode<T> *root)const;//��α���
	BinaryTreeNode<T> *ReturnRoot()const { return Root; }//���ظ��ڵ�
	void DeleteBT(const BinaryTreeNode<T> *root);//ɾ��������
	BinaryTreeNode<T>* Find(BinaryTreeNode<T>* root,const T &item)const;//����ֵΪitem�Ľ��
	int GetNodeNumber() { return NodeNumber; }//�������н��ĸ���
	int GetHeight(const BinaryTreeNode<T>* root);//��ö������ĸ߶�
	BinaryTreeNode<T>* Parent(BinaryTreeNode<T>* root, const T &item)const;//Ѱ��ֵΪitem���ĸ��ڵ�
	bool InsertLL(T& insert, T& inserted);//������λ�����ӽڵ㣬ԭ�������Ϊ������������
	bool DST(BinaryTreeNode<T>* root, T &item);//ɾ��ָ����㼰�����Һ���
	void GetLeaves(BinaryTreeNode<T>*root);//��ȡ����Ҷ�ӽ��
};
#endif

