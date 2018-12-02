#include<iostream>
#include"��һ���ϻ���һ��.h"
using namespace std;

SLList<int> *sllisttest = new SLList<int>();
//����������㷨��ʵ����֤
void CreateList();
void Menu();

int main()
{
	Menu();
}

void Menu()
{
	int select;
	int k;
	int item;
	cout << "1.����������" << endl;
	cout << "2.�鿴��������" << endl;
	cout << "3.�鿴�Ƿ�Ϊ��" << endl;
	cout << "4.ɾ�����" << endl;
	cout << "5.��ȡ���" << endl;
	cout << "6.���ҽ��" << endl;
	cout << "7.������" << endl;
	cout << "8.��ʾ����" << endl;
	//cout << "9.ɾ������" << endl;
	cout << "9.��β����" << endl;
	cout << "10.��βɾ��" << endl;
	cin >> select;
	switch (select)
	{
	case 1:
		CreateList();
		cout << endl;
		cout << "�������" << endl;
		Menu();
		break;
	case 2:
		cout << "��������Ϊ" << endl;
		cout << sllisttest->Length() << endl;;
		Menu();
		break;
	case 3:
		if (sllisttest->Isempty() == 1)
		{
			cout << "������ǿ�" << endl;
		}
		if (sllisttest->Isempty() == 0)
		{
			cout << "������Ϊ��" << endl;
		}
		Menu();
		break;
	case 4:
		cout << "������Ҫɾ���Ľ��λ��" << endl;
		cin >> k;
		if (sllisttest->Delete(k, item))
		{
			cout << "item:" << item << endl;
		}
		else
		{
			cout << "��λ��û�н��" << endl;
		}
		Menu();
		break;
	case 5:
		cout << "������Ҫ��ȡ����ֵ" << endl;
		cin >> item;
		cout << "λ��:" <<sllisttest->Search(item) <<endl;
		Menu();
		break;
	case 6:
		cout << "������Ҫ���ҵĽ���λ��" << endl;
		cin >> k;
		if (sllisttest->Find(k, item))
		{
			cout << "��λ�ý���ֵ:" << item << endl;
		}
		else
		{
			cout << "��λ��û�н��" <<  endl;
		}
		Menu();
		break;
	case 7:
		cout << "������Ҫ�����ֵ�Լ�λ��" << endl;
		cin >> item;
		cin >> k;
		sllisttest->Insert(k, item);
		cout << "����������:" << endl;
		sllisttest->Show();
		cout << endl;
		Menu();
		break;
	case 8:
		cout << "����:" << endl;
		sllisttest->Show();
		cout << endl;
		Menu();
		break;
	case 9:
		cout << "������Ҫ�����ֵ" << endl;
		cin >> item;
		sllisttest->TailInsert(item);
		cout << "����������" << endl;
		sllisttest->Show();
		cout << endl;
		Menu();
		break;
	/*case 9:
		delete(sllisttest);
		cout << "ɾ�����" << endl;
		Menu();
		break;*/
	case 10:
		sllisttest->TailDelete();
		cout << "ɾ���������:" << endl;
		sllisttest->Show();
		cout << endl;
		Menu();
		break;
	default:
		Menu();
		break;
	}
}

void CreateList()
{
	sllisttest = new SLList<int>();
	int count = 0;
	int item;
	cout << "������Ҫ�����Ľ�����" << endl;
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		count++;
		cout << "�����" << count << "������ֵ" << endl;
		cin >> item;
		sllisttest->CreateNode(item);
	}


	sllisttest->Show();
}

template<typename T>
void SLList<T>::Show()
{
	SLLNode<T> *temp = head->next;
	while (temp)
	{
		if (!temp->next)
		{
			cout << "[" << temp->data << "]";
		}
		else
		{
			cout << "[" << temp->data << "]->";
		}
		temp = temp->next;
	}

}

template<typename T>
SLList<T>::SLList()
{
	head = new SLLNode<T>();//�����ڱ��ڵ����ݽڵ�Ϊ��
	head->next = nullptr;
	tail = head;//β���
}

template<typename T>
SLList<T>::~SLList()
{
	SLLNode<T> *tempback = head;
	SLLNode<T> *tempforwad = head;
	while(tempback)
	{
		tempback = tempback->next;
		delete(tempforwad);
		tempforwad = tempback;
	}
}

template<typename T>
void SLList<T>::CreateNode(const T &item)
{
	SLLNode<T> *node = new SLLNode<T>();
	node->data = item;
	tail->next = node;
	tail = node;
	tail->next = nullptr;
}



template<typename T>
SLList<T>::SLList(T & item)
{
	head = new SLLNode<int>();//�����ڱ��ڵ����ݽڵ�Ϊ��
	head->next = nullptr;
	tail = head;//β���
	SLLNode<T> *node = new SLLNode<T>();
	node->data = item;
	tail->next = node;
	tail = node;
}

template<typename T>
bool SLList<T>::Isempty()const
{
	if (!head->next)
	{
		return false;//���ֻ���ڱ��ڵ�����Ϊ��
	}
	else
	{
		return true;
	}

}

template<typename T>
int SLList<T>::Length()
{
	int Count = 0;
	SLLNode<T> *temp = head;
	while (temp->next)
	{
		Count++;
		temp = temp->next;
	}
	return Count;
}

template<typename T>
bool SLList<T>::Delete(int k, T &item)
{
	SLLNode<T> *tempforwad = head;
	SLLNode<T> *tempback = head;
	int count = 0;
	while (tempback)
	{
		count++;
		tempback = tempback->next;
		if (count == k)
		{
			tempforwad->next = tempback->next;
			item = tempback->data;
			delete(tempback);
			return true;
			break;
		}
		tempforwad = tempback;
	}
	return false;
}

template<typename T>
bool SLList<T>::Find(int k, T &item)const
{
	SLLNode<T> *temp = head->next;
	int Count = 0;
	while (temp)
	{
		Count++;
		if (Count == k)
		{
			item = temp->data;
			return true;
			break;
		}
		temp = temp->next;
	}
	return false;
}

template<typename T>
int SLList<T>::Search(const T &item)const
{
	SLLNode<T> *temp = head->next;
	int Count = 0;
	while (temp)
	{
		Count++;
		if (temp->data == item)
		{
			return Count;
			break;
		}
		temp = temp->next;
	}
	return -1;
}

template<typename T>
void SLList<T>::Insert(int k, const T &item)
{
	SLLNode<T> *temp = head;
	int Count = 0;
	while (temp)
	{
		if (Count == k)
		{
			if (temp == tail)
			{
				SLLNode<T> *newnode = new SLLNode<T>();
				newnode->data = item;
				newnode->next = temp->next;
				temp->next = newnode;
				tail = newnode;
			}
			else
			{
				SLLNode<T> *newnode = new SLLNode<T>();
				newnode->data = item;
				newnode->next = temp->next;
				temp->next = newnode;
			}
			break;
		}
		Count++;
		temp = temp->next;
	}
}

template<typename T>
void SLList<T>::TailInsert(const T &item)
{
	SLLNode<T> *newnode = new SLLNode<T>();
	newnode->data = item;
	tail->next = newnode;
	tail = newnode;
}

template<typename T>
void SLList<T>::TailDelete()
{
	SLLNode<T> *temp = head;
	while (temp)
	{
		if (temp->next == tail)
		{
			break;
		}
		temp = temp->next;
	}
	if (Isempty())
	{
		delete(tail);
		tail = temp;
		tail->next = nullptr;
	}
}

