#include <iostream>
#include <algorithm>

using namespace std;

int MulFunc(int _iNum, int _iCount)
{
	int iReturn = 1;
	for (int i = 0; i < _iCount; ++i)
		iReturn *= _iNum--;

	return iReturn;
}

int main()
{
	int N, K;
	cin >> N >> K;

	int iDenominatorMax = max(N - K, K), iDenominatorMin = min(N - K, K);

	cout << MulFunc(N, N - iDenominatorMax) / MulFunc(iDenominatorMin, iDenominatorMin);

	return 0;
}