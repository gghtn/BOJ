#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (; n != 0;n--) {
		for (int i = 0; i < n; i++) {
			cout << "*";
		}
		cout << '\n';
	}
	return 0;
}