#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

vector<pair<int, int>> vecGraph[10001];
bool bVisit[10001];

pair<int, int> DFS(int _start, int _cost = 0)
{
	pair<int, int> prReturn = { _cost, _start };
	bVisit[_start] = true;

	int iSize = vecGraph[_start].size();
	for (int i = 0; i < iSize; ++i)
	{
		pair<int, int> temp = vecGraph[_start][i];
		if (bVisit[temp.second]) continue;		// 이전 위치는 탐색 안함

		temp = DFS(temp.second, temp.first + _cost);

		if (prReturn.first < temp.first)
			prReturn = temp;
	}
	bVisit[_start] = false;
	return prReturn;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, fr, to, cost, iMax = 0;
	cin >> n;

	for (int i = 0; i < n - 1; ++i)
	{
		cin >> fr >> to >> cost;
		vecGraph[fr].push_back({ cost, to });
		vecGraph[to].push_back({ cost, fr });
	}

	pair<int, int> temp = DFS(1);			// 특정한 점에서 가장 멀리있는 점

	iMax = DFS(temp.second).first;			// 트리의 지름
	cout << iMax;
}