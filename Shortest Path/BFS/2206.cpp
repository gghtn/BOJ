#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX 1e9

int N, M;
vector<string> vecGraph;
bool bVisit[2][1000][1000];
queue<tuple<int, int, int, bool>> myQueue; // 위치, 비용, 1을 지났는지
int x[4] = { 1, -1, 0, 0 };
int y[4] = { 0, 0, 1, -1 };

int BFS()
{
	int iMinCost = MAX;
	// 0인 부분만 지날 경우
	myQueue.push({ 0, 0, 1, false });
	bVisit[0][0][0] = true;

	int idx1, idx2, cost;
	bool bOne;
	while (!myQueue.empty())
	{
		tie(idx1, idx2, cost, bOne) = myQueue.front();
		myQueue.pop();
		if (idx1 == N - 1 && idx2 == M - 1) iMinCost = cost;

		for (int i = 0; i < 4; ++i)
		{
			int index1 = idx1 + x[i], index2 = idx2 + y[i];
			if (0 <= index1 && index1 < N && 0 <= index2 && index2 < M)
			{
				if (!bVisit[0][index1][index2] && vecGraph[index1][index2] == '0')
				{
					bVisit[0][index1][index2] = true;
					myQueue.push({ index1, index2, cost + 1, bOne });
				}
			}
		}
	}

	memset(bVisit, 0, sizeof(bVisit));

	// 1을 한 번 지날 경우
	myQueue.push({ 0,0,1,false });
	bVisit[0][0][0] = true;
	bVisit[1][0][0] = true;

	while (!myQueue.empty())
	{
		tie(idx1, idx2, cost, bOne) = myQueue.front();
		myQueue.pop();
		if (idx1 == N - 1 && idx2 == M - 1) iMinCost = min(iMinCost, cost);

		for (int i = 0; i < 4; ++i)
		{
			int index1 = idx1 + x[i], index2 = idx2 + y[i];
			if (0 <= index1 && index1 < N && 0 <= index2 && index2 < M)
			{
				// 이미 벽을 통과한 경우
				if (!bVisit[0][index1][index2] && bOne)
				{
					bVisit[0][index1][index2] = true;
					if (vecGraph[index1][index2] == '0')
					{
						myQueue.push({ index1, index2, cost + 1, bOne });
					}
				}
				// 벽을 통과하지 않은 경우
				else if (!bVisit[1][index1][index2] && !bOne)
				{
					bVisit[1][index1][index2] = true;

					if (vecGraph[index1][index2] == '1')
					{
						myQueue.push({ index1, index2, cost + 1, true });
					}
					else
					{
						myQueue.push({ index1, index2, cost + 1, bOne });
					}
				}
			}
		}
	}

	return iMinCost;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	vecGraph.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecGraph[i];
	}

	int iMin = BFS();

	if (iMin == MAX) cout << -1;
	else cout << iMin;

	return 0;
}