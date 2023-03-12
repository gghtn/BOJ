#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

vector<pair<int, int>> vecGraph[1001];
vector<int> vecDist;

void Dijkstra(int _start)
{
	priority_queue<pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>> pq;
	pq.push({ 0, _start });
	vecDist[_start] = 0;

	while (!pq.empty())
	{
		int iCost = pq.top().first;
		int iCur = pq.top().second;
		pq.pop();

		if (vecDist[iCur] < iCost) continue;

		int iSize = vecGraph[iCur].size();
		for (int i = 0; i < iSize; ++i)
		{
			int iGoal = vecGraph[iCur][i].second;
			int iDist = vecDist[iCur] + vecGraph[iCur][i].first;

			if (vecDist[iGoal] > iDist)
			{
				vecDist[iGoal] = iDist;
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

	int N, M;
	int fr, to, cost;
	int start, goal;
	cin >> N;
	cin >> M;
	vecDist.resize(N + 1, INF);


	for (int i = 0; i < M; ++i)
	{
		cin >> fr >> to >> cost;
		vecGraph[fr].push_back({ cost, to });
	}

	cin >> start >> goal;
	Dijkstra(start);
	cout << vecDist[goal];

	return 0;
}