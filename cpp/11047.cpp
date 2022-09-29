#include <iostream>
using namespace std;

int main() {
	int n, k, won, total = 0, arr[10];
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int j = n - 1; j >= 0 && k != 0; j--) {
		total += k / arr[j];
		k = k % arr[j];
	}
	cout << total;

	return 0;
}