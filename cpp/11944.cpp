#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	string str = to_string(n);
	
	if (m < n * str.size()) {
		int repeat = m / str.size();
		int remain = m % str.size();

		while (repeat--) {
			cout << n;
		}

		for (int i = 0; i < remain; i++) {
			cout << str[i];
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << n;
		}
	}
	
	return 0;
}