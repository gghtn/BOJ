#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	//내림차순 변경
	sort(v.begin(), v.end(), greater<>());
	cout << v[k - 1];
	return 0;
}