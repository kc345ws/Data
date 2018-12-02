#pragma once
#ifndef _HEAD
#define _HEAD

//单链表的结点
template<typename T>
class SLLNode
{
public:
	T data;//链表的数据节点
	SLLNode<T> *next;//链表的下一个节点
};

//单链表
template<typename T>
class SLList
{
private:
	SLLNode<T> *head;//哨兵节点
	SLLNode<T> *tail;//尾结点
public:
	SLList();
	SLList(T& item);
	~SLList();
	void CreateNode(const T &item);//创建结点
	void Insert(int k, const T &item);//在第k个位置后插入
	bool Delete(int k, T &item);//删除第k个结点
	bool Find(int k, T &item)const;//存取链表中第k个位置的值
	int Search(const T &item)const;//查找item在链表中的位置
	bool Isempty()const;//判断是否为空
	int Length();//链表的长度
	void Show();//显示链表
	void TailInsert(const T&item);//表尾插入
	void TailDelete();//表尾删除
};

#endif