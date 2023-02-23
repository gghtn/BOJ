#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, iMax = 0;
vector<vector<int>> v;
vector<vector<bool>> bV;

int idx1[4] = { 1, -1, 0, 0 };
int idx2[4] = { 0, 0, 1, -1 };

void DFS(int _i, int _j, int _iCnt, int _iTotal)
{
	if (_iCnt == 4)
	{
		iMax = max(iMax, _iTotal);
		return;
	}
	_iTotal += v[_i][_j];  // 이전 방문 체크
	bV[_i][_j] = true;
	++_iCnt;

	for (int i = 0; i < 4; ++i)
	{
		int index1 = _i + idx1[i], index2 = _j + idx2[i];
		if (0 > index1 || 0 > index2 || N <= index1 || M <= index2) continue;
		if (!bV[index1][index2])
			DFS(index1, index2, _iCnt, _iTotal);
	}
	bV[_i][_j] = false;
}

void Tetro(int _i, int _j)
{
	// ㅏ
	if (0 <= _i - 1 && N > _i + 1 && M > _j + 1)
		iMax = max(iMax, v[_i][_j] + v[_i + 1][_j] + v[_i][_j + 1] + v[_i - 1][_j]);

	// ㅗ
	if (0 <= _j - 1 && 0 <= _i - 1 && M > _j + 1)
		iMax = max(iMax, v[_i][_j] + v[_i][_j - 1] + v[_i][_j + 1] + v[_i - 1][_j]);

	// ㅓ
	if (0 <= _j - 1 && 0 <= _i - 1 && N > _i + 1)
		iMax = max(iMax, v[_i][_j] + v[_i][_j - 1] + v[_i - 1][_j] + v[_i + 1][_j]);

	// ㅜ
	if (0 <= _j - 1 && M > _j + 1 && N > _i + 1)
		iMax = max(iMax, v[_i][_j] + v[_i][_j - 1] + v[_i][_j + 1] + v[_i + 1][_j]);
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	v.resize(N, vector<int>(M));
	bV.resize(N, vector<bool>(M));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			DFS(i, j, 0, 0);
			Tetro(i, j);
		}
	}

	cout << iMax;
	return 0;
}