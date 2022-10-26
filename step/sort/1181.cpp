#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, string>& a, pair<int, string>& b) {
	if (a.first == b.first) {
		for (int i = 0; i < a.first; i++) {
			if (a.second[i] == b.second[i]) continue;
			else return a.second[i] < b.second[i];
		}
	}
	return a.first < b.first;
}

int main() {
	int n;
	string str;
	cin >> n;
	vector<pair<int,string>> v(n);
	
	
	for (int i = 0; i < n; i++) {
		cin >> str;
		v[i].first = str.size();
		v[i].second = str;
	}

	sort(v.begin(), v.end(), compare);

	cout << v[0].second << '\n';
	for (int i = 1; i < n; i++) {
		if(v[i-1] != v[i]) cout << v[i].second << '\n';
	}
	return 0;
}