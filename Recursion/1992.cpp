#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<string> v;

void QuadTree(int idx1, int idx2, int _n)
{
	int iTemp = int(v[idx1][idx2] - '0');
	bool bSame = true;
	if (_n != 1)
	{
		for (int i = idx1; i < _n + idx1; ++i)
		{
			for (int j = idx2; j < _n + idx2; ++j)
			{
				if (iTemp != int(v[i][j] - '0'))
				{
					_n /= 2;
					cout << '(';
					QuadTree(idx1, idx2, _n);
					QuadTree(idx1, idx2 + _n, _n);
					QuadTree(idx1 + _n, idx2, _n);
					QuadTree(idx1 + _n, idx2 + _n, _n);
					bSame = false;
					cout << ')';
					break;
				}
			}
			if (!bSame) break;
		}
		if (bSame) cout << iTemp;

	}
	else
		cout << iTemp;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	v.resize(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	QuadTree(0, 0, N);
}