#pragma once
#ifndef _HEAD
#define _HEAD
template<typename T>
class Graph_List;

template<typename T>
class Graph_Matrix//ͼ���ڽӾ����ʾ
{
private:
	const int MaxGraphSize = 256;//ͼ����󶥵����
	const int MaxWeight = 1000;//ͼ�����Ȩֵ
	T **Edges;//�ڽӾ���
	int GraphSize;//��ǰͼ�ж���ĸ���

public:
	Graph_Matrix();
	bool IsEmpty()const;//���ͼ�Ƿ�Ϊ��
	int NumberOfVertices()const;//ͼ�ж���ĸ���
	int NumberOfEdges()const;//ͼ�бߵĸ���
	int GetWeight(const T v1, const T v2);//����ָ���ߵ�Ȩֵ
	int GetFirstNeighbor(const T v);//�������Ϊv�Ķ���ĵ�һ���ڽӶ�������
	int GetNextNeighbor(const int v1, const int v2);  //�������Ϊv1�Ķ�����������Ϊv2�Ķ������һ���ڽӶ�������
	void InsertVertex(const int v);  // ����һ������
	void InsertEdge(const int v1, const int v2, int weight);  // ����һ����(v1, v2)����ȨֵΪweight
	void DeleteVertex(const int v);  // ��ͼ��ɾȥ����v ����������������ı�
	void DeleteEdge(const int v1, const int v2);  // ��ͼ��ɾȥ��(v1, v2) 
};




//ͼ���ڽӱ���
template<typename T>
class Edge//�߽��ṹ  �ڽӱ�Ϊ���Ӵ洢
{
public:
	friend class Graph_List<T>;
	int verAdj;//�ڽӶ������(�ý���ڶ�����е�λ��)
	int cost;//�ߵ�Ȩֵ
	Edge *next;//��һ���߽���ָ��
};


template<typename T>
class Vertex//����ṹ  �����Ϊ˳��洢
{
public:
	friend class Graph_List<T>;
	T verinfor;//��������� v0  1  A��
	Edge<T> *adjacent;//�������ͷָ��
};

template<typename T>
class Graph_List//ͼ���ڽӱ���ʽ����
{
private:
	Vertex<T> *vertices;//������ͷָ�� 
	int GraphSize;//����ĸ���
	//int *Visited;//���ʱ������

public:
	Graph_List();
	int GetFirstNeighbor(const int v);//�������Ϊv�Ķ���ĵ�һ���ڽӶ�������
	int GetNextNeighbor(const int v1, const int v2);
	/*�����Ϊv1�Ķ�����ڽӱ������ΪV2����һ���߽������*/
	//int* ReturnVisited(){ return Visited; }
	void DepthFirstSearch(const int v,int *visited);//������ȱ��� ����˼�������������ȸ�����
	void DFS_Main();
	void BreadthFirstSearch(int v);//������ȱ��� �������Ĳ�α���
	void Insert(const int v1 , const int v2);//����һ�����
	void InsertEdge(const int v1 , const int v2);//����һ����
	void Delete(const int adj);//ɾ��һ������
	bool DeleteEdge(const int v1, const int v2);//ɾ��һ����
	int GetCost(const int v1 , const int v2);//����ָ���ߵ�Ȩֵ
	int ReturnGraphSize() { return GraphSize; };
};
#endif