#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int iArr[100][100];
int N;

void floyd()
{
	for (int k = 0; k < N; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				iArr[i][j] = min(iArr[i][j], iArr[i][k] + iArr[k][j]);
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> iArr[i][j];
			if (!iArr[i][j]) iArr[i][j] = 1000;
		}
	}
	floyd();

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (iArr[i][j] == 1000) cout << "0 ";
			else cout << "1 ";
		}
		cout << '\n';
	}

	return 0;
}