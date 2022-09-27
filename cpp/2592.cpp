#include <iostream>
#include <array>
using namespace std;

int main() {
	int n, arr[100] = { 0, }, mod = 0, num = 0, average = 0;
	for (int i = 0; i < 10; i++) {
		cin >> n;
		average += n;
		arr[n / 10]++;
		if (num < arr[n / 10]) {
			num = arr[n / 10];
			mod = n;
		}
	}
	cout << average / 10 << '\n' << mod;

	return 0;
}