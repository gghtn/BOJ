#include <iostream>
using namespace std;

int main() {
	int total = 0, max = 0, score[4] = { 0, }, winner;
	for (int i = 1; i <= 5; i++) {
		cin >> score[0] >> score[1] >> score[2] >> score[3];
		for (int j = 0; j < 4; j++) {
			total += score[j];
		}
		if (max < total) {
			max = total;
			winner = i;
		}
		total = 0;
	}
	cout << winner << ' ' << max;

	return 0;
}