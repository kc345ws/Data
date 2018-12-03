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
class Tree//树
{
private:
	TreeNode<T>* Root;//树的根节点

public:
	Tree();
	Tree(T&item);
	TreeNode<T> *CreateTree(TreeNode<T> *root);
	TreeNode<T> *ReturnRoot()const { return Root; }//返回根节点
	void Preorder(TreeNode<T> *root)const;//先根遍历递归算法
	void Postorder(TreeNode<T> *root)const;//后根遍历递归算法
	void Levelorder(TreeNode<T> *root)const;//层次遍历
	TreeNode<T>* GFC(TreeNode<T> *root);//查找大儿子兄弟
	TreeNode<T>* GNC(TreeNode<T>*root);//查找兄弟结点
	void NPO(TreeNode<T> *root);//先根遍历迭代算法
	void NPT(TreeNode<T> *root);//后根遍历迭代算法
};

template<typename T>
class Forest//森林
{
private:
	
	

	
public:
	int ForestSize;
	TreeNode<T>*Root[];
	Forest();
	Forest(T&item);
	void CreateForest();
	TreeNode<T> *CreateForestTree(TreeNode<T> *root);
	TreeNode<T> *ReturnRoot()const { return Root; }//返回根节点
	void ForestPreorder(TreeNode<T> *root)const;//先根遍历递归算法
	void Pre(TreeNode<T>*root[]);
	void ForestPostorder(TreeNode<T> *root)const;//后根遍历递归算法
	void Pos(TreeNode<T>*root[]);
	void ForestLevelorder(TreeNode<T> *root)const;//层次遍历
	//TreeNode<T>* GFC(TreeNode<T> *root);//查找大儿子兄弟
	//TreeNode<T>* GNC(TreeNode<T>*root);//查找兄弟结点
	void ForestNPO(TreeNode<T> *root);//先根遍历迭代算法
	void ForestNPT(TreeNode<T> *root);//后根遍历迭代算法
	void Levelorder(TreeNode<T> *root)const;//层次遍历
	void Level(TreeNode<T>*root[]);
	//TreeNode<T> *ReturnRoot()const { return Root; }//返回根节点

	void NPO(TreeNode<T> *root);//先根遍历迭代算法
	void NPT(TreeNode<T> *root);//后根遍历迭代算法
};
#endif // !_HEAD


