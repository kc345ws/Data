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
	//int k;
	//int item;
	//int temp;
	int firstadj;
	int secondadj;
	int FirstNeighbor;
	cout << "1.����ͼ" << endl;
	cout << "2.ͼ��������ȱ���" << endl;
	cout << "3.ͼ�Ĺ�����ȱ���" << endl;
	cout << "4.����ָ���ߵ�Ȩֵ" << endl;
	cout << "5.���붥��" << endl;
	cout << "6.����һ����" << endl;
	cout << "7.ɾ��һ����" << endl;
	cout << "8.���Ҷ���ĵ�һ���߽��" << endl;
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
			cout << ":ͼ�Ĺ�ȶ����ȱ������" << endl;

			cout << endl;
			Menu();
			break;
		case 4:
			cout << "�������һ���������" << endl;
			
			cin >> firstadj;
			while (firstadj < 0 || firstadj >= GraphList->ReturnGraphSize())
			{
				cout << "����������ݳ�����Χ����������" << endl;
				cin >> firstadj;
			}
			cout << "������ڶ����������" << endl;
			
			cin >> secondadj;
			while (secondadj < 0 || secondadj >= GraphList->ReturnGraphSize())
			{
				cout << "����������ݳ�����Χ����������" << endl;
				cin >> secondadj;
			}
			cout << "�ñߵ�Ȩֵ" << endl;
			cout << GraphList->GetCost(firstadj, secondadj);
			cout << endl;
			Menu();
			break;

		case 5:
			cout << "������Ҫ����������" << endl;
			int insertedadj;
			cin >> insertedadj;
			cout << "������������Ȩֵ" << endl;
			int insertcost;
			cin >> insertcost;
			GraphList->Insert(insertedadj, insertcost);
			cout << "����ɹ�" << endl;
			cout << endl;
			Menu();
			break;

		case 6:
			cout << "�������һ����������" << endl;
			cin >> firstadj;
			while (firstadj < 0 || firstadj >= GraphList->ReturnGraphSize())
			{
				cout << "����������ݳ�����Χ����������" << endl;
				cin >> firstadj;
			}

			cout << "������ڶ�����������" << endl;
			cin >> secondadj;
			while (secondadj < 0 || secondadj >= GraphList->ReturnGraphSize())
			{
				cout << "����������ݳ�����Χ����������" << endl;
				cin >> secondadj;
			}

			GraphList->InsertEdge(firstadj, secondadj);
			cout << "����ɹ�" << endl;
			cout << endl;
			Menu();
			break;
		case 7:
			cout << "�������һ����������" << endl;
			cin >> firstadj;
			while (firstadj < 0 || firstadj >= GraphList->ReturnGraphSize())
			{
				cout << "����������ݳ�����Χ����������" << endl;
				cin >> firstadj;
			}

			cout << "������ڶ�����������" << endl;
			cin >> secondadj;
			while (secondadj < 0 || secondadj >= GraphList->ReturnGraphSize())
			{
				cout << "����������ݳ�����Χ����������" << endl;
				cin >> secondadj;
			}

			if (GraphList->DeleteEdge(firstadj, secondadj))
			{
				cout << "ɾ���ɹ�" << endl;
			}
			else
			{
				cout << "ɾ��ʧ��,�����������û�б�����" << endl;
			}

			cout << endl;
			Menu();
			break;

		case 8:
			cout << "������Ҫ���Ҷ�������" << endl;
			cin >> firstadj;
			while (firstadj < 0 || firstadj >= GraphList->ReturnGraphSize())
			{
				cout << "����������ݳ�����Χ����������" << endl;
				cin >> firstadj;
			}

			FirstNeighbor = GraphList->GetFirstNeighbor(firstadj);
			if (FirstNeighbor == -1)
			{
				cout << "�ö���û�б߽��" << endl;
			}
			else
			{
				//Vertex<char>*Temp = GraphList->ReturnVertex();
				cout << "�ö���ĵ�һ���߽��Ϊ" << endl;
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
	cout << "��������Ҫ�����Ķ������" << endl;
	cin >> GraphSize;
	vertices = new Vertex<T>[20];

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
			cout << "�������" << i << "������" << "����" << Adj << "������ߵ�Ȩֵ" << endl;
			int weight;
			cin >> weight;
			if (!vertices[i].adjacent)//����ǵ�һ���߽��������ֵ��adjacent
			{
				vertices[i].adjacent = new Edge<T>();
				vertices[i].adjacent->verAdj = Adj;
				vertices[i].adjacent->cost = weight;
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
				Temp->cost = weight;


				//����ͼ����
				Edge<T>*other = vertices[Adj].adjacent;
				while (1)
				{
					if (!vertices[Adj].adjacent)//�����һ������ڽӱ��ͷ���Ϊ��
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

template<typename T>//Ҫ���������� �������Ȩֵ
void Graph_List<T>::Insert(const int v1, const int v2)
{
	Edge<T> *TempEdge = vertices[v1].adjacent;//��ȡҪ�������ڽӱ��ͷ���
	GraphSize++;//���������һ

	cout << "�������" << GraphSize -1 << "�����������" << endl;
	cin >> vertices[GraphSize - 1].verinfor;
	vertices[GraphSize - 1].adjacent = nullptr;//�²�������ڽӱ�ͷ��㸳ֵΪ��

	if (!TempEdge)//���Ҫ��������ڽӱ�ͷ���Ϊ��
	{
		TempEdge = new Edge<T>();
		TempEdge->verAdj = GraphSize - 1;//Ҫ��������ڽӱ�ͷ�����Ÿ�ֵΪ�²������ڶ�����е����
		TempEdge->cost = v2;
		Edge<T>* newadjacent;
		newadjacent = vertices[GraphSize - 1].adjacent;
		newadjacent = new Edge<T>();
		newadjacent->verAdj = v1;//�²������ڽӱ��ͷ�����Ÿ�ֵΪҪ����������
		newadjacent->cost = v2;
	}
	else//���Ҫ��������ڽӱ�ͷ��㲻Ϊ��
	{
		while (TempEdge)//�ҵ��ڽӱ�����һ��Ϊ�յı߽��
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

template<typename T>//����һ����  ��һ���������� �ڶ�����������
void Graph_List<T>::InsertEdge(const int v1, const int v2)
{
	Edge<T>*Firstver;
	Edge<T>*Secondver;
	int Insertcost;
	if (!vertices[v1].adjacent)//�����һ��������ڽӱ�ͷ���Ϊ��
	{
		vertices[v1].adjacent = new Edge<T>();
		Firstver = vertices[v1].adjacent;
		cout << "���������ߵ�Ȩֵ" << endl;
		cin >> Insertcost;
		Firstver->cost = Insertcost;
		Firstver->verAdj = v2;
		Firstver->next = nullptr;

		if (!vertices[v2].adjacent)//����ڶ��������ڽӱ�ͷ���Ϊ��
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
			while (Secondver)//�ҵ��ڶ���������һ����Ϊ�յı߽��
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

	else//�����һ��������ڽӱ�ͷ��㲻Ϊ��
	{
		Firstver = vertices[v1].adjacent;

		while (Firstver)//�ҵ���һ���������һ����Ϊ�յı߽��
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

		if (!vertices[v2].adjacent)//����ڶ��������ڽӱ�ͷ���Ϊ��
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
			while (Secondver)//�ҵ��ڶ���������һ����Ϊ�յı߽��
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

template<typename T>//Ҫɾ���������
void Graph_List<T>::Delete(const int adj)
{
	
}

template<typename T>//ɾ��һ����
bool Graph_List<T>::DeleteEdge(const int v1, const int v2)
{
	Edge<T>*Firstver;
	Edge<T>*Secondver;
	if (!vertices[v1].adjacent || !vertices[v2].adjacent)//�����һ��ڶ��������ڽӱ�ͷ���Ϊ��
	{
		return false;
	}
	else
	{
		Firstver = vertices[v1].adjacent;
		bool flag = false;
		while (Firstver)//���ҵ�һ��������ڽӱ����Ƿ��еڶ�������
		{
			if (Firstver->verAdj == v2)
			{
				flag = !flag;
				if (Firstver == vertices[v1].adjacent)
				{
					delete Firstver;
					Firstver = nullptr;
					vertices[v1].adjacent = nullptr;//���ڽӱ�ͷ��㸳ֵΪ�շ�ֹ���Ұָ��
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
		if (!flag)//�����һ��������ڽӱ���û�еڶ�������
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


