#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

vector<int> v;

int search(int left, int right, int m)
{
	int result;
	long long total;	// int의 범위가 넘어갈 수 있으므로
	while (left <= right || total < m)
	{
		result = (left + right) / 2;
		total = 0;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] > result) total += v[i] - result;
		}
		if (total > m) left = result + 1;
		else if (total < m) right = result - 1;
		else return result;
	}
	return result;
}

int main()
{
	int N, M, max_num = 0;
	cin >> N >> M;
	v.resize(N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	max_num = v.back();

	cout << search(0, max_num, M);
	return 0;
}