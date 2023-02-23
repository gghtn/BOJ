#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <memory>
#include <string.h>
using namespace std;
int N, M, MaxZeroSize;
int vArr[8][8];
queue<pair<int, int>> myQueue, tempQueue;

int BFS(int(*p)[8])
{
	int iReturn = MaxZeroSize;
	tempQueue = myQueue;
	while (!tempQueue.empty())
	{
		int idx1 = tempQueue.front().first, idx2 = tempQueue.front().second;
		tempQueue.pop();

		if (idx1 > 0 && p[idx1 - 1][idx2] == 0)
		{
			p[idx1 - 1][idx2] = 2;
			tempQueue.push(make_pair(idx1 - 1, idx2));
			--iReturn;
		}
		if (idx1 < N - 1 && p[idx1 + 1][idx2] == 0)
		{
			p[idx1 + 1][idx2] = 2;
			tempQueue.push(make_pair(idx1 + 1, idx2));
			--iReturn;
		}
		if (idx2 > 0 && p[idx1][idx2 - 1] == 0)
		{
			p[idx1][idx2 - 1] = 2;
			tempQueue.push(make_pair(idx1, idx2 - 1));
			--iReturn;
		}
		if (idx2 < M - 1 && p[idx1][idx2 + 1] == 0)
		{
			p[idx1][idx2 + 1] = 2;
			tempQueue.push(make_pair(idx1, idx2 + 1));
			--iReturn;
		}
	}

	return iReturn;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int iMax = 0;
	cin >> N >> M;
	vector<pair<int, int>> v;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> vArr[i][j];
			if (vArr[i][j] == 2) myQueue.push(make_pair(i, j));
			else if (vArr[i][j] == 0)
			{
				MaxZeroSize++;
				v.push_back(make_pair(i, j));
			}
		}
	}
	MaxZeroSize -= 3;

	int iTempMem[8][8];
	memcpy(iTempMem, vArr, sizeof(vArr));
	int size = v.size();
	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			for (int k = j + 1; k < size; ++k)
			{
				iTempMem[v[i].first][v[i].second] = 1;
				iTempMem[v[j].first][v[j].second] = 1;
				iTempMem[v[k].first][v[k].second] = 1;
				iMax = max(iMax, BFS(iTempMem));
				memcpy(iTempMem, vArr, sizeof(vArr));
			}
		}
	}

	cout << iMax;
	return 0;
}