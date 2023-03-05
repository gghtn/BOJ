#include <iostream>
#include <vector>
using namespace std;

//const int INF = 123456789;

struct tEdge
{
	int from, to, cost;
};

bool Bellman_Ford(vector<tEdge>& v, int N)
{
	vector<int> vecDist(N + 1);
	vecDist[1] = 0;						// 시작점 갱신

	for (int i = 0; i < N; ++i)
	{
		for (auto& edge : v)
		{
			int fr = edge.from, to = edge.to, cost = edge.cost;
			// fr정점까지 최소 비용 + fr->to까지의 비용이 to정점까지의 최소비용보다 더 작다면 갱신
			// 원래 벨만 포드는 출발점이 특정한 한 점일 때 가능한 알고리즘이다.
			// 이 문제는 특정한 시작점을 제시하지 않았으므로 전체 정점에 대해 알고리즘을 수행해야 한다.
			// 하지만 이 경우 시간 초과의 가능성이 높다. 단, 이 문제의 요구는 음수 사이클의 존재 여부이므로
			// vecDist[fr] != INF 즉, 갱신된 적 있는지 확인할 필요가 없다.
			if (vecDist[fr] + cost < vecDist[to])
				vecDist[to] = vecDist[fr] + cost;
		}
	}

	// 음수 사이클이 존재하는지 여부
	for (auto& edge : v)
	{
		int fr = edge.from, to = edge.to, cost = edge.cost;
		// 비용이 갱신된다면 음수 사이클 존재
		if (vecDist[fr] + cost < vecDist[to])
			return true;
	}
	return false;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int TC;
	cin >> TC;
	vector<tEdge> vecGraph;
	while (TC--)
	{
		int N, M, W;
		int S, E, T;
		cin >> N >> M >> W;
		vecGraph = vector<tEdge>(M * 2 + W);
		for (int i = 0; i < M; ++i)
		{
			cin >> S >> E >> T;
			vecGraph[i] = { S, E, T };
			vecGraph[i + M] = { E, S, T };
		}
		for (int i = M * 2; i < M * 2 + W; ++i)
		{
			cin >> S >> E >> T;
			vecGraph[i] = { S, E, -T };
		}

		if (Bellman_Ford(vecGraph, N)) cout << "YES\n";
		else cout << "NO\n";
	}
}