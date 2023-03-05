#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

const long long INF = LLONG_MAX;

vector<long long> vecDist;

struct tEdge
{
	int from, to, cost;
};

bool Bellman_Ford(vector<tEdge>& v, int N)
{
	vecDist[1] = 0;	// 시작점 갱신

	for (int i = 0; i < N; ++i)		// N - 1번 수행
	{
		for (const auto& edge : v)
		{
			// 현재 정점(from)이 갱신된 적이 있으면서(INF가 아니면서) 현재 정점까지 최소비용 + from->to 비용이 목적지 정점(to)의 최소비용보다 작으면 갱신
			if (vecDist[edge.from] != INF && vecDist[edge.from] + edge.cost < vecDist[edge.to])
			{
				vecDist[edge.to] = vecDist[edge.from] + edge.cost;
			}
		}
	}

	// 음수 사이클 존재 여부 확인
	for (const auto& edge : v)
	{
		// 갱신 된다면 음수 사이클이 존재
		if (vecDist[edge.from] != INF && vecDist[edge.from] + edge.cost < vecDist[edge.to])
		{
			return true;
		}
	}

	return false;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	int A, B, C;
	cin >> N >> M;

	vector<tEdge> vecGraph(M);
	vecDist.resize(N + 1, INF);

	for (int i = 0; i < M; ++i)
	{
		cin >> A >> B >> C;
		vecGraph[i] = { A, B, C };
	}

	if (Bellman_Ford(vecGraph, N)) cout << -1;
	else
	{
		for (int i = 2; i <= N; ++i)
		{
			if (vecDist[i] == INF) cout << "-1\n";
			else cout << vecDist[i] << '\n';
		}
	}

	return 0;
}