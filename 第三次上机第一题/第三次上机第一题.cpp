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
	//int k;
	//int item;
	//int temp;
	int firstadj;
	int secondadj;
	int FirstNeighbor;
	cout << "1.创建图" << endl;
	cout << "2.图的深度优先遍历" << endl;
	cout << "3.图的广度优先遍历" << endl;
	cout << "4.返回指定边的权值" << endl;
	cout << "5.插入顶点" << endl;
	cout << "6.插入一条边" << endl;
	cout << "7.删除一条边" << endl;
	cout << "8.查找顶点的第一个边结点" << endl;
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
			cout << ":图的广度度优先遍历结果" << endl;

			cout << endl;
			Menu();
			break;
		case 4:
			cout << "请输入第一个结点的序号" << endl;
			
			cin >> firstadj;
			while (firstadj < 0 || firstadj >= GraphList->ReturnGraphSize())
			{
				cout << "你输入的数据超出范围请重新输入" << endl;
				cin >> firstadj;
			}
			cout << "请输入第二个结点的序号" << endl;
			
			cin >> secondadj;
			while (secondadj < 0 || secondadj >= GraphList->ReturnGraphSize())
			{
				cout << "你输入的数据超出范围请重新输入" << endl;
				cin >> secondadj;
			}
			cout << "该边的权值" << endl;
			cout << GraphList->GetCost(firstadj, secondadj);
			cout << endl;
			Menu();
			break;

		case 5:
			cout << "请输入要插入结点的序号" << endl;
			int insertedadj;
			cin >> insertedadj;
			cout << "请输入插入结点的权值" << endl;
			int insertcost;
			cin >> insertcost;
			GraphList->Insert(insertedadj, insertcost);
			cout << "插入成功" << endl;
			cout << endl;
			Menu();
			break;

		case 6:
			cout << "请输入第一个顶点的序号" << endl;
			cin >> firstadj;
			while (firstadj < 0 || firstadj >= GraphList->ReturnGraphSize())
			{
				cout << "你输入的数据超出范围请重新输入" << endl;
				cin >> firstadj;
			}

			cout << "请输入第二个顶点的序号" << endl;
			cin >> secondadj;
			while (secondadj < 0 || secondadj >= GraphList->ReturnGraphSize())
			{
				cout << "你输入的数据超出范围请重新输入" << endl;
				cin >> secondadj;
			}

			GraphList->InsertEdge(firstadj, secondadj);
			cout << "插入成功" << endl;
			cout << endl;
			Menu();
			break;
		case 7:
			cout << "请输入第一个顶点的序号" << endl;
			cin >> firstadj;
			while (firstadj < 0 || firstadj >= GraphList->ReturnGraphSize())
			{
				cout << "你输入的数据超出范围请重新输入" << endl;
				cin >> firstadj;
			}

			cout << "请输入第二个顶点的序号" << endl;
			cin >> secondadj;
			while (secondadj < 0 || secondadj >= GraphList->ReturnGraphSize())
			{
				cout << "你输入的数据超出范围请重新输入" << endl;
				cin >> secondadj;
			}

			if (GraphList->DeleteEdge(firstadj, secondadj))
			{
				cout << "删除成功" << endl;
			}
			else
			{
				cout << "删除失败,这两个顶点间没有边相连" << endl;
			}

			cout << endl;
			Menu();
			break;

		case 8:
			cout << "请输入要查找顶点的序号" << endl;
			cin >> firstadj;
			while (firstadj < 0 || firstadj >= GraphList->ReturnGraphSize())
			{
				cout << "你输入的数据超出范围请重新输入" << endl;
				cin >> firstadj;
			}

			FirstNeighbor = GraphList->GetFirstNeighbor(firstadj);
			if (FirstNeighbor == -1)
			{
				cout << "该顶点没有边结点" << endl;
			}
			else
			{
				//Vertex<char>*Temp = GraphList->ReturnVertex();
				cout << "该顶点的第一个边结点为" << endl;
				cout << GraphList->ReturnVertex()[FirstNeighbor].verinfor << endl;			
			}
			
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
	vertices = new Vertex<T>[20];

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
			cout << "请输入第" << i << "个顶点" << "到第" << Adj << "个顶点边的权值" << endl;
			int weight;
			cin >> weight;
			if (!vertices[i].adjacent)//如果是第一个边结点则将它赋值给adjacent
			{
				vertices[i].adjacent = new Edge<T>();
				vertices[i].adjacent->verAdj = Adj;
				vertices[i].adjacent->cost = weight;
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
						
						vertices[Adj].adjacent->cost = weight;
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
				Temp->cost = weight;


				//无向图部分
				Edge<T>*other = vertices[Adj].adjacent;
				while (1)
				{
					if (!vertices[Adj].adjacent)//如果另一个结点邻接表的头结点为空
					{
						vertices[Adj].adjacent = new Edge<T>();
						vertices[Adj].adjacent->verAdj = i;
						//vertices[Adj].adjacent->next = nullptr;

						vertices[Adj].adjacent->cost = weight;
						break;
					}
					else
					{
						if (!other->next)
						{
							other->next = new Edge<T>();
							other->verAdj = i;

							other->cost = weight;
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

template<typename T>//要插入结点的序号 插入结点的权值
void Graph_List<T>::Insert(const int v1, const int v2)
{
	Edge<T> *TempEdge = vertices[v1].adjacent;//获取要插入结点邻接表的头结点
	GraphSize++;//结点数量加一

	cout << "请输入第" << GraphSize -1 << "个顶点的名称" << endl;
	cin >> vertices[GraphSize - 1].verinfor;
	vertices[GraphSize - 1].adjacent = nullptr;//新插入结点的邻接表头结点赋值为空

	if (!TempEdge)//如果要插入结点的邻接表头结点为空
	{
		TempEdge = new Edge<T>();
		TempEdge->verAdj = GraphSize - 1;//要插入结点的邻接表头结点序号赋值为新插入结点在顶点表中的序号
		TempEdge->cost = v2;
		Edge<T>* newadjacent;
		newadjacent = vertices[GraphSize - 1].adjacent;
		newadjacent = new Edge<T>();
		newadjacent->verAdj = v1;//新插入结点邻接表的头结点序号赋值为要插入结点的序号
		newadjacent->cost = v2;
	}
	else//如果要插入结点的邻接表头结点不为空
	{
		while (TempEdge)//找到邻接表中下一个为空的边结点
		{
			if (!TempEdge->next)
			{
				TempEdge->next = new Edge<T>();
				TempEdge->next->cost = v2;
				TempEdge->next->verAdj = GraphSize - 1;


				Edge<T>* newadjacent;
				vertices[GraphSize - 1].adjacent = new Edge<T>();
				newadjacent = vertices[GraphSize - 1].adjacent;
				newadjacent->verAdj = v1;
				newadjacent->cost = v2;
				newadjacent->next = nullptr;
				break;
			}
			TempEdge = TempEdge->next;
		}
	}
}

template<typename T>//插入一条边  第一个顶点的序号 第二个顶点的序号
void Graph_List<T>::InsertEdge(const int v1, const int v2)
{
	Edge<T>*Firstver;
	Edge<T>*Secondver;
	int Insertcost;
	if (!vertices[v1].adjacent)//如果第一个顶点的邻接表头结点为空
	{
		vertices[v1].adjacent = new Edge<T>();
		Firstver = vertices[v1].adjacent;
		cout << "请输入插入边的权值" << endl;
		cin >> Insertcost;
		Firstver->cost = Insertcost;
		Firstver->verAdj = v2;
		Firstver->next = nullptr;

		if (!vertices[v2].adjacent)//如果第二个顶点邻接表头结点为空
		{
			vertices[v2].adjacent = new Edge<T>();
			Secondver = vertices[v2].adjacent;
			Secondver->cost = Insertcost;
			Secondver->verAdj = v1;
			Secondver->next = nullptr;
		}
		else
		{
			Secondver = vertices[v2].adjacent;
			while (Secondver)//找到第二个结点最后一个不为空的边结点
			{
				if (!Secondver->next)
				{
					Secondver->next = new Edge<T>();
					Secondver->next->cost = Insertcost;
					Secondver->next->verAdj = v1;
					Secondver->next = nullptr;
					break;
				}
				Secondver = Secondver->next;
			}
		}
	}

	else//如果第一个顶点的邻接表头结点不为空
	{
		Firstver = vertices[v1].adjacent;

		while (Firstver)//找到第一个顶点最后一个不为空的边结点
		{
			if (!Firstver->next)
			{
				Firstver->next = new Edge<T>();
				Firstver->cost = Insertcost;
				Firstver->verAdj = v2;
				Firstver->next = nullptr;
				break;
			}
			Firstver = Firstver->next;
		}

		if (!vertices[v2].adjacent)//如果第二个顶点邻接表头结点为空
		{
			vertices[v2].adjacent = new Edge<T>();
			Secondver = vertices[v2].adjacent;
			Secondver->cost = Insertcost;
			Secondver->verAdj = v1;
			Secondver->next = nullptr;
		}
		else
		{
			Secondver = vertices[v2].adjacent;
			while (Secondver)//找到第二个结点最后一个不为空的边结点
			{
				if (!Secondver->next)
				{
					Secondver->next = new Edge<T>();
					Secondver->next->cost = Insertcost;
					Secondver->next->verAdj = v1;
					Secondver->next = nullptr;
					break;
				}
				Secondver = Secondver->next;
			}
		}
	}
	
}

template<typename T>
int Graph_List<T>::GetCost(const int v1, const int v2)
{
	Edge<T> *TempEdge = vertices[v1].adjacent;
	while (TempEdge)
	{
		if (v2 == TempEdge->verAdj)
		{
			return TempEdge->cost;
		}
		TempEdge = TempEdge->next;
	}
	return 0;
}

template<typename T>//要删除结点的序号
void Graph_List<T>::Delete(const int adj)
{
	
}

template<typename T>//删除一条边
bool Graph_List<T>::DeleteEdge(const int v1, const int v2)
{
	Edge<T>*Firstver;
	Edge<T>*Secondver;
	if (!vertices[v1].adjacent || !vertices[v2].adjacent)//如果第一或第二个顶点邻接表头结点为空
	{
		return false;
	}
	else
	{
		Firstver = vertices[v1].adjacent;
		bool flag = false;
		while (Firstver)//查找第一个顶点的邻接表中是否有第二个顶点
		{
			if (Firstver->verAdj == v2)
			{
				flag = !flag;
				if (Firstver == vertices[v1].adjacent)
				{
					delete Firstver;
					Firstver = nullptr;
					vertices[v1].adjacent = nullptr;//将邻接表头结点赋值为空防止变成野指针
				}
				else
				{
					delete Firstver;
					Firstver = nullptr;
				}
				break;
			}
			Firstver = Firstver->next;
		}
		if (!flag)//如果第一个顶点的邻接表中没有第二个顶点
		{
			return false;
		}

		Secondver = vertices[v2].adjacent;
		while (Secondver)
		{
			if (Secondver->verAdj == v1)
			{
				if (Firstver == vertices[v1].adjacent)
				{
					delete Secondver;
					Secondver = nullptr;
					vertices[v2].adjacent = nullptr;
				}
				else
				{
					delete Secondver;
					Secondver = nullptr;
				}
				break;
			}
			Secondver = Secondver->next;
		}
		return true;
	}
}


