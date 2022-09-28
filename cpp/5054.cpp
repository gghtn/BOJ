#include <iostream>
using namespace std;

int main() {
	int t, n, xi, min, max;
	cin >> t;

	while (t--) {
		cin >> n;
		min = 99, max = 0;
		while (n--) {
			cin >> xi;
			if (xi < min) min = xi;
			if (xi > max) max = xi;
		}
		cout << (max - min) * 2 << '\n';
	}

	return 0;
}