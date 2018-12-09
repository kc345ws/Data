#include"�������ϻ���һ��.h"
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
	cout << "1.����ͼ" << endl;
	cout << "2.ͼ��������ȱ���" << endl;
	cout << "3.ͼ�Ĺ�����ȱ���" << endl;
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
			GraphList = new Graph_List<char>();
			
			cout << endl;
			Menu();
			break;
		case 2:
			//5 A B C D E
			//1 -1 2 3 -1 -1 4 -1 -1
			/*cout << "�����뿪ʼ�����������" << endl;
			int startadj;
			cin >> startadj;*/
			
			//GraphList->DepthFirstSearch(startadj, GraphList->ReturnVisited());
			GraphList->DFS_Main();
			cout << ":ͼ��������ȱ������" << endl;
			cout << endl;
			Menu();
			break;
		case 3:
			cout << "�����뿪ʼ�����������" << endl;
			int startadj;
			cin >> startadj;
			GraphList->BreadthFirstSearch(startadj);
			cout << ":ͼ��������ȱ������" << endl;

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
	cout << "��������Ҫ�����Ķ������" << endl;
	cin >> GraphSize;
	vertices = new Vertex<T>[GraphSize];

	for (int i = 0; i < GraphSize; i++)
	{
		cout << "�������" << i << "�����������" << endl;
		cin >> vertices[i].verinfor;
		vertices[i].adjacent = nullptr;
	}

	for (int i = 0; i < GraphSize; i++)
	{
		int temp = 0;
		Edge<T>*Temp = nullptr;
		
		while (1)
		{		
			
			cout << "�������" << i << "������" << "��" << temp << "���߽������(-1����)" << endl;
			int Adj;
			cin >> Adj;
			while (1)
			{
				if (Adj >= GraphSize||Adj<-1)
				{
					cout << "���������ų�����Χ����������" << endl;
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
			/*cout << "�������" << i + 1 << "������" << "��" << temp + 1 << "���߽���Ȩֵ" << endl;
			int weight;
			cin >> weight;*/
			if (!vertices[i].adjacent)//����ǵ�һ���߽��������ֵ��adjacent
			{
				vertices[i].adjacent = new Edge<T>();
				vertices[i].adjacent->verAdj = Adj;
				//vertices[i].adjacent->cost = weight;
				Temp = vertices[i].adjacent;


				//����ͼ����
				Edge<T>*other = vertices[Adj].adjacent;
				while (1)
				{
					if (!vertices[Adj].adjacent)//�����һ������ڽӱ��ͷ���Ϊ��
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
				while (1)//�ҵ����һ���ǿձ߽��
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


				//����ͼ����
				Edge<T>*other = vertices[Adj].adjacent;
				while (1)
				{
					if (!vertices[Adj].adjacent)//�����һ������ڽӱ��ͷ���Ϊ��
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
	//�����Ϊv�Ķ���ĵ�һ���ڽӶ�������
	if (v != -1)
	{
		Edge<T>* Temp = vertices[v].adjacent;//��ֵָ����Ŷ����ڽӶ����ͷ���
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
	//�����Ϊv1�Ķ�����ڽӱ������ΪV2����һ���߽������
	if (v1 == -1 || v2 == -1)
	{
		return -1;
	}


	Edge<T>* Temp = vertices[v1].adjacent;
	while (Temp)
	{
		if (Temp->verAdj == v2)//����ҵ����Ϊv2�Ľ��������
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
void Graph_List<T>::DepthFirstSearch(const int v, int *visited)//�״η��ʵĽ����� ���ʱ������
{
	cout << vertices[v].verinfor<<" ";
	visited[v] = 1;

	Edge<T> *Temp = vertices[v].adjacent;
	while (Temp != nullptr)
	{
		if (visited[Temp->verAdj] != 1)//������û�б����ʹ�
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
		cout << "������Ҫ��ʼ�����������" << endl;
		int temp;
		cin >> temp;
		while (1)
		{
			if (temp >= GraphSize || temp<=-1)
			{
				cout << "���������ų�����Χ����������" << endl;
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


