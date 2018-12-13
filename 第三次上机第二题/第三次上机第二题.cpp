#include<iostream>
#include"�������ϻ��ڶ���.h"
#include<time.h>
#include <fstream>
using namespace std;
SortingAlgorithm *Sort;
int AllTims = 0;
int SortNum = 0;
void Menu();
void ShowAverageTime();
int main()
{
	Menu();
}

void Menu()
{
	ofstream FILE;
	int select;
	int m;
	cout << "1.��������" << endl;
	cout << "2.��������" << endl;
	cout << "3.ƽ���Ƚϴ���" << endl;
	while (1)
	{
		cin >> select;

		if (!std::cin || select == '#')
		{
			cin.clear();
			cin.get();
			cout << "����������" << endl;
			cin >> select;
		}
		switch (select)
		{
		case 1:
			Sort = new SortingAlgorithm();

			FILE.open("data.txt",ios::app);
			FILE << "����ǰ�Ľ��" << endl;
			for (int i = 0; i < Sort->ReturnSortNumber(); i++)
			{
				FILE << Sort->ReturnData()[i] << " ";
			}
			FILE << endl;
			FILE.close();
			cout << endl;
			Menu();
			break;
		case 2:
			m = 0;
			while (m<0 || m>Sort->ReturnSortNumber())
			{
				cout << "��������ݳ�����Χ����������" << endl;
				cin >> m;
			}
			Sort->QSort(Sort->ReturnData(),m,Sort->ReturnSortNumber() - 1);

			FILE.open("data.txt", ios::app);
			cout << "�����Ľ��" << endl;
			FILE << "�����Ľ��" << endl;
			for (int i = 0; i < Sort->ReturnSortNumber(); i++)
			{
				cout << Sort->ReturnData()[i] << " ";
				FILE << Sort->ReturnData()[i] << " ";
			}
			FILE << endl;
			cout << endl;
			cout << "�Ƚϴ���:" << endl;
			FILE << "�Ƚϴ���" << endl;
			cout << Sort->ReturnTimes() << endl;
			cout << endl;
			FILE << Sort->ReturnTimes() << endl;
			FILE << endl;
			FILE.close();
			AllTims += Sort->ReturnTimes();
			SortNum++;
			Menu();
			break;
		
		case 3:
			ShowAverageTime();
			cout << endl;
			Menu();
		default:
			break;
		}
	}
}

void ShowAverageTime()
{
	ofstream FILE;
	FILE.open("data.txt", ios::app);
	cout << "ƽ���Ƚϴ���" << endl;
	FILE << "ƽ���Ƚϴ���" << endl;
	cout << AllTims / SortNum << endl;
	FILE << AllTims / SortNum << endl;
	FILE.close();
}

inline SortingAlgorithm::SortingAlgorithm()
{
	cout << "��������������" << endl;
	cin >> SortNumber;
	Data = new int[SortNumber];

	srand((unsigned)time(NULL));
	for (int i = 0; i < SortNumber - 1; i++)
	{
		Data[i] = rand() % 1000000;
		if (Data[i] < 10)
		{
			Data[i] += 10;
		}
	}
	Data[SortNumber - 1] = 1000001;
	cout << "����Ϊ�漴���ɵ�����" << endl;
	for (int i = 0; i < SortNumber; i++)
	{
		cout << Data[i] << " ";
	}
	Times = 0;
}

void SortingAlgorithm::QSort(int *data, int m, int n)
{
	if (m < n)
	{
		int j = Partition(data, m, n);
		QSort(data, m, j - 1);
		QSort(data,j + 1, n);
	}
}

//�������� ��׼Ԫ��λ�� Ԫ�ظ���-1
int SortingAlgorithm::Partition(int *data, int m, int n)
{
	int i = m;
	int j = n + 1;
	int K = data[m];
	int Temp;
	while (i < j)
	{
		i++;
		while (data[i] < K)
		{
			i++;
			Times++;
		}
		j--;
		while (data[j] > K)
		{
			j--;
			Times++;
		}
		if (i < j)
		{
			Temp = data[i];
			data[i] = data[j];
			data[j] = Temp;
			Times++;
		}
	}
	Temp = data[m];
	data[m] = data[j];
	data[j] = Temp;
	return j;
}
