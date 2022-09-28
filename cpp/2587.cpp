#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[5], aver = 0;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		aver += arr[i];
	}
	sort(arr, arr+5);
	cout << aver / 5 << ' ' << arr[2];

	return 0;
}