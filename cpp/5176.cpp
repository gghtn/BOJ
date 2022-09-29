#include <iostream>
#include <vector>
using namespace std;

int main() {
	int k, p, m, num, out;
	cin >> k;

	while (k--) {
		cin >> p >> m;
		vector<int> v(p);
		out = 0;
		for (int i = 0; i < p; i++) {
			cin >> num;
			v[num-1]++;
			if (v[num-1] > 1) out++;
		}
		cout << out << '\n';
	}

	return 0;
}