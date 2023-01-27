#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	unsigned int K, N;
	unsigned int maxLen = 0;
	cin >> K >> N;
	vector<unsigned int> lenVec(N);

	for (int i = 0; i < K; ++i)
	{
		cin >> lenVec[i];
		if (i == 0) maxLen = lenVec[i];
		else maxLen = max(maxLen, lenVec[i]);
	}

	// left가 0일때 런타임 에러 DivisionByZero(0으로 나누면 에러) lenVec[i]/mid에서 mid가 0이 될 수 있음
	unsigned int left = 1, right = maxLen, mid = 0, total = 0, result = 0;
	while (left <= right)
	{
		total = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < K; ++i)
		{
			total += lenVec[i] / mid;
		}
		if (total >= N)
		{
			left = mid + 1;
			result = max(result, mid);		// N보다 크거나 작으면 mid가 결과값이거나 그보다 작음
		}
		else right = mid - 1;
	}

	cout << result;

	return 0;
}