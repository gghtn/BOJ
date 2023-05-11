#include "iostream"
#include "queue"
using namespace std;

bool bVisit[100001] = { 0, };

int Search(int _n, int _k)
{
	if (_n == _k) return 0;
	queue<pair<int, int>> myQueue;

	bVisit[_n] = true;
	myQueue.push({ 0, _n });

	int iNextPos = 0, iNextTime = 0;
	while (!myQueue.empty())
	{
		int iCurPos = myQueue.front().second;
		int iCurTime = myQueue.front().first;
		myQueue.pop();

		for (int i = 0; i < 3; ++i)
		{
			switch (i)
			{
			case 0:
				iNextPos = iCurPos * 2;
				iNextTime = iCurTime;
				break;

			case 1:
				iNextPos = iCurPos - 1;
				iNextTime = iCurTime + 1;
				break;

			case 2:
				iNextPos = iCurPos + 1;
				iNextTime = iCurTime + 1;
				break;
			}

			if (iNextPos == _k)
				return iNextTime;
			else
			{
				if (0 <= iNextPos && iNextPos <= 100000 && !bVisit[iNextPos])
				{
					bVisit[iNextPos] = true;
					myQueue.push({ iNextTime, iNextPos });
				}
			}
		}
	}
}



int main()
{
	int N, K;
	cin >> N >> K;

	cout << Search(N, K);

	return 0;
}