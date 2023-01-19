#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//DP

vector<int> v;

int main()
{
	int n, temp = 0, start = 0, big = 0;
	cin >> n;

	v.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	temp = v[0], start = v[0], big = v[0];
	for (int i = 1; i < n; i++)
	{
		if (0 > start)
		{
			start = max(start, v[i]);
			temp = start;
		}
		else
		{
			temp = temp + v[i];
		}

		if (0 > temp)
		{
			start = v[i];
			temp = start;
		}

		big = max(big, temp);
	}

	cout << big;
	return 0;
}