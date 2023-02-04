#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<pair<int, int>> v(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), compare);

	int iTotal = 1;
	int iMax = v[0].second;
	for (int i = 1; i < N; ++i)
	{
		if (iMax <= v[i].first)
		{
			iMax = v[i].second;
			iTotal++;
		}
	}
	cout << iTotal;

	return 0;
}