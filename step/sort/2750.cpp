#include <iostream>
using namespace std;

int main() {
	int N, number[1000] = { };
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> number[i];
	}

	for (int i = 0; i < N-1; i++) {
		for (int j = i; j < N-1; j++) {
			if (number[i] > number[j + 1]) {
				swap(number[i], number[j + 1]);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << number[i] << '\n';
	}
	return 0;
}
/*삽입정렬
int N;
cin >> N;
vector <int> number(N);

for (int i = 0; i < N; i++) {
	cin >> number[i];
}

for (int i = 1; i < N; i++) {
	for (int j = i - 1; j >= 0 && number[j] > number[j + 1]; j--) {
		swap(number[j], number[j + 1]);
	}
}

for (int i = 0; i < N; i++) {
	cout << number[i] << '\n';
}
return 0;
*/