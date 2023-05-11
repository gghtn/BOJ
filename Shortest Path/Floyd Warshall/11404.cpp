#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int dp[101][101];

void floyd()
{
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	fill(&dp[1][1], &dp[100][100], 1e9);

	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		dp[a][b] = min(dp[a][b], c);
	}

	floyd();

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (dp[i][j] >= 1e9 || i == j) cout << "0 ";
			else cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}