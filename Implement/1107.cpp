#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int iArr[10];

bool Compare(int _iNum)
{
	int iTemp = 0;
	while (true)
	{
		iTemp = _iNum % 10;
		_iNum /= 10;

		if (iArr[iTemp]) return false;

		if (!_iNum) break;
	}

	return true;
}

int main()
{
	int N, M, iMin = 500000;
	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int iTemp;
		cin >> iTemp;
		iArr[iTemp] = 1;
	}

	string str = to_string(N);
	int size = str.size();
	iMin = abs(N - 100);
	if (10 == M || size >= iMin)
	{
		cout << iMin;
		return 0;
	}


	string sTemp = "";
	int iTemp = 0;
	for (int i = N; i < 1000000; ++i)
	{
		if (Compare(i))
		{
			sTemp = to_string(i);
			iTemp = i - N + sTemp.size();
			iMin = min(iMin, iTemp);
			break;
		}
	}
	for (int i = N - 1; i >= 0; --i)
	{
		if (Compare(i))
		{
			sTemp = to_string(i);
			iTemp = N - i + sTemp.size();
			iMin = min(iMin, iTemp);
			break;
		}
	}

	cout << iMin;

	return 0;
}