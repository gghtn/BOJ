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

	// left�� 0�϶� ��Ÿ�� ���� DivisionByZero(0���� ������ ����) lenVec[i]/mid���� mid�� 0�� �� �� ����
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
			result = max(result, mid);		// N���� ũ�ų� ������ mid�� ������̰ų� �׺��� ����
		}
		else right = mid - 1;
	}

	cout << result;

	return 0;
}