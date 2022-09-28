#include <iostream>
using namespace std;

int main() {
	int n, num, max = 0, min = 1000000;
	cin >> n;
	while (n--) {
		cin >> num;
		if (max < num) max = num;
		if (min > num) min = num;
	}
	
	cout << max * min;

	return 0;
}