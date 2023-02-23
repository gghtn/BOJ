#include <iostream>
#include <string>
#include <string.h>
#include <queue>
using namespace std;

int N;
string strArr[100];
bool bVisit[100][100];
queue<pair<int, int>> myQueue;

int g_iArr[4] = { 1, -1, 0, 0 };
int g_jArr[4] = { 0, 0 , 1, -1 };

void BFS(bool _b)
{
	int iTotal = 0;
	pair<int, int> pr;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!bVisit[i][j])
			{
				iTotal++;
				myQueue.push(make_pair(i, j));
				while (!myQueue.empty())
				{
					pr = myQueue.front();
					myQueue.pop();

					for (int k = 0; k < 4; ++k)
					{
						int idx1 = pr.first + g_iArr[k];
						int idx2 = pr.second + g_jArr[k];
						if (0 <= idx1 && N > idx1 && 0 <= idx2 && N > idx2)
						{
							if (!_b)
							{
								if (!bVisit[idx1][idx2] && strArr[pr.first][pr.second] == strArr[idx1][idx2])
								{
									bVisit[idx1][idx2] = 1;
									myQueue.push(make_pair(idx1, idx2));
								}
							}
							else
							{
								if (!bVisit[idx1][idx2])
								{
									if (strArr[pr.first][pr.second] == 'R' || strArr[pr.first][pr.second] == 'G')
									{
										if (strArr[idx1][idx2] == 'R' || strArr[idx1][idx2] == 'G')
										{
											bVisit[idx1][idx2] = 1;
											myQueue.push(make_pair(idx1, idx2));
										}
									}
									else
									{
										if (strArr[idx1][idx2] == 'B')
										{
											bVisit[idx1][idx2] = 1;
											myQueue.push(make_pair(idx1, idx2));
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << iTotal;
}

int main()
{

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> strArr[i];
	}

	BFS(false);
	cout << ' ';
	memset(bVisit, 0, sizeof(bVisit));
	BFS(true);
	return 0;
}