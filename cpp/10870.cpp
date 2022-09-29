#include <iostream>
using namespace std;

int fibo(int num) {
	if (num < 2) return num;
	return fibo(num - 1) + fibo(num - 2);
}

int main() {
	int n;
	cin >> n;
	cout << fibo(n);

	return 0;
}