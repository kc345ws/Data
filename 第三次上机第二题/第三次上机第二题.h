#pragma once
#ifndef _HEAD
#define _HEAD


class SortingAlgorithm
{
private:
	int *Data;
	int SortNumber;
public:
	SortingAlgorithm();

	void InsertSort();//���������㷨
	void Bubble();//ð�������㷨
	void SelectSort();//ѡ�������㷨
	void HeapSort();//�������㷨
	void DCSort();//�ϲ������㷨
};
#endif