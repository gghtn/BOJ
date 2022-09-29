#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, total = 0;
	string str;
	cin >> n >> str;

	for (int i = 0; i < str.size(); i++) {
		total += (int)str[i] - 48;
	}
	cout << total;

	return 0;
}