#include <iostream>
using namespace std;

int graphVec[101][101];
bool visit[101];

int DFS(int num, int N)
{
	static int result = 0;

	for (int i = 1; i <= N; i++)
	{
		if (!visit[i] && graphVec[num][i])
		{
			++result;
			visit[i] = true;
			DFS(i, N);
		}
	}

	return result;
}

int main()
{
	int N, E, u, v;
	cin >> N >> E;

	for (int i = 0; i < E; ++i)
	{
		cin >> u >> v;
		graphVec[u][v] = graphVec[v][u] = 1;
	}

	visit[1] = true;
	cout << DFS(1, N);

	return 0;
}