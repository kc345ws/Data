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

	void InsertSort();//插入排序算法
	void Bubble();//冒泡排序算法
	void SelectSort();//选择排序算法
	void HeapSort();//堆排序算法
	void DCSort();//合并排序算法
};
#endif