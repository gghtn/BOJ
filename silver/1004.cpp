#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T, num, r, total;
	int x1, y1, x2, y2, tmpX, tmpY;
	bool bStart = false, bEnd = false;
	cin >> T;

	while (T--) {
		total = 0;
		cin >> x1 >> y1 >> x2 >> y2 >> num;
		while (num--) {
			cin >> tmpX >> tmpY >> r;

			if (pow((tmpX - x1), 2) + pow((tmpY - y1), 2) < (double)r * r) bStart = true;
			if (pow((tmpX - x2), 2) + pow((tmpY - y2), 2) < (double)r * r) bEnd = true;

			if (bStart ^ bEnd) total++;

			bStart = false;
			bEnd = false;
		}
		cout << total << '\n';
	}

	return 0;
}