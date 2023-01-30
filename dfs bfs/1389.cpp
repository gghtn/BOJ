#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

queue<int>	myQueue;
bool		graph[101][101];
bool		visit[101];
int			iArr[101];
int			N, M;

int _BFS(int _iNum)
{
	int iReturn = 0, iTemp = 0, index = 0, curIndex = 1;
	visit[_iNum] = true;
	myQueue.push(_iNum);

	while (!myQueue.empty())
	{
		iTemp = myQueue.front();
		if (index == 0 || index == 1)
		{
			if (index == 1) iArr[curIndex]--;
			index++;
		}
		else if (iArr[curIndex] == 0)
		{
			index++, curIndex++;
			iArr[curIndex]--;
		}
		else
		{
			iArr[curIndex]--;
		}
		myQueue.pop();

		for (int i = 1; i <= N; ++i)
		{
			if (!visit[i] && graph[iTemp][i])
			{
				visit[i] = true;
				myQueue.push(i);
				iReturn += index;
				iArr[index] += 1;
			}
		}
	}
	memset(visit, 0, 101);
	return iReturn;
}


int main()
{
	int iTemp1, iTemp2, iMin = 10000, result = 0;
	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		cin >> iTemp1 >> iTemp2;
		graph[iTemp1][iTemp2] = graph[iTemp2][iTemp1] = 1;
	}

	for (int i = 1; i <= N; ++i)
	{
		int iTemp = _BFS(i);
		if (iMin > iTemp)
		{
			iMin = iTemp;
			result = i;
		}
	}
	cout << result;


	return 0;
}