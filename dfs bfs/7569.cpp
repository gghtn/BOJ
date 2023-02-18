#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int M, N, H;
int iArr[100][100][100];
queue<tuple<int, int, int>> myQueue;

void BFS(int(&_jArr)[4], int(&_kArr)[4])
{
	int idx1, idx2, idx3;
	int iDay = 0, iSize = myQueue.size(), iCnt = 0;
	while (!myQueue.empty())
	{
		tie(idx1, idx2, idx3) = myQueue.front();
		myQueue.pop();

		if (0 <= idx1 - 1 && iArr[idx1 - 1][idx2][idx3] == 0)
		{
			iArr[idx1 - 1][idx2][idx3] = -1;
			myQueue.push(make_tuple(idx1 - 1, idx2, idx3));
			++iCnt;
		}
		if (H > idx1 + 1 && iArr[idx1 + 1][idx2][idx3] == 0)
		{
			iArr[idx1 + 1][idx2][idx3] = -1;
			myQueue.push(make_tuple(idx1 + 1, idx2, idx3));
			++iCnt;
		}
		for (int i = 0; i < 4; ++i)
		{
			int index2 = idx2 + _jArr[i];
			int index3 = idx3 + _kArr[i];
			if (0 <= index2 && N > index2 && 0 <= index3 && M > index3)
			{
				if (iArr[idx1][index2][index3] == 0)
				{
					iArr[idx1][index2][index3] = -1;
					myQueue.push(make_tuple(idx1, index2, index3));
					++iCnt;
				}
			}
		}

		if (iSize)
		{
			if ((--iSize) == 0 && iCnt)
			{
				iSize = iCnt;
				iCnt = 0;
				++iDay;
			}
		}
	}

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				if (!iArr[i][j][k])
				{
					cout << -1;
					return;
				}
			}
		}
	}

	cout << iDay;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> M >> N >> H;

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				cin >> iArr[i][j][k];
				if (iArr[i][j][k] == 1)
				{
					iArr[i][j][k] = -1;
					myQueue.push(make_tuple(i, j, k));
				}
			}
		}
	}
	int jArr[4] = { 1,-1,0,0 };
	int kArr[4] = { 0,0,1,-1 };

	BFS(jArr, kArr);

	return 0;
}