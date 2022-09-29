#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int k, n;
	cin >> k;
	for (int i = 1; i <= k; i++) {

		int largest_gab = 0;

		cin >> n;
		vector<int> v(n);
		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}
		
		sort(v.begin(), v.end());

		for (int i = 0; i < n - 1; i++) {
			if (v[i + 1] - v[i] > largest_gab) largest_gab = v[i + 1] - v[i];
		}

		cout << "Class " << i << '\n';
		cout << "Max " << v[n - 1] << ", Min " << v[0] << ", Largest gap " << largest_gab << '\n';

		v.clear();		   //
		v.shrink_to_fit(); // 벡터의 메모리 해제;
	}

	return 0;
}