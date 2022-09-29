#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	cout << str[0];
	for (int i = 1; i < str.size(); i++) {
		if (str[i] == 45) {
			cout << str[i + 1];
			i++;
		}
	}


	return 0;
}