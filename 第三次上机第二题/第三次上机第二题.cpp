#include<iostream>
#include"第三次上机第二题.h"
#include<time.h>
using namespace std;
SortingAlgorithm *Sort;
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
	int temp;
	cout << "1.创建数据" << endl;

	while (1)
	{

		cin >> select;

		if (!std::cin || select == '#')
		{
			cin.clear();
			cin.get();
			cout << "请重新输入" << endl;
			cin >> select;
		}
		switch (select)
		{
		case 1:
			Sort = new SortingAlgorithm();

			cout << endl;
			Menu();
			break;
		case 2:
			
			cout << endl;
			Menu();
			break;
		case 3:
			

			cout << endl;
			Menu();
			break;
		case 4:


			cout << endl;
			Menu();
			break;

		case 5:


			cout << endl;
			Menu();
			break;

		case 6:


			cout << endl;
			Menu();
			break;
		case 7:


			cout << endl;
			Menu();
			break;

		case 8:


			cout << endl;
			Menu();
			break;

		case 9:


			cout << endl;
			Menu();
			break;

		case 10:


			cout << endl;
			Menu();
			break;

		case 11:

			cout << endl;
			Menu();
			break;

		case 12:


			cout << endl;
			Menu();
			break;

		default:
			break;
		}
	}
}

inline SortingAlgorithm::SortingAlgorithm()
{
	cout << "请输入数据数量" << endl;
	cin >> SortNumber;
	Data = new int[SortNumber];

	srand((unsigned)time(NULL));
	for (int i = 0; i < SortNumber; i++)
	{
		Data[i] = rand()%100;
	}

	for (int i = 0; i < SortNumber; i++)
	{
		cout << Data[i] << " ";
	}
}


void SortingAlgorithm::InsertSort()
{
}


void SortingAlgorithm::Bubble()
{
}

void SortingAlgorithm::SelectSort()
{
}


void SortingAlgorithm::HeapSort()
{

}

void SortingAlgorithm::DCSort()
{
}
