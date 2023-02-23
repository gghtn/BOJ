#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

queue<tuple<int, int, int>> myQueue;
int iBoxArr[1002][1002];
int N, M;

void PushQueue(int i, int j, int num)
{
	if (!iBoxArr[i - 1][j] && i > 1)
	{
		myQueue.push(make_tuple(i - 1, j, num));
		iBoxArr[i - 1][j] = 1;
	}

	if (!iBoxArr[i + 1][j] && i < N)
	{
		myQueue.push(make_tuple(i + 1, j, num));
		iBoxArr[i + 1][j] = 1;
	}

	if (!iBoxArr[i][j + 1] && j < M)
	{
		myQueue.push(make_tuple(i, j + 1, num));
		iBoxArr[i][j + 1] = 1;
	}

	if (!iBoxArr[i][j - 1] && j > 1)
	{
		myQueue.push(make_tuple(i, j - 1, num));
		iBoxArr[i][j - 1] = 1;
	}
}

int BFS()
{
	int iCount = 0;
	int index1 = 0, index2 = 0, iTempCount = 0;

	while (!myQueue.empty())
	{
		tie(index1, index2, iTempCount) = myQueue.front();
		myQueue.pop();
		if (iTempCount == iCount) ++iCount;

		PushQueue(index1, index2, iCount);
	}

	return iCount - 1;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int iTemp, iTotal = 0;
	cin >> M >> N;

	for (int i = 1; i < N + 1; ++i)
	{
		for (int j = 1; j < M + 1; ++j)
		{
			cin >> iTemp;
			if (iTemp == 1)
			{
				iBoxArr[i][j] = 1;
				myQueue.push(make_tuple(i, j, 0));
			}
			else if (iTemp == -1)
				iBoxArr[i][j] = -1;
		}
	}

	int result = BFS();
	for (int i = 1; i < N + 1; ++i)
	{
		for (int j = 1; j < M + 1; ++j)
		{
			if (!iBoxArr[i][j])
			{
				cout << -1;
				return 0;
			}
		}
	}
	cout << result;
	return 0;
}