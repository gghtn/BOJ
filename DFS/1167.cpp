#include <iostream>
#include <vector>
using namespace std;

// 트리의 지름
int V, iMax, iFarIndex;
vector<vector<pair<int, int>>> v;
vector<bool> vecVisit;

void DFS(int _i, int _iNum)
{
	int iSize = v[_i].size();
	vecVisit[_i] = true;

	if (_iNum > iMax)
	{
		iFarIndex = _i;
		iMax = _iNum;
	}

	for (int i = 0; i < iSize; ++i)
	{
		if (!vecVisit[v[_i][i].first])
		{
			DFS(v[_i][i].first, _iNum + v[_i][i].second);
		}
	}
}


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> V;
	v.resize(V + 1);
	vecVisit.resize(V + 1);

	for (int i = 1; i <= V; ++i)
	{
		vector<pair<int, int>> vecTemp;

		int index = 0, iInput = 0, iLine = 0;
		cin >> index;
		while (true)
		{
			cin >> iInput;
			if (iInput == -1) break;
			cin >> iLine;
			vecTemp.push_back(make_pair(iInput, iLine));
		}
		v[index] = vecTemp;
	}

	DFS(1, 0);	// 한 지점에서 가장 먼 지점
	vecVisit = vector<bool>(V + 1);
	DFS(iFarIndex, 0);		// 그 지점에서 가장 먼 지점

	cout << iMax;
	return 0;
}