#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int t, arr[5];
	cin >> t;
	while (t--) {
		for (int i = 0; i < 5; i++) {
			cin >> arr[i];
		}

		for (int i = 0; i < 4; i++) {		//sort(arr, arr + 5);
			for (int j = i + 1; j < 5; j++) {
				if (arr[i] > arr[j]) swap(arr[i], arr[j]);
			}
		}

		if (arr[3] - arr[1] < 4) cout << arr[1] + arr[2] + arr[3] << '\n';
		else cout << "KIN" << '\n';
	}

	return 0;
}