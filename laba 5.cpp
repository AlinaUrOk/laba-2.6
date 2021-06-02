#include <iostream>
#include <vector>
//відстань між двома найбільш віддаленими вершинами
using namespace std;

int graph[100][100];
int used[100];
int flag;

void BuildMatrix(int v, int e)
{
	for (int i = 0; i < v; i++)
	{
		for (int k = 0; k < v; k++)
		{
			graph[i][k] = 0;
			graph[k][i] = 0;
		}
	}
	int fe, se;
	cout << "Enter edges: ";
	while (e != 0)
	{
		cin >> fe >> se;
		graph[fe][se] = 1;
		//graph[se][fe] = 1;
		e = e - 1;
	}
}

void PrintMatrix(int v)
{
	for (int i = 1; i <= v; i++)
	{
		for (int k = 1; k <= v; k++)
		{
			cout << graph[i][k] << " ";
		}
		cout << endl;
	}
}

//void dfs(int v)
//{
//	if (flag == 1)return;
//	else
//	{
//		used[v] = 1;
//		int c = 1;
//		for (int i = 0; i < sizeof(graph[v]); i++)
//		{
//			int to = graph[v][i];
//			{
//				if (used[to] == 1)
//				{
//					c = 1;
//					flag = 1;
//					return;
//				}
//				else
//				{
//					dfs(to);
//				}
//				if (flag == 1)return;
//			}
//			used[v] = 2;
//		}
//	}
//}
//
//	void checkNodes(int v)
//	{
//		for (int i = 1; i <= v; i++)
//		{
//			if (used[i] == 0)
//			{
//				dfs(i);
//				if (flag == 1) return;
//			}
//		}
//	}
	//void traverse(int u, bool visited[],int v) {
	//	visited[u] = true; 
	//	for (int k = 0; k < v; k++) {
	//		if (graph[u][k]) {
	//			if (!visited[k])
	//				traverse(k, visited, v);
	//		}
	//	}
	//}
	//
	//bool IsConnected(int v)
	//{
	//	bool* m = new bool[v];
	//	for (int i = 0; i <= v; i++)
	//	{
	//		for (int k = 0; k < v; k++)
	//		{
	//			m[k] = false;
	//			traverse(i, m, v);
	//		}
	//
	//		for (int k = 0; k < v; k++)
	//		{
	//			if (!m[k]) return false;
	//		}
	//	}
	//}

void FloydWarshall(int v, int e)
{
	int d = 0;
	for (int k = 1; k <= v; ++k)
	{
		for (int i = 1; i <= v; ++i)
		{
			if (graph[i][k] != 0)
			{
				for (int j = 1; j <= v; ++j)
				{
					if (graph[k][j] != 0 && (graph[i][j] == 0 || graph[i][k] + graph[k][j] < graph[i][j])) {
						graph[i][j] = graph[i][k] + graph[k][j];
					}
				}
			}
		}
	}

	for (int i = 1; i <= v; ++i)
	{
		for (int j = 1; j <= v; ++j)
		{
			if (d < graph[i][j])
			{
				d = graph[i][j];
			}
		}
	}
	cout << d;
}

int main()
{
	int vertic, edge;
	cout << "Enter number of vertices: ";
	cin >> vertic;
	cout << "Enter number of edges: ";
	cin >> edge;
	BuildMatrix(vertic, edge);
	PrintMatrix(vertic);
	FloydWarshall(vertic, edge);
	return 0;
}


