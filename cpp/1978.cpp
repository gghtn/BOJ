#include <iostream>
#include <cmath>
using namespace std;

bool PrimeNumber(int num) {
	if (num == 1) return false;
	//i <= sqrt(num)이 아닌 i < sqrt(num) + 1일 경우 num이 2일 때 false가 나오게된다.
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n, num, result = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (PrimeNumber(num)) result++;
	}

	cout << result;
	return 0;
}