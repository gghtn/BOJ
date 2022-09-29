#include <iostream>
#include <string>
using namespace std;

int main() {
	int t, n, m, total;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		total = 0;
		for (int i = n; i <= m; i++) {
			string str = to_string(i);
			for (int j = 0; j < str.size(); j++) {
				if (str[j] == '0') total++;
			}
		}
		cout << total << '\n';
	}

	return 0;
}