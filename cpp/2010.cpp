#include <iostream>
using namespace std;

int main() {
	int n, total = 0, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		total += m - 1;
	}
	cout << total + 1;
	return 0;
}