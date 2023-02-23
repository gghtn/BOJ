#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

vector<string> v;
queue<tuple<int, int, int>> myQueue;

int idxArr1[4] = { 1, 0, -1, 0 };
int idxArr2[4] = { 0, 1, 0, -1 };

void BFS(int _n, int _m)
{
	myQueue.push(make_tuple(0, 0, 1));
	int idx1 = 0, idx2 = 0, iCnt = 0, iMin = 10000, iTemp = 1;
	while (!myQueue.empty())
	{
		tie(idx1, idx2, iCnt) = myQueue.front();
		myQueue.pop();
		v[idx1][idx2] = '0';
		if (iTemp == iCnt) iTemp++;

		for (int i = 0; i < 4; ++i)
		{
			int index1 = idx1 + idxArr1[i], index2 = idx2 + idxArr2[i];
			if (0 <= index1 && index1 <= _n && 0 <= index2 && index2 <= _m)
			{
				if (index1 == _n && index2 == _m)
				{
					iMin = min(iMin, iTemp);
					break;
				}
				if (v[index1][index2] == '1')
				{
					myQueue.push(make_tuple(index1, index2, iTemp));
					v[index1][index2] = '0';
				}

			}
		}
	}
	cout << iMin;
}

int main()
{
	int N, M;
	cin >> N >> M;
	v.resize(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	BFS(N - 1, M - 1);

	return 0;
}