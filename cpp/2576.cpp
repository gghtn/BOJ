#include <iostream>
using namespace std;

int main() {
	int n, total = 0, min = 100;
	for (int i = 0; i < 7; i++) {
		cin >> n;
		if (n % 2 == 1) {
			total += n;
			if (min > n) min = n;
		}
	}
	if (min != 100) cout << total << '\n' << min;
	else cout << -1;

	return 0;
}