#pragma once
#ifndef _HEAD
#define _HEAD


class SortingAlgorithm
{
private:
	int *Data;
	int SortNumber;
	int Times;//比较次数
public:
	SortingAlgorithm();
	void QSort(int *data,int m, int n);//快速排序算法
	int Partition(int *Data, int m , int n);//分划算法
	int ReturnSortNumber() { return SortNumber; }
	int *ReturnData() { return Data; }
	int ReturnTimes() { return Times; }
};
#endif