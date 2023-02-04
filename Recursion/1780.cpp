#include <iostream>
#include <vector>
using namespace std;

int N;
int g_minus, g_zero, g_one;
vector<vector<int>> v;

void Search(int _index1, int _index2, int _N)
{
	int iTemp = v[_index1][_index2];
	bool bSame = true;
	if (1 < _N)
	{
		for (int i = _index1; i < _index1 + _N && bSame; ++i)
		{
			for (int j = _index2; j < _index2 + _N; ++j)
			{
				if (iTemp != v[i][j])
				{
					bSame = false;
					break;
				}
			}
		}
	}

	if (bSame)
	{
		if (iTemp == -1) g_minus++;
		else if (iTemp == 0) g_zero++;
		else g_one++;
	}
	else
	{
		int size = _N / 3;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				Search(_index1 + i * size, _index2 + j * size, size);
			}
		}
	}

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	v.resize(N);
	vector<int> vElement(N);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> vElement[j];
		}
		v[i] = vElement;
	}

	Search(0, 0, N);

	cout << g_minus << '\n' << g_zero << '\n' << g_one;
	return 0;
}