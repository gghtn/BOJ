#include <iostream>
#include <string>
using namespace std;

int main() {
	int num1, num2, num3, arr[10] = {0,};
	cin >> num1 >> num2 >> num3;
	string str = to_string(num1 * num2 * num3);

	char ch;
	for (int i = 0; i < str.size(); i++) {
		ch = str[i];
		arr[atoi(&ch)]++;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}