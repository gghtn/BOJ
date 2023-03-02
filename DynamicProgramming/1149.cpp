#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	v.resize(N, vector<int>(3));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> v[i][j];
		}
	}

	for (int i = 1; i < N; ++i)
	{
		v[i][0] += min(v[i - 1][1], v[i - 1][2]);
		v[i][1] += min(v[i - 1][0], v[i - 1][2]);
		v[i][2] += min(v[i - 1][0], v[i - 1][1]);
	}

	cout << min({ v[N - 1][0], v[N - 1][1], v[N - 1][2] });

	return 0;
}