#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int M, N;
	cin >> M >> N;
	int result=0, min;
	double m, n;
	m = ceil((double)sqrt(M));
	n = sqrt(N);
	min = (int)(m * m);
	if (m > floor(n)) {
		cout << "-1";
		return 0;
	}
	while (m <= n) {
		result += (int)(m * m);
		++m;
	}
	cout << result <<"\n" << min;
	return 0;
}