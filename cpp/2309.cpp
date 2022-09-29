#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[9], index, index2, total = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		total += arr[i];
	}

	sort(arr, arr + 9);

	int remain;
	for (index = 0; index < 8; index++) {
		remain = total - 100 - arr[index];
		for (index2 = 1; index2 < 9; index2++) {
			if (remain == arr[index2]) break;
		}
		if (remain == arr[index2]) break;
	}

	for (int i = 0; i < 9; i++) {
		if (i != index && i != index2) cout << arr[i] << '\n';
	}

	return 0;
}