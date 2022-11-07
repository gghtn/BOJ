#include <iostream>
using namespace std;

int main() {
	int t, n, m, tmp;
	long long result;
	cin >> t;

	while (t--) {
		cin >> n >> m;
		result = 1;
		tmp = n;
		for (int i = m; i >= m - n + 1; i--) {
			result *= i;
			while (tmp != 1 && result % tmp == 0) {
				result /= tmp;
				tmp--;
			}
		}
		cout << result << '\n';
	}

	return 0;
}