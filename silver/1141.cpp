// 문자열 자르기
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(const pair<string, int>& a, const pair<string, int>& b)
{
	return a.second < b.second;
}

int main()
{
	int N, max = 0;
	cin >> N;

	vector<pair<string, int>> v(N);
	max = N;

	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first;
		v[i].second = v[i].first.length();
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			string tmpStr = v[j].first.substr(0, v[i].second);
			if (v[i].first == tmpStr)
			{
				max--;
				break;
			}
		}
	}

	cout << max;
}