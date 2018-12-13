#include<iostream>
#include"第三次上机第二题.h"
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
	cout << "1.创建数据" << endl;
	cout << "2.快速排序" << endl;
	cout << "3.平均比较次数" << endl;
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

			FILE.open("data.txt",ios::app);
			FILE << "排序前的结果" << endl;
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
				cout << "输入的数据超出范围请重新输入" << endl;
				cin >> m;
			}
			Sort->QSort(Sort->ReturnData(),m,Sort->ReturnSortNumber() - 1);

			FILE.open("data.txt", ios::app);
			cout << "排序后的结果" << endl;
			FILE << "排序后的结果" << endl;
			for (int i = 0; i < Sort->ReturnSortNumber(); i++)
			{
				cout << Sort->ReturnData()[i] << " ";
				FILE << Sort->ReturnData()[i] << " ";
			}
			FILE << endl;
			cout << endl;
			cout << "比较次数:" << endl;
			FILE << "比较次数" << endl;
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
	cout << "平均比较次数" << endl;
	FILE << "平均比较次数" << endl;
	cout << AllTims / SortNum << endl;
	FILE << AllTims / SortNum << endl;
	FILE.close();
}

inline SortingAlgorithm::SortingAlgorithm()
{
	cout << "请输入数据数量" << endl;
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
	cout << "以下为随即生成的数据" << endl;
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

//数据数组 基准元素位置 元素个数-1
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
