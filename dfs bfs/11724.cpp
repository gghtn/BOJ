#include <iostream>
#include <queue>
#include <stack>

// 인접행렬 방식의 DFS, BFS
using namespace std;

queue<int> q;
stack<int> st;
int		graph[1001][1001];
bool	visit[1001];

void BFS(int num, int N)
{
	int temp = 0;
	q.push(num);
	while (!q.empty())
	{
		temp = q.front();
		q.pop();

		for (int i = 1; i <= N; i++)
		{
			if (!visit[i] && graph[temp][i])
			{
				visit[i] = true;
				q.push(i);
			}
		}
	}
}

void StackDFS(int num, int N)
{
	int temp = 0;
	st.push(num);

	while (!st.empty())
	{
		temp = st.top();
		st.pop();

		for (int i = 1; i <= N; i++)
		{
			if (!visit[i] && graph[temp][i])
			{
				visit[i] = true;
				st.push(i);
			}
		}
	}

}

void RecursionDFS(int num, int N)
{
	for (int i = 1; i <= N; i++)
	{
		if (!visit[i] && graph[num][i])
		{
			visit[i] = true;
			RecursionDFS(i, N);
		}
	}
}

int main()
{
	int N, M, u, v, total = 0;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		graph[u][v] = graph[v][u] = 1;
	}

	/*for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			BFS(i, N);
			total++;
		}
	}*/
	/*for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			RecursionDFS(i, N);
			total++;
		}
	}*/
	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			StackDFS(i, N);
			total++;
		}
	}

	cout << total;
	return 0;
}
