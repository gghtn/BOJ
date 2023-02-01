#include <iostream>
#include <queue>

using namespace std;

int visit[100001] = { 0, };

int Search(int _n, int _k)
{
	int iReturn = 0;
	queue<int> q;
	q.push(_n);

	if (_n == _k) return 0;

	while (!q.empty())
	{
		int iTemp = q.front();
		q.pop();

		for (int i = 0; i < 3; ++i)
		{
			switch (i)
			{
			case 0:
				_n = iTemp * 2;
				break;
			case 1:
				_n = iTemp + 1;
				break;
			case 2:
				_n = iTemp - 1;
				break;
			default:
				break;
			}
			if (_n == _k)
			{
				return visit[iTemp] + 1;
			}
			if (0 < _n && _n <= 100000 && !visit[_n])
			{
				q.push(_n);
				visit[_n] = visit[iTemp] + 1;
			}
		}
	}
}

int main()
{
	int N, K;
	cin >> N >> K;

	cout << Search(N, K);
}