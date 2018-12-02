#pragma once
#ifndef _HEAD
#define _HEAD

//˳��ջ��Ķ���
template<typename T>
class AStack
{
private:
	int size;//˳��ջ�Ĺ�ģ
	T* AStackArray;//��Ŷ�ջԪ�ص�����
	int top;//ջ���±�
public:
	AStack();
	AStack(int maxsize);
	~AStack();
	bool Push(const T &item);//ѹ��Ԫ��
	bool Pop(T &item);//��ջ
	bool Peek(T &item)const;//�鿴ջ��Ԫ��
	bool IsEmpty()const;//���ջ�Ƿ�Ϊ��
	bool isFull()const;//���ջ�Ƿ�����
	void Clear();//���ջ
	void Show();//��ӡջ��Ԫ��	
};
#endif // !_HEAD

