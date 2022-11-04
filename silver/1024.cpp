#include <iostream>
using namespace std;

int main() {
	int N, L, tmpN = 0, tmpL = 0, s;
	cin >> N >> L;

	for (int i = L; i <= 100; i++) {
		s = (i - 1)*(2 + ((i - 1) - 1)) / 2;		//수열의 합 공식 Sn = n*(2*a + (n-1)*d)/2  (a=첫 째항, d = 공차)
		tmpN = N - s;
		if (tmpN >= i) {
			if (tmpN % i == 0) {
				tmpN = tmpN / i;
				tmpL = i;
				break;
			}
		}
		else if (tmpN == 0) {
			tmpL = i;
			break;
		}
		else {
			cout << -1;
			return 0;
		}
		if (i == 100) {
			cout << -1;
			return 0;
		}
	}

	for (int i = 0; i < tmpL; i++) {
		cout << tmpN + i << ' ';
	}

	return 0;
}