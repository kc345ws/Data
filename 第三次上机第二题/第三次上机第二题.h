#pragma once
#ifndef _HEAD
#define _HEAD


class SortingAlgorithm
{
private:
	int *Data;
	int SortNumber;
	int Times;//�Ƚϴ���
public:
	SortingAlgorithm();
	void QSort(int *data,int m, int n);//���������㷨
	int Partition(int *Data, int m , int n);//�ֻ��㷨
	int ReturnSortNumber() { return SortNumber; }
	int *ReturnData() { return Data; }
	int ReturnTimes() { return Times; }
};
#endif