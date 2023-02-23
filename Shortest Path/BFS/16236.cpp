#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string.h>
using namespace std;

int N, curIdx1, curIdx2, g_iEat, g_iSize = 2, g_iTotal = 0;
int g_iArr[20][20];
bool g_bVisit[20][20];
vector<tuple<int, int, int>> v;		// 먹을 수 있는 물고기 위치들을 저장할 벡터

int x[4] = { -1, 0, 0, 1 };
int y[4] = { 0, -1, 1, 0 };

bool compare(tuple<int, int, int>& _a, tuple<int, int, int>& _b)
{
	int a1, a2, a3, b1, b2, b3;
	tie(a1, a2, a3) = _a;
	tie(b1, b2, b3) = _b;
	if (a3 == b3 && a1 == b1) return a2 < b2;		// 거리가 같고 높이도 같다면 왼쪽이 작은 순
	else if (a3 == b3) return a1 < b1;				// 거리만 같으면 높이가 낮은 순
	else return a3 < b3;							// 거리가 가까운 순
}

bool BFS()
{
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(curIdx1, curIdx2, 0));
	g_bVisit[curIdx1][curIdx2] = true;

	int index1, index2, iCnt;
	while (!q.empty())
	{
		tie(index1, index2, iCnt) = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int idx1 = index1 + x[i], idx2 = index2 + y[i];
			if (0 <= idx1 && 0 <= idx2 && N > idx1 && N > idx2)
			{
				if (!g_bVisit[idx1][idx2])
				{
					g_bVisit[idx1][idx2] = true;
					if (g_iArr[idx1][idx2] == 0 || g_iArr[idx1][idx2] == g_iSize)
					{
						q.push(make_tuple(idx1, idx2, iCnt + 1));
					}
					else if (0 < g_iArr[idx1][idx2] && g_iArr[idx1][idx2] < g_iSize)
					{
						v.push_back(make_tuple(idx1, idx2, iCnt + 1));
					}
				}
			}
		}
	}

	if (v.size() == 0)
		return false;
	else
	{
		sort(v.begin(), v.end(), compare);

		tie(curIdx1, curIdx2, iCnt) = v[0];
		g_iArr[curIdx1][curIdx2] = 0;
		g_iTotal += iCnt;
		++g_iEat;
		if (g_iSize < 7 && g_iEat == g_iSize)
		{
			g_iEat = 0;
			++g_iSize;
		}
		memset(g_bVisit, 0, sizeof(g_bVisit));
		v.clear();
		return true;
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> g_iArr[i][j];
			if (g_iArr[i][j] == 9)
			{
				curIdx1 = i, curIdx2 = j;
				g_iArr[i][j] = 0;
			}
		}
	}

	while (true)
	{
		if (!BFS()) break;
	}

	cout << g_iTotal;
	return 0;
}