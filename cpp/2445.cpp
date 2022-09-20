#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) cout << '*';
		for (int j = i * 2; j < 2 * n; j++) cout << ' ';
		for (int j = 0; j < i; j++) cout << '*';
		cout << '\n';
	}

	for (int i = 1; i < n; i++) {
		for (int j = i; j < n; j++) cout << '*';
		for (int j = (n - i) * 2; j < 2 * n; j++) cout << ' ';
		for (int j = i; j < n; j++) cout << '*';
		cout << '\n';
	}
	return 0;
}