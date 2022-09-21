#include <iostream>
using namespace std;

int main() {
	int n, fibo[50] = { 0,1, };
	cin >> n;
	for (int i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 2] + fibo[i - 1];
	}
	cout << fibo[n];
	return 0;
}