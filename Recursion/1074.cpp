#include <iostream>
#include <cmath>

using namespace std;

int ZFunc(int _N, int _r, int _c)
{
	int iReturn = 0;
	if (_r == 0 && _c == 0) return iReturn;

	int iBlock = pow(pow(2, _N), 2) / 4, iTemp = pow(2, _N) / 2;

	if (_r >= iTemp)
	{
		iReturn += iBlock * 2;
		_r -= pow(2, _N - 1);
	}
	if (_c >= iTemp)
	{
		iReturn += iBlock;
		_c -= pow(2, _N - 1);
	}
	iReturn += ZFunc(_N - 1, _r, _c);

	return iReturn;
}

int main()
{
	int N, r, c;
	cin >> N >> r >> c;

	cout << ZFunc(N, r, c);

	return 0;
}