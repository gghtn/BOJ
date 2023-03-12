#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, x;
	cin >> N;

	vector<int> iArrOdd(501), iArrEven(501);
	cin >> iArrOdd[1];
	for (int i = 1; i < N; ++i)
	{
		if (i % 2 == 0)
		{
			for (int j = 1; j <= i + 1; ++j)
			{
				cin >> x;
				if (iArrEven[j - 1] < iArrEven[j])
				{
					iArrOdd[j] = x + iArrEven[j];
				}
				else
				{
					iArrOdd[j] = x + iArrEven[j - 1];
				}
			}
		}
		else
		{
			for (int j = 1; j <= i + 1; ++j)
			{
				cin >> x;
				if (iArrOdd[j - 1] < iArrOdd[j])
				{
					iArrEven[j] = x + iArrOdd[j];
				}
				else
				{
					iArrEven[j] = x + iArrOdd[j - 1];
				}
			}
		}
	}

	if (N % 2 == 0)
	{
		sort(iArrEven.begin(), iArrEven.end());
		cout << iArrEven[500];
	}
	else
	{
		sort(iArrOdd.begin(), iArrOdd.end());
		cout << iArrOdd[500];
	}

	return 0;
}