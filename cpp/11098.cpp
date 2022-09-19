#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, p, price = 0, max = 0;
	string tmp;
	cin >> n;
	vector <string> name(n);
	for (int i = 0; i < n; i++) {
		cin >> p;
		for (; p != 0; p--) {
			cin >> price;
			if (price > max) {
				max = price;
				cin >> name[i];
			}
			else cin >> tmp;
		}
		max = 0;
	}
	for (int j = 0; j < n; j++) {
		cout << name[j] << "\n";
	}
	return 0;
}