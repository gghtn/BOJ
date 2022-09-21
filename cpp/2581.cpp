#include <iostream>
#include <cmath>
using namespace std;

bool prime(int num) {
	if (num == 1) return false;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
	}
	return true;
}

int main() {
	int m, n, sum = 0, min = 0;
	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		if (prime(i)) {
			sum += i;
			if (min == 0) min = i;
		}
	}
	if (min) cout << sum << '\n' << min;
	else cout << -1;
	return 0;
}