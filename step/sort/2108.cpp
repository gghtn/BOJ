#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[8001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num, mode = 0, modeNum = 0, sum = 0;
	bool is_mode = true;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> num;
		v[i] = num;
		arr[num + 4000]++;
		sum += num;
	}
	sort(v.begin(), v.end());

	int j = 0;
	int index = 0;
	while (j < n) {
		if (arr[index]) {
			j += arr[index];
			if (mode < arr[index]) {
				mode = arr[index];
				modeNum = index;
				is_mode = true;
			}
			else if (mode == arr[index]) {
				if (is_mode) {
					modeNum = index;
					is_mode = false;
				}
			}
		}
		index++;
	}
	//num이 int형이기 때문에 sum은 int형 sum을 float으로할 경우 틀렸다고 나오게됨
	cout << (int)round((float)sum / n) << '\n' << v[n / 2] << '\n' << modeNum - 4000 << '\n' << v[n - 1] - v[0];

	return 0;
}