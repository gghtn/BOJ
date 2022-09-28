#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second < b.second; //pair 두 번째 값으로 오름차순 정렬
}

int main() {
	int n, total = 0;
	vector<pair<int, int>> p(5);
	pair<int, int> tmp;
	for (int i = 1; i <= 8; i++) {
		cin >> n;
		tmp = { n, i };
		for (int j = 0; j < 5; j++) {
			if (p[j].first < tmp.first) {
				swap(p[j], tmp);
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		total += p[i].first;
	}

	cout << total << '\n';
	sort(p.begin(), p.end(), compare);
	for (int i = 0; i < 5; i++) {
		cout << p[i].second << ' ';
	}
	return 0;
}