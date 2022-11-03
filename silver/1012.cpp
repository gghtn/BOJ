#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int total;
// 재귀 or DFS
int Recursion(vector<vector<bool>>& v, int x, int y) {
	int result = 0;
	if (v[x][y] != 1) return 0;
	else {
		v[x][y] = 0;
		Recursion(v, x - 1, y);
		Recursion(v, x + 1, y);
		Recursion(v, x, y + 1);
		Recursion(v, x, y - 1);
	}
	return 1;
}

int main() {
	int T, M, N, K, m, n;
	cin >> T;

	while (T--) {
		total = 0;
		cin >> M >> N >> K;
		vector<vector<bool>> v(M+2,vector<bool>(N+2));
		while (K--) {
			cin >> m >> n;
			v[m+1][n + 1] = 1;
		}
		for (int i = 1; i <= M+1; i++) {
			for (int j = 1; j <= N + 1; j++) {
				total += Recursion(v, i, j);
			}
		}
		cout << total << '\n';
	}

	return 0;
}