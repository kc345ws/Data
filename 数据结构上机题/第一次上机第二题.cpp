#include<iostream>
#include"第一次上机第二题.h"

using namespace std;
AStack<int> *astcktest;
void Menu();

int main()
{
	Menu();
}

void Menu()
{

	cout << "1.创建顺序栈" << endl;
	cout << "2.插入操作" << endl;
	cout << "3.删除操作" << endl;
	cout << "4.存取操作" << endl;
	cout << "5.打印栈内所有元素" << endl;

	int select;
	int item;
	cin >> select;
	switch (select)
	{
	case 1:
		cout << "请输入栈的大小" << endl;
		int size;
		cin >> size;
		astcktest = new AStack<int>(size);
		cout << endl;
		Menu();
		break;
	case 2:
		cout << "请输入压栈元素的值" << endl;
		cin >> item;
		if (astcktest->Push(item))
		{
			cout << "压栈成功" << endl;
		}
		else
		{
			cout << "栈已满无法压入" << endl;
		}
		cout << endl;
		Menu();
		break;
	case 3:
		if (astcktest->Pop(item))
		{
			cout << "成功弹出栈顶元素" << item << endl;
		}
		else
		{
			cout << "栈空弹出失败" << endl;
		}
		cout << endl;
		Menu();
		break;
	case 4:
		if (astcktest->Peek(item))
		{
			cout << "栈顶元素为:" << item <<endl;
		}
		else
		{
			cout << "栈空" << endl;
		}
		cout << endl;
		Menu();
		break;
	case 5:
		astcktest->Show();
		cout << endl;
		Menu();
		break;
	default:
		cout << endl;
		Menu();
		break;
	}
}

template<typename T>
AStack<T>::AStack(int maxsize)
{
	size = maxsize;
	AStackArray = new T[size];
	top = -1;
}

template<typename T>
AStack<T>::~AStack()
{
	delete[]AStackArray;
}

template<typename T>
bool AStack<T>::Push(const T &item)
{
	if (!isFull())//如果栈不满
	{
		AStackArray[top + 1] = item;
		top++;
		return true;
	}
	return false;
}

template<typename T>
bool AStack<T>::Pop(T &item)
{
	if (!IsEmpty())//如果栈不空
	{
		item = AStackArray[top];
		top--;
		return true;
	}
	return false;
}

template<typename T>
bool AStack<T>::Peek(T &item)const
{
	if (!IsEmpty())
	{
		item = AStackArray[top];
		return true;
	}
	return false;
}

template<typename T>
bool AStack<T>::IsEmpty()const
{
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool AStack<T>::isFull()const
{
	if (top == size - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
void AStack<T>::Clear()
{
	delete[]AStackArray;
}

template<typename T>
void AStack<T>::Show()
{
	cout << "栈内元素为" << endl;
	for (int i = 0; i <= top; i++)
	{
		cout << AStackArray[i] << " ";
	}
	cout << endl;
}