#include <iostream>
#include <cmath>
using namespace std;

#define MAX  100000;

int dp[50001];

int main()
{
	int n, iCnt = 0;
	cin >> n;
	dp[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		dp[i] = MAX;
		for (int j = 1; j * j <= i; ++j)
		{
			if (j * j == i)
			{
				dp[i] = 1;
				break;
			}
			dp[i] = min(dp[i], dp[i - j * j] + dp[j * j]);
		}
	}

	cout << dp[n];

	return 0;
}