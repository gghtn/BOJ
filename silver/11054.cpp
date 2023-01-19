#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A[1000];

int main()
{
	int N;
	cin >> N;
	vector<int> Larr(N, 1);
	vector<int> Rarr(N, 1);
	vector<int> arr_sum(N);

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (int i = 1; i < N; i++)
	{
		int big = 0;
		for (int j = i - 1; 0 <= j; j--)
		{
			if (A[j] < A[i])
			{
				big = max(Larr[j], big);
			}
		}
		Larr[i] += big;
	}

	for (int i = N - 2; 0 <= i; i--)
	{
		int big = 0;
		for (int j = i + 1; j < N; j++)
		{
			if (A[j] < A[i])
			{
				big = max(Rarr[j], big);
			}
		}
		Rarr[i] += big;
	}

	for (int i = 0; i < N; i++)
	{
		arr_sum[i] = Larr[i] + Rarr[i];
	}

	sort(arr_sum.begin(), arr_sum.end());
	cout << arr_sum.back() - 1;
	return 0;
}