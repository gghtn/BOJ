#include <iostream>
#include <string>
using namespace std;
int stack[10000];

void push(int num) {
	for(int i = 0; i < 10000; i++){
		if (!stack[i]) {
			stack[i] = num;
			break;
		}
	}
}
int pop() {
	int result = -1;
	if (!stack[0]) return result;

	for (int i = 0; i < 10000; i++) {
		if (!stack[i]) {
			result = stack[i - 1];
			stack[i - 1] = 0;
			return result;
		}
	}
}
int size() {
	int result = 0;
	for (int i = 0; i < 10000; i++) {
		if (stack[i]) result++;
		else break;
	}
	return result;
}
bool empty() {
	if (stack[0] == 0) return 1;
	else return 0;
}
int top() {
	int result = -1;
	if (!stack[0]) return result;

	for (int i = 0; i < 10000; i++) {
		if (!stack[i]) {
			result = stack[i - 1];
			return result;
		}
	}
}


int main() {
	int n, num;
	string str;
	cin >> n;

	while (n--) {
		cin >> str;
		if (str == "push") {
			cin >> num;
			push(num);
		}
		else if (str == "pop") cout << pop() << '\n';
		else if (str == "size") cout << size() << '\n';
		else if (str == "empty") cout << empty() << '\n';
		else if (str == "top") cout << top() << '\n';
	}

	return 0;
}