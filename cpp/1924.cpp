#include <iostream>
using namespace std;

enum{SUN, MON, TUE, WED, THU, FRI, SAT};

int main() {
	int x, y, mon[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	cin >> x >> y;
	while (x != 0) {
		y += mon[x - 1];
		x--;
	}
	switch (y % 7)
	{
	case SUN:
		cout << "SUN";
		break;
	case MON:
		cout << "MON";
		break;
	case TUE:
		cout << "TUE";
		break;
	case WED:
		cout << "WED";
		break;
	case THU:
		cout << "THU";
		break;
	case FRI:
		cout << "FRI";
		break;
	default:
		cout << "SAT";
		break;
	}
	return 0;
}