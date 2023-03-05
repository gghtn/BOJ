#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define prii	pair<int, int>

const int INF = 123456789;

int V, E, K;
vector<pair<int, int>> graph[20001];
vector<int> vecDist;

void Dijkstra(int _start)
{
	priority_queue<prii, vector<prii>, greater<prii>> pq;
	//bool bVisit[20001] = {};
	pq.push({ 0, _start });
	vecDist[_start] = 0;

	while (!pq.empty())
	{
		int curIdx = pq.top().second;
		pq.pop();

		int iSize = graph[curIdx].size();
		for (int i = 0; i < iSize; ++i)
		{
			int iGoal = graph[curIdx][i].second;
			if (vecDist[iGoal] > vecDist[curIdx] + graph[curIdx][i].first)
			{
				vecDist[iGoal] = vecDist[curIdx] + graph[curIdx][i].first;
				pq.push({ vecDist[iGoal], iGoal });
			}
		}
	}

}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> V >> E;
	cin >> K;
	vecDist.resize(V + 1, INF);

	int u, v, w;
	for (int i = 0; i < E; ++i)
	{
		cin >> u >> v >> w;
		graph[u].push_back({ w, v });  // 시작 u, 목적지 v, u->v로의 비용 w 저장
	}

	Dijkstra(K);

	for (int i = 0; i < V; ++i)
	{
		if (vecDist[i + 1] == INF) cout << "INF\n";
		else cout << vecDist[i + 1] << '\n';
	}

	return 0;
}