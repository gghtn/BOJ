#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

#define MAX 100000
bool arr[100001];

int Factorization(int num) {
	int result = 1, n = 2;
	while (num != n) {
		if (num % n == 0) {
			num /= n;
			result++;
			continue;
		}
		n++;
	}
	return result;
}

int main() {
	int A, B, total = 0;
	cin >> A >> B;

	memset(arr, 1, 100001);
	for (int i = 2; i <= MAX; i++) {
		if (arr[i] ==  0) continue;
		for (int j = 2 * i; j <= MAX; j += i) {
			arr[j] = 0;
		}
	}

	for (int i = A; i <= B; i++) {
		if (arr[i]) continue;
		if (arr[Factorization(i)]) total++;
	}
	cout << total;
	return 0;
}