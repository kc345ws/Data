#include<iostream>
#include"��һ���ϻ��ڶ���.h"

using namespace std;
AStack<int> *astcktest;
void Menu();

int main()
{
	Menu();
}

void Menu()
{

	cout << "1.����˳��ջ" << endl;
	cout << "2.�������" << endl;
	cout << "3.ɾ������" << endl;
	cout << "4.��ȡ����" << endl;
	cout << "5.��ӡջ������Ԫ��" << endl;

	int select;
	int item;
	cin >> select;
	switch (select)
	{
	case 1:
		cout << "������ջ�Ĵ�С" << endl;
		int size;
		cin >> size;
		astcktest = new AStack<int>(size);
		cout << endl;
		Menu();
		break;
	case 2:
		cout << "������ѹջԪ�ص�ֵ" << endl;
		cin >> item;
		if (astcktest->Push(item))
		{
			cout << "ѹջ�ɹ�" << endl;
		}
		else
		{
			cout << "ջ�����޷�ѹ��" << endl;
		}
		cout << endl;
		Menu();
		break;
	case 3:
		if (astcktest->Pop(item))
		{
			cout << "�ɹ�����ջ��Ԫ��" << item << endl;
		}
		else
		{
			cout << "ջ�յ���ʧ��" << endl;
		}
		cout << endl;
		Menu();
		break;
	case 4:
		if (astcktest->Peek(item))
		{
			cout << "ջ��Ԫ��Ϊ:" << item <<endl;
		}
		else
		{
			cout << "ջ��" << endl;
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
	if (!isFull())//���ջ����
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
	if (!IsEmpty())//���ջ����
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
	cout << "ջ��Ԫ��Ϊ" << endl;
	for (int i = 0; i <= top; i++)
	{
		cout << AStackArray[i] << " ";
	}
	cout << endl;
}