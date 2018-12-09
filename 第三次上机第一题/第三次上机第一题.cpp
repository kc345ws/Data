#include"第三次上机第一题.h"
#include<iostream>
#include<queue>
using namespace std;
Graph_List<char>*GraphList;
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
	cout << "1.创建图" << endl;
	cout << "2.图的深度优先遍历" << endl;
	cout << "3.图的广度优先遍历" << endl;
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
			GraphList = new Graph_List<char>();
			
			cout << endl;
			Menu();
			break;
		case 2:
			//5 A B C D E
			//1 -1 2 3 -1 -1 4 -1 -1
			/*cout << "请输入开始遍历结点的序号" << endl;
			int startadj;
			cin >> startadj;*/
			
			//GraphList->DepthFirstSearch(startadj, GraphList->ReturnVisited());
			GraphList->DFS_Main();
			cout << ":图的深度优先遍历结果" << endl;
			cout << endl;
			Menu();
			break;
		case 3:
			cout << "请输入开始遍历结点的序号" << endl;
			int startadj;
			cin >> startadj;
			GraphList->BreadthFirstSearch(startadj);
			cout << ":图的深度优先遍历结果" << endl;

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

template<typename T>
Graph_List<T>::Graph_List()
{
	cout << "请输入你要创建的顶点个数" << endl;
	cin >> GraphSize;
	vertices = new Vertex<T>[GraphSize];

	for (int i = 0; i < GraphSize; i++)
	{
		cout << "请输入第" << i << "个顶点的名称" << endl;
		cin >> vertices[i].verinfor;
		vertices[i].adjacent = nullptr;
	}

	for (int i = 0; i < GraphSize; i++)
	{
		int temp = 0;
		Edge<T>*Temp = nullptr;
		
		while (1)
		{		
			
			cout << "请输入第" << i << "个顶点" << "第" << temp << "个边结点的序号(-1结束)" << endl;
			int Adj;
			cin >> Adj;
			while (1)
			{
				if (Adj >= GraphSize||Adj<-1)
				{
					cout << "你输入的序号超出范围请重新输入" << endl;
					cin >> Adj;
				}
				else
				{
					break;
				}
			}
			if (Adj == -1)
			{
				break;
			}
			/*cout << "请输入第" << i + 1 << "个顶点" << "第" << temp + 1 << "个边结点的权值" << endl;
			int weight;
			cin >> weight;*/
			if (!vertices[i].adjacent)//如果是第一个边结点则将它赋值给adjacent
			{
				vertices[i].adjacent = new Edge<T>();
				vertices[i].adjacent->verAdj = Adj;
				//vertices[i].adjacent->cost = weight;
				Temp = vertices[i].adjacent;


				//无向图部分
				Edge<T>*other = vertices[Adj].adjacent;
				while (1)
				{
					if (!vertices[Adj].adjacent)//如果另一个结点邻接表的头结点为空
					{
						vertices[Adj].adjacent = new Edge<T>();
						vertices[Adj].adjacent->verAdj = i;
						//vertices[Adj].adjacent->next = nullptr;
						break;
					}
					else
					{
						if (!other->next)
						{
							other->next = new Edge<T>();
							other->verAdj = i;
							break;
						}
						other = other->next;
					}
				}
			}
			else
			{
				Temp = vertices[i].adjacent;
				while (1)//找到最后一个非空边结点
				{
					if (!Temp->next)
					{
						break;
					}
					else
					{
						Temp = Temp->next;
					}
				}
				Temp->next = new Edge<T>();
				Temp = Temp->next;
				Temp->verAdj = Adj;
				//Temp->cost = weight;


				//无向图部分
				Edge<T>*other = vertices[Adj].adjacent;
				while (1)
				{
					if (!vertices[Adj].adjacent)//如果另一个结点邻接表的头结点为空
					{
						vertices[Adj].adjacent = new Edge<T>();
						vertices[Adj].adjacent->verAdj = i;
						//vertices[Adj].adjacent->next = nullptr;
						break;
					}
					else
					{
						if (!other->next)
						{
							other->next = new Edge<T>();
							other->verAdj = i;
							break;
						}
						other = other->next;
					}
				}
			}
			temp++;
		}
	}

	
}

template<typename T>
inline int Graph_List<T>::GetFirstNeighbor(const int v)
{
	//求序号为v的顶点的第一个邻接顶点的序号
	if (v != -1)
	{
		Edge<T>* Temp = vertices[v].adjacent;//赋值指定序号顶点邻接顶点的头结点
		if (Temp)
		{
			return Temp->verAdj;
		}
	}
	else
	{
		return -1;
	}
}

template<typename T>
int Graph_List<T>::GetNextNeighbor(const int v1, const int v2)
{
	//求序号为v1的顶点的邻接表中序号为V2的下一个边结点的序号
	if (v1 == -1 || v2 == -1)
	{
		return -1;
	}


	Edge<T>* Temp = vertices[v1].adjacent;
	while (Temp)
	{
		if (Temp->verAdj == v2)//如果找到序号为v2的结点则跳出
		{
			break;
		}
		Temp = Temp->next;
	}

	if (!Temp || !Temp->next)
	{
		return -1;
	}
	else
	{
		return Temp->verAdj;
	}	
}

template<typename T>
void Graph_List<T>::DepthFirstSearch(const int v, int *visited)//首次访问的结点序号 访问标记数组
{
	cout << vertices[v].verinfor<<" ";
	visited[v] = 1;

	Edge<T> *Temp = vertices[v].adjacent;
	while (Temp != nullptr)
	{
		if (visited[Temp->verAdj] != 1)//如果结点没有被访问过
		{
			DepthFirstSearch(Temp->verAdj, visited);
		}
		Temp = Temp->next;
	}
	// 3 A B C 1 -1 2 -1 -1
}

template<typename T>
void Graph_List<T>::DFS_Main()
{
	if (GraphSize)
	{
		int *Visited = new int[GraphSize];
		for (int i = 0; i < GraphSize; i++)
		{
			Visited[i] = 0;
		}
		cout << "请输入要开始遍历结点的序号" << endl;
		int temp;
		cin >> temp;
		while (1)
		{
			if (temp >= GraphSize || temp<=-1)
			{
				cout << "你输入的序号超出范围请重新输入" << endl;
				cin >> temp;
			}
			else
			{
				break;
			}
		}
		DepthFirstSearch(temp, Visited);
	}
}


template<typename T>
void Graph_List<T>::BreadthFirstSearch(int v)
{
	queue<Vertex<T>>Queue;
	int *visited = new int[GraphSize];
	for (int i = 0; i < GraphSize; i++)
	{
		visited[i] = 0;
	}
	cout << vertices[v].verinfor << " ";
	visited[v] = 1;
	Queue.push(vertices[v]);

	while (!Queue.empty())
	{
		Vertex<T>TempVertex = Queue.front();
		Queue.pop();
		Edge<T> *TempEdge = TempVertex.adjacent;
		while (TempEdge)
		{
			if (visited[TempEdge->verAdj] == 0)
			{
				//cout << TempVertex.verinfor << " ";
				cout << vertices[TempEdge->verAdj].verinfor << " ";
				visited[TempEdge->verAdj] = 1;
				Queue.push(vertices[TempEdge->verAdj]);
			}
			TempEdge = TempEdge->next;
		}
		
	}
}


