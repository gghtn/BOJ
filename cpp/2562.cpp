#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, max = 0, index;
	vector<int> v;
	for (int i = 0; i < 9; i++) {
		cin >> n;
		if (n > max) max = n;
		v.push_back(n);
	}
	index = find(v.begin(), v.end(), max) - v.begin() + 1;
	cout << max << '\n' << index;
	return 0;
}