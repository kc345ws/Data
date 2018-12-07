#pragma once
#ifndef _HEAD
#define _HEAD

template<typename T>
class TreeNode
{
public:
	T Data;
	TreeNode<T>* FirstChild;
	TreeNode<T>* NextBother;
};

template<typename T>
class Tree//��
{
private:
	TreeNode<T>* Root;//���ĸ��ڵ�

public:
	Tree();
	Tree(T&item);
	TreeNode<T> *CreateTree(TreeNode<T> *root);
	TreeNode<T> *ReturnRoot()const { return Root; }//���ظ��ڵ�
	void Preorder(TreeNode<T> *root);//�ȸ������ݹ��㷨
	void Postorder(TreeNode<T> *root);//��������ݹ��㷨
	void Levelorder(TreeNode<T> *root)const;//��α���
	TreeNode<T>* GFC(TreeNode<T> *root);//���Ҵ�����ֵ�
	TreeNode<T>* GNB(TreeNode<T>*root);//�����ֵܽ��
	void NPO(TreeNode<T> *root);//�ȸ����������㷨
	void NPT(TreeNode<T> *root);//������������㷨
};

template<typename T>
class Forest//ɭ��
{
private:
	
public:
	TreeNode<T>*VirtualRoot;
	int ForestSize;
	TreeNode<T>*Root[];
	

	Forest();
	Forest(T&item);
	void CreateForest();
	TreeNode<T> *CreateForestTree(TreeNode<T> *root);
	TreeNode<T> *ReturnRoot()const { return Root; }//���ظ��ڵ�
	void ForestPreorder(TreeNode<T> *root);//�ȸ������ݹ��㷨
	void Pre(TreeNode<T>*root[]);
	void ForestPostorder(TreeNode<T> *root);//��������ݹ��㷨
	void Pos(TreeNode<T>*root[]);
	void ForestLevelorder(TreeNode<T> *root);//��α���
	//TreeNode<T>* GFC(TreeNode<T> *root);//���Ҵ�����ֵ�
	//TreeNode<T>* GNC(TreeNode<T>*root);//�����ֵܽ��
	void ForestNPO(TreeNode<T> *root);//�ȸ����������㷨
	void ForestNPT(TreeNode<T> *root);//������������㷨
	void Levelorder(TreeNode<T> *root[]);//��α���
	void Level(TreeNode<T>*root[]);
	//TreeNode<T> *ReturnRoot()const { return Root; }//���ظ��ڵ�
	void NPO(TreeNode<T> *root);//�ȸ����������㷨
	void NPT(TreeNode<T> *root);//������������㷨

	void NPOF(TreeNode<T> *root[]);//�ȸ����������㷨
	void NPTF(TreeNode<T> *root[]);//������������㷨

	TreeNode<T>* GFC(TreeNode<T> *root);//���Ҵ�����ֵ�
	TreeNode<T>* GNB(TreeNode<T>*root);//�����ֵܽ��
};
#endif // !_HEAD


