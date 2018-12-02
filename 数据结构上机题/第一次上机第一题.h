#pragma once
#ifndef _HEAD
#define _HEAD

//������Ľ��
template<typename T>
class SLLNode
{
public:
	T data;//��������ݽڵ�
	SLLNode<T> *next;//�������һ���ڵ�
};

//������
template<typename T>
class SLList
{
private:
	SLLNode<T> *head;//�ڱ��ڵ�
	SLLNode<T> *tail;//β���
public:
	SLList();
	SLList(T& item);
	~SLList();
	void CreateNode(const T &item);//�������
	void Insert(int k, const T &item);//�ڵ�k��λ�ú����
	bool Delete(int k, T &item);//ɾ����k�����
	bool Find(int k, T &item)const;//��ȡ�����е�k��λ�õ�ֵ
	int Search(const T &item)const;//����item�������е�λ��
	bool Isempty()const;//�ж��Ƿ�Ϊ��
	int Length();//����ĳ���
	void Show();//��ʾ����
	void TailInsert(const T&item);//��β����
	void TailDelete();//��βɾ��
};

#endif