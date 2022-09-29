#include <iostream>
#include <string>
#include <algorithm> //reverse 문자열 뒤집기
using namespace std;

int Rev(int num) {
	string str = to_string(num);
	reverse(str.begin(), str.end());
	return stoi(str);
}

int main() {
	int num1, num2;
	cin >> num1 >> num2;

	cout << Rev(Rev(num1) + Rev(num2));

	return 0;
}