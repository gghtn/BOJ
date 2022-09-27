#include <iostream>
using namespace std;

int main() {
	int a, b, sum = 0, i = 1, num = 1;
	cin >> a >> b;

	while(num <= b) {
		for (int j = 0; j < i; j++) {
			if (num >= a && num <= b) sum += i;
			num++;
		}
		i++;
	}
	cout << sum;

	return 0;
}