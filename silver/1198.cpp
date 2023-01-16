#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Area(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
	int result = 0;
	result = ((a.first * b.second + b.first * c.second + c.first * a.second)
		- (b.first * a.second + c.first * b.second + a.first * c.second));

	return abs(result);
}

int main()
{
	int N, max_area = 0;
	cin >> N;
	vector<pair<int, int>> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first >> v[i].second;
	}

	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				max_area = max(max_area, Area(v[i], v[j], v[k]));
			}
		}
	}

	printf("%.9f", (double)max_area / 2);

	return 0;
}