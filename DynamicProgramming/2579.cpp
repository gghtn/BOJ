#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> v(N + 1);
	vector<int> vecDP(N + 1);

	for (int i = 1; i < N + 1; ++i)
	{
		cin >> v[i];
	}

	vecDP[1] = v[1];			// 1������ �ִ밪
	vecDP[2] = v[1] + v[2];		// 2������ �ִ밪

	int index = 1;
	for (int i = 3; i < N + 1; ++i)
	{
		vecDP[i] = max(vecDP[i - 2] + v[i], vecDP[i - 3] + v[i - 1] + v[i]);	// i������ �ִ밪
	}

	cout << vecDP[N];

	return 0;
}