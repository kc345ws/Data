#include<iostream>
#include"第一次上机第一题.h"
using namespace std;

SLList<int> *sllisttest = new SLList<int>();
//单链表相关算法的实验验证
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
	cout << "1.创建单链表" << endl;
	cout << "2.查看单链表长度" << endl;
	cout << "3.查看是否为空" << endl;
	cout << "4.删除结点" << endl;
	cout << "5.存取结点" << endl;
	cout << "6.查找结点" << endl;
	cout << "7.插入结点" << endl;
	cout << "8.显示链表" << endl;
	//cout << "9.删除链表" << endl;
	cout << "9.表尾插入" << endl;
	cout << "10.表尾删除" << endl;
	cin >> select;
	switch (select)
	{
	case 1:
		CreateList();
		cout << endl;
		cout << "创建完毕" << endl;
		Menu();
		break;
	case 2:
		cout << "该链表长度为" << endl;
		cout << sllisttest->Length() << endl;;
		Menu();
		break;
	case 3:
		if (sllisttest->Isempty() == 1)
		{
			cout << "该链表非空" << endl;
		}
		if (sllisttest->Isempty() == 0)
		{
			cout << "该链表为空" << endl;
		}
		Menu();
		break;
	case 4:
		cout << "请输入要删除的结点位置" << endl;
		cin >> k;
		if (sllisttest->Delete(k, item))
		{
			cout << "item:" << item << endl;
		}
		else
		{
			cout << "此位置没有结点" << endl;
		}
		Menu();
		break;
	case 5:
		cout << "请输入要存取结点的值" << endl;
		cin >> item;
		cout << "位置:" <<sllisttest->Search(item) <<endl;
		Menu();
		break;
	case 6:
		cout << "请输入要查找的结点的位置" << endl;
		cin >> k;
		if (sllisttest->Find(k, item))
		{
			cout << "该位置结点的值:" << item << endl;
		}
		else
		{
			cout << "该位置没有结点" <<  endl;
		}
		Menu();
		break;
	case 7:
		cout << "请输入要插入的值以及位置" << endl;
		cin >> item;
		cin >> k;
		sllisttest->Insert(k, item);
		cout << "插入后的链表:" << endl;
		sllisttest->Show();
		cout << endl;
		Menu();
		break;
	case 8:
		cout << "链表:" << endl;
		sllisttest->Show();
		cout << endl;
		Menu();
		break;
	case 9:
		cout << "请输入要插入的值" << endl;
		cin >> item;
		sllisttest->TailInsert(item);
		cout << "插入后的链表" << endl;
		sllisttest->Show();
		cout << endl;
		Menu();
		break;
	/*case 9:
		delete(sllisttest);
		cout << "删除完毕" << endl;
		Menu();
		break;*/
	case 10:
		sllisttest->TailDelete();
		cout << "删除后的链表:" << endl;
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
	cout << "请输入要创建的结点个数" << endl;
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		count++;
		cout << "输入第" << count << "个结点的值" << endl;
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
	head = new SLLNode<T>();//构造哨兵节点数据节点为空
	head->next = nullptr;
	tail = head;//尾结点
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
	head = new SLLNode<int>();//构造哨兵节点数据节点为空
	head->next = nullptr;
	tail = head;//尾结点
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
		return false;//如果只有哨兵节点链表为空
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

