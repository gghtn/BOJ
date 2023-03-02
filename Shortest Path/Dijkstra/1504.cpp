#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 123456789;

int N, E;
vector<pair<int, int>> vecGraph[801];		// �� �������� �ٸ� ���������� ���� �ε����� ������ ���� �迭
vector<int> vecDist[3];						// � �� �������� ��� ���������� �ִܰŸ��� ������ ���� �迭(3���� ���������� �ִܰŸ��� ���ϸ� �ǹǷ� 3�� ����)

void Dijkstra(int _start, int _idx)
{
	bool bVisit[801] = {};
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, _start });
	vecDist[_idx][_start] = 0;				// ���� �������� ���� ���������� ��� 0

	while (!pq.empty())
	{
		//int iCost = pq.top().first;
		int iCur = pq.top().second;
		pq.pop();

		if (bVisit[iCur]) continue;
		bVisit[iCur] = true;

		int iSize = vecGraph[iCur].size();
		for (int i = 0; i < iSize; ++i)
		{
			int iNext = vecGraph[iCur][i].second;

			if (vecDist[_idx][iNext] > vecDist[_idx][iCur] + vecGraph[iCur][i].first)
			{
				vecDist[_idx][iNext] = vecDist[_idx][iCur] + vecGraph[iCur][i].first;
				pq.push({ vecDist[_idx][iNext], iNext });
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c, v1, v2;

	cin >> N >> E;
	for (int i = 0; i < E; ++i)
	{
		cin >> a >> b >> c;
		vecGraph[a].push_back({ c, b });		// ������ �׷���
		vecGraph[b].push_back({ c, a });
	}
	cin >> v1 >> v2;

	vecDist[0].resize(N + 1, INF);				// �ִܰŸ� ���� �ʱ�ȭ
	vecDist[1].resize(N + 1, INF);
	vecDist[2].resize(N + 1, INF);

	Dijkstra(1, 0);
	Dijkstra(v1, 1);
	Dijkstra(v2, 2);


	int iRoute1 = vecDist[0][v1] + vecDist[1][v2] + vecDist[2][N];
	int iRoute2 = vecDist[0][v2] + vecDist[2][v1] + vecDist[1][N];

	if (iRoute1 >= INF && iRoute2 >= INF)
	{
		cout << -1;
		return 0;
	}
	cout << min(iRoute1, iRoute2);

	return 0;
}