#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

#define MAX 100000
bool arr[100001];
int cnt[100001];

int main() {
	int A, B, total = 0;
	cin >> A >> B;

	memset(arr, 1, 100001);

	for (int i = 2; i <= MAX; i++) {
		if (arr[i] == 0) continue;
		for (int j = 2 * i; j <= MAX; j += i) {
			arr[j] = 0;
		}
	}

	for (int i = 2; i <= MAX; i++) {
		if (arr[i]) {
			for (int j = 2*i; j <= MAX; j+=i) {
				int tmp = j;
				while (tmp % i == 0) {
					tmp /= i;
					cnt[j]++;
				}
			}
		}
	}

	for (int i = A; i <= B; i++) {
		if (arr[i]) continue;
		if (arr[cnt[i]]) total++;
	}
	cout << total;
	return 0;
}