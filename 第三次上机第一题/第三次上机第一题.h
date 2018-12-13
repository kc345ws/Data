#pragma once
#ifndef _HEAD
#define _HEAD
template<typename T>
class Graph_List;

template<typename T>
class Graph_Matrix//图的邻接矩阵表示
{
private:
	const int MaxGraphSize = 256;//图的最大顶点个数
	const int MaxWeight = 1000;//图的最大权值
	T **Edges;//邻接矩阵
	int GraphSize;//当前图中顶点的个数

public:
	Graph_Matrix();
	bool IsEmpty()const;//检测图是否为空
	int NumberOfVertices()const;//图中顶点的个数
	int NumberOfEdges()const;//图中边的个数
	int GetWeight(const T v1, const T v2);//返回指定边的权值
	int GetFirstNeighbor(const T v);//返回序号为v的顶点的第一个邻接顶点的序号
	int GetNextNeighbor(const int v1, const int v2);  //返回序号为v1的顶点相对于序号为v2的顶点的下一个邻接顶点的序号
	void InsertVertex(const int v);  // 插入一个顶点
	void InsertEdge(const int v1, const int v2, int weight);  // 插入一条边(v1, v2)，边权值为weight
	void DeleteVertex(const int v);  // 在图中删去顶点v 和所有与它相关联的边
	void DeleteEdge(const int v1, const int v2);  // 在图中删去边(v1, v2) 
};




//图的邻接表定义
template<typename T>
class Edge//边结点结构  邻接表为链接存储
{
public:
	friend class Graph_List<T>;
	int verAdj;//邻接顶点序号(该结点在顶点表中的位置)
	int cost;//边的权值
	Edge *next;//下一个边结点的指针
};


template<typename T>
class Vertex//顶点结构  顶点表为顺序存储
{
public:
	friend class Graph_List<T>;
	T verinfor;//顶点的名称 v0  1  A等
	Edge<T> *adjacent;//边链表的头指针
};

template<typename T>
class Graph_List//图的邻接表形式定义
{
private:
	Vertex<T> *vertices;//顶点表的头指针 
	int GraphSize;//顶点的个数
	//int *Visited;//访问标记数组

public:
	Graph_List();
	int GetFirstNeighbor(const int v);//返回序号为v的顶点的第一个邻接顶点的序号
	int GetNextNeighbor(const int v1, const int v2);
	/*求序号为v1的顶点的邻接表中序号为V2的下一个边结点的序号*/
	//int* ReturnVisited(){ return Visited; }
	void DepthFirstSearch(const int v,int *visited);//深度优先遍历 基本思想类似于树的先根遍历
	void DFS_Main();
	void BreadthFirstSearch(int v);//广度优先遍历 类似树的层次遍历
	void Insert(const int v1 , const int v2);//插入一个结点
	void InsertEdge(const int v1 , const int v2);//插入一条边
	void Delete(const int adj);//删除一个顶点
	bool DeleteEdge(const int v1, const int v2);//删除一条边
	int GetCost(const int v1 , const int v2);//返回指定边的权值
	int ReturnGraphSize() { return GraphSize; };
};
#endif