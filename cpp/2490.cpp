#include <iostream>
using namespace std;

int main() {
	int n, total;
	for (int i = 0; i < 3; i++) {
		total = 0;
		for (int j = 0; j < 4; j++) {
			cin >> n;
			total += n;
		}
		switch (total) {
		case 0:
			cout << 'D' << '\n';
			break;
		case 1:
			cout << 'C' << '\n';
			break;
		case 2:
			cout << 'B' << '\n';
			break;
		case 3:
			cout << 'A' << '\n';
			break;
		default:
			cout << 'E' << '\n';
		}
	}
	return 0;
}