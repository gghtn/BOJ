#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		string str1, str2;
		cin >> str1 >> str2;

		cout << "Distances:";
		for (int i = 0; i < str1.size(); i++) {
			if (int(str2[i]) < int(str1[i])) {
				cout << ' ' << (int(str2[i]) + 26) - int(str1[i]);
			}
			else {
				cout << ' ' << int(str2[i]) - int(str1[i]);
			}
		}
		cout << '\n';
	}

	return 0;
}