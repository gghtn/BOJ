#include <iostream>
using namespace std;

int N, M;
int dp[1025][1025];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			int iTemp;
			cin >> iTemp;
			dp[i][j] = iTemp + dp[i][j - 1];
		}
	}

	while (M--)
	{
		int i, j, i2, j2;
		int total = 0;
		cin >> i >> j >> i2 >> j2;

		for (; i <= i2; ++i)
		{
			total += dp[i][j2] - dp[i][j - 1];
		}
		cout << total << '\n';
	}
	return 0;
}