#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
int part(int list[], int low, int high) {
	int p = low; 
	while (1) {
		while (!(list[p] <= list[low] && list[p] >= list[high])) {
			if (list[p] > list[low]) {
				++low;
			}
			if (list[p] < list[high]) {
				--high;
			}
		}

		if (high > low) {
			swap(list[high], list[low]);
		}
		else {
			swap(list[p], list[high]);
			break;
		}
	}
	return high;
}

void quick(int list[], int low, int high) {
	if (low < high) {
		int pivot = part(list, low, high);
		
		quick(list, low, pivot - 1);
		quick(list, pivot + 1, high);
	}
}*/

int main() {
	int N;
	cin >> N;
	vector <int> number(N);

	for (int i = 0; i < N; i++) {
		cin >> number[i];
	}

	sort(number.begin(), number.end());

	for (int i = 0; i < N; i++) {
		cout << number[i] << '\n';
	}
	return 0;
}