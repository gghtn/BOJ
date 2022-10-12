#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n-1; i++) {

		int tmp = n - 1 - i;
		for(int i = 0; i < tmp; i++){
			cout << ' ';
		}

		for (int j = tmp; j < n + i; j++) {
			if (j == tmp || j == n + i - 1) cout << '*';
			else cout << ' ';
		}
		cout << '\n';
	}

	for (int i = 0; i < 2 * n - 1; i++) cout << '*';

	return 0;
}