#include <iostream>
#include <vector>
using namespace std;

int T, M, N, x, y;

void Search()
{
	int iCurX = 1, iCurY = 1, total = 1;
	vector<bool> v(N + 1);

	total += x - 1;
	iCurY += x - 1;
	if (N < iCurY) iCurY %= N;
	if (iCurY == 0) iCurY = N;

	while (true)
	{
		if (iCurY == y)
		{
			cout << total << '\n';
			return;
		}
		if (v[iCurY])
		{
			cout << "-1\n";
			return;
		}
		else
			v[iCurY] = true;

		total += M;
		iCurY += M;
		if (N < iCurY) iCurY %= N;
		if (iCurY == 0) iCurY = N;
	}

}

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> M >> N >> x >> y;

		if (M < x || N < y)
		{
			cout << "-1\n";
			continue;
		}
		Search();
	}


	return 0;
}