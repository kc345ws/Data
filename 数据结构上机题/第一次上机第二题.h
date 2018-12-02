#pragma once
#ifndef _HEAD
#define _HEAD

//顺序栈类的定义
template<typename T>
class AStack
{
private:
	int size;//顺序栈的规模
	T* AStackArray;//存放堆栈元素的数组
	int top;//栈顶下标
public:
	AStack();
	AStack(int maxsize);
	~AStack();
	bool Push(const T &item);//压入元素
	bool Pop(T &item);//弹栈
	bool Peek(T &item)const;//查看栈顶元素
	bool IsEmpty()const;//检测栈是否为空
	bool isFull()const;//检测栈是否满了
	void Clear();//清空栈
	void Show();//打印栈内元素	
};
#endif // !_HEAD

