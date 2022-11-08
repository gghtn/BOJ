#include <iostream>
using namespace std;

int arr[10];

int main() {
	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;

		for (int j = 0; j < n; j++) {
			if (arr[j] == 0 && tmp == 0) {
				arr[j] = i + 1;
				break;
			}
			else {
				if (arr[j] == 0) tmp--;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}