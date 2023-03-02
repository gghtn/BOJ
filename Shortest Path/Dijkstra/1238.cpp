#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1000000;

int N, M, X;
vector<pair<int, int>> vecArr[2][1001];
vector<int> vecCost[2];

// 단일 지점에서 다른 모든 지점까지의 최단 경로
void Dijkstra(int _idx)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;		// 비용 ,현재 인덱스
	bool bVisit[1001] = { 0 };
	pq.push({ 0, X });
	vecCost[_idx][X] = 0;

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (bVisit[cur]) continue;
		bVisit[cur] = true;

		int iSize = vecArr[_idx][cur].size();
		for (int i = 0; i < iSize; ++i)
		{
			int iGoal = vecArr[_idx][cur][i].second; // 벡터에 저장된 현재 정점과 이어진 정점의 인덱스

			vecCost[_idx][iGoal] = min(vecCost[_idx][iGoal], vecCost[_idx][cur] + vecArr[_idx][cur][i].first);
			pq.push({ vecCost[_idx][iGoal], iGoal });
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> X;

	vecCost[0].resize(N + 1, INF);
	vecCost[1].resize(N + 1, INF);

	int fr, to, cost;
	for (int i = 0; i < M; ++i)
	{
		cin >> fr >> to >> cost;
		vecArr[0][fr].push_back({ cost, to });
		vecArr[1][to].push_back({ cost, fr });			// 역방향 그래프 (가고 오고 2가지이므로)
	}

	Dijkstra(0);
	Dijkstra(1);

	int iMax = 0;
	for (int i = 1; i <= N; ++i)
	{
		iMax = max(iMax, vecCost[0][i] + vecCost[1][i]);
	}

	cout << iMax;
}