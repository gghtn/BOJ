#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N, M, g_min = 100;
vector<vector<int>> vArr;
vector<pair<int, int>> vNumTwo;
queue<tuple<int, int, int>> q;

int idxArr1[4] = { 1, -1, 0, 0 };
int idxArr2[4] = { 0, 0, 1, -1 };

int BFS(vector<vector<int>> _v)
{
	int idx1, idx2, iCount, iTemp = 0;
	while (!q.empty())
	{
		tie(idx1, idx2, iCount) = q.front();
		q.pop();
		if (iCount == iTemp) iTemp++;

		for (int i = 0; i < 4; ++i)
		{
			int index1 = idx1 + idxArr1[i], index2 = idx2 + idxArr2[i];
			if (0 <= index1 && index1 < N && 0 <= index2 && index2 < N)
			{
				if (_v[index1][index2] != 1)
				{
					_v[index1][index2] = 1;
					q.push(make_tuple(index1, index2, iTemp));
				}
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			if (!_v[i][j]) return -1;
	}

	return --iTemp;
}

void Combination(int _iNum, int _m, int _iSize, queue<tuple<int, int, int>> _q, vector<vector<int>> _v)
{
	queue<tuple<int, int, int>> qCpy;
	vector<vector<int>> vCpy;

	for (int i = _iNum; i <= _iSize - _m; ++i)
	{
		qCpy = _q;
		vCpy = _v;

		qCpy.push(make_tuple(vNumTwo[i].first, vNumTwo[i].second, 0));
		vCpy[vNumTwo[i].first][vNumTwo[i].second] = 1;

		if (_m > 1)
		{
			Combination(i + 1, _m - 1, _iSize, qCpy, vCpy);
		}
		else
		{
			q = qCpy;
			int iTemp = BFS(vCpy);
			if (-1 != iTemp)
			{
				g_min = min(g_min, iTemp);
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	vArr.resize(N, vector<int>(N));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> vArr[i][j];
			if (vArr[i][j] == 2)
			{
				vNumTwo.push_back(make_pair(i, j));
			}
		}
	}
	int iSize = vNumTwo.size();
	Combination(0, M, iSize, q, vArr);

	if (100 == g_min) cout << -1 << '\n';
	else cout << g_min;

	return 0;
}