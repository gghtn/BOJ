#include <iostream>
#include <string.h>
using namespace std;

char szStar[3072][6144];

void PrintStar(int _n, int _x, int _y)
{
	if (_n == 3)
	{
		szStar[_x][_y] = '*';
		szStar[_x + 1][_y - 1] = szStar[_x + 1][_y + 1] = '*';
		for (int i = -2; i < 3; ++i)
		{
			szStar[_x + 2][_y + i] = '*';
		}
		return;
	}

	PrintStar(_n / 2, _x, _y);
	PrintStar(_n / 2, _x + _n / 2, _y - _n / 2);
	PrintStar(_n / 2, _x + _n / 2, _y + _n / 2);
}

int main()
{
	int N;
	cin >> N;

	memset(szStar, ' ', sizeof(szStar));

	PrintStar(N, 0, N - 1);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 2 * N; ++j)
		{
			cout << szStar[i][j];
		}
		cout << '\n';
	}

	return 0;
}