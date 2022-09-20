#include <iostream>
using namespace std;

int main() {
	int T, n;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int c, total = 0;
		float GPA = 0.0, g;

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> c >> g;
			total += c;
			GPA += g * c;
		}
		cout << fixed;
		cout.precision(1);
		cout << total << " " << GPA / total << endl;
	}
	return 0;
}