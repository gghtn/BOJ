#include <iostream>
#include <algorithm>
using namespace std;

int DP[101][100001]; //범위가 넘어 함수 내부에 선언할 수 없다.

int main() {
	int n, k;
	cin >> n >> k;
	int w[101] = { 0, }, v[101] = { 0, };

	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			if (w[j] <= i) DP[j][i] = max(DP[j - 1][i], DP[j - 1][i - w[j]] + v[j]);
			else DP[j][i] = DP[j - 1][i];
		}
	}
	cout << DP[n][k];
	return 0;
}