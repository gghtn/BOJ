#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
string szArr[101][101];

void StringSum(string _s1, string _s2, int _n, int _m)
{
	char szTemp[100] = {};
	int size1 = _s1.size();
	int size2 = _s2.size();

	int size = max(size1, size2);
	bool bUp = false;

	int iTemp;
	for (int i = 0; i < size; ++i)
	{
		if (size1 <= i)
		{
			iTemp = _s2[i] - '0';
		}
		else if (size2 <= i)
		{
			iTemp = _s1[i] - '0';
		}
		else
		{
			iTemp = (_s1[i] - '0') + (_s2[i] - '0');
		}

		if (bUp) iTemp += 1;

		if (iTemp / 10 > 0) bUp = true;
		else bUp = false;

		szTemp[i] = iTemp % 10 + '0';
	}

	if (bUp) szTemp[size] = '1';

	szArr[_n][_m] = szTemp;
}

string Combination(int _n, int _m)
{
	if (_n == _m || _m == 0) szArr[_n][_m] = "1";

	if (szArr[_n][_m] != "")
	{
		return szArr[_n][_m];
	}

	StringSum(Combination(_n - 1, _m - 1), Combination(_n - 1, _m), _n, _m);
	return szArr[_n][_m];
}

int main()
{
	cin >> n >> m;

	string result = Combination(n, m);
	reverse(result.begin(), result.end());
	cout << result;

	return 0;
}