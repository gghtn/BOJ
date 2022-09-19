#include <iostream>
using namespace std;

int main() {
	int n, d, m, y;
	string humanName;
	cin >> n;

	struct human {
		string name;
		int day;
		int month;
		int year;
	};

	cin >> humanName >> d >> m >> y;
	human young{ humanName,d,m,y}, old{ humanName,d,m,y };
	n--;

	while (n--) {
		cin >> humanName >> d >> m >> y;

		if (y > young.year || (y == young.year && m > young.month) || (y == young.year && m == young.month && d > young.day)) {
			young.name = humanName;
			young.day = d;
			young.month = m;
			young.year = y;
		}
		else if (y < old.year || (y == old.year && m < old.month) || (y == old.year && m == old.month && d < old.day)) {
			old.name = humanName;
			old.day = d;
			old.month = m;
			old.year = y;
		}
	}
	cout << young.name << "\n" << old.name;
	return 0;
}