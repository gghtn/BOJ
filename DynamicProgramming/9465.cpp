#include <iostream>
using namespace std;

int iArr[2][100001];
int dp[2][100001];

int main()
{
	int T, n;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				cin >> iArr[i][j];
			}
		}
		dp[0][0] = 0;
		dp[1][0] = 0;
		dp[0][1] = iArr[0][1];
		dp[1][1] = iArr[1][1];

		for (int i = 2; i <= n; ++i)
		{
			dp[0][i] = iArr[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = iArr[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}

		cout << max(dp[0][n], dp[1][n]) << '\n';
	}

	return 0;
}