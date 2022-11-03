#include <iostream>
#include <vector>
using namespace std;

pair<int, int> arr[40];

void fibo(int num) {
	arr[0] = { 1, 0 }; arr[1] = { 0, 1 };
	for (int i = 2; i <= num; i++) {
		arr[i].first = arr[i - 1].first + arr[i - 2].first;
		arr[i].second = arr[i - 1].second + arr[i - 2].second;
	}
	cout << arr[num].first << ' ' << arr[num].second << '\n';
}

int main() {
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		fibo(n);
	}

	return 0;
}