#include <iostream>
#include <vector>
using namespace std;

int g_iTotalZero, g_iTotalOne;
void Search(int _idx1, int _idx2, int _N, vector<vector<int>>& _r)
{
	int iTemp = _r[_idx1][_idx2];

	if (_N == 1)
	{
		if (iTemp == 0) g_iTotalZero++;
		else g_iTotalOne++;
		return;
	}

	for (int i = _idx1; i < _N + _idx1; ++i)
	{
		for (int j = _idx2; j < _N + _idx2; ++j)
		{
			if (iTemp != _r[i][j])
			{
				_N /= 2;
				Search(_idx1, _idx2, _N, _r);
				Search(_idx1 + _N, _idx2, _N, _r);
				Search(_idx1, _idx2 + _N, _N, _r);
				Search(_idx1 + _N, _idx2 + _N, _N, _r);
				return;
			}
		}

		if (i == _N + _idx1 - 1)
		{
			if (iTemp == 0) g_iTotalZero++;
			else g_iTotalOne++;
		}
	}

}

int main()
{
	int N;
	cin >> N;
	vector<vector<int>> vv(N, vector<int>(N));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> vv[i][j];
		}
	}

	Search(0, 0, N, vv);

	cout << g_iTotalZero << '\n' << g_iTotalOne;

	return 0;
}