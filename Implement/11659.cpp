#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, iTemp = 0;
	cin >> N >> M;

	vector<int> v;
	v.resize(N + 1, 0);
	for (int i = 1; i < N + 1; ++i)
	{
		cin >> iTemp;
		v[i] = v[i - 1] + iTemp;
	}

	int idx1, idx2;
	while (M--)
	{
		cin >> idx1 >> idx2;
		cout << v[idx2] - v[idx1 - 1] << '\n';
	}

	return 0;
}