#include <iostream>
using namespace std;

int main() {
	int t, n, location;
	cin >> t;
	while (t--) {
		cin >> n;
		location = 0;
		while (n) {
			if (n % 2 == 1) cout << location << ' ';
			location++;
			n = n / 2;
		}
		cout << '\n';
	}

	return 0;
}