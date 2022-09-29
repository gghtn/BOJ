#include <iostream>
#include <vector>
using namespace std;

int main() {
	int k, num, total = 0;
	cin >> k;
	vector<int> v;
	while(k--){
		cin >> num;
		if (num != 0) v.push_back(num);
		else v.pop_back();
	}
	while (!v.empty()) {
		total += v.back();
		v.pop_back();
	}

	cout << total;

	return 0;
}