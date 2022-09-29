#include <iostream>
#include <string>
using namespace std;

int main() {
	bool is_same = false;
	int arr[26] = { 0, }, max = 0, index = 0;
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 97) arr[int(str[i] - 97)]++;
		else arr[int(str[i] - 65)]++;
	}

	for (int i = 0; i < 26; i++) {
		if(max < arr[i]){
			index = i;
			max = arr[i];
			is_same = false;
		}
		else if (max == arr[i]) {
			is_same = true;
		}
	}

	if (is_same) cout << '?';
	else cout << char(index + 65);
	return 0;
}