#include <iostream>
using namespace std;

int main() {
	int t, num;
	string str;
	cin >> t;
	while (t--) {
		cin >> num >> str;
		str.erase(str.begin()+ num - 1);
		cout << str <<'\n';
	}

	return 0;
}