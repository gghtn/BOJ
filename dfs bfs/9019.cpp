#include <iostream>
#include <string>
#include <string.h>
#include <queue>
using namespace std;

int A, B;
bool bVisit[10000];

void BFS()
{
	queue<pair<int, string>> myQueue;
	myQueue.push(make_pair(A, ""));
	bVisit[A] = true;

	pair<int, string> pairTemp;
	int iTemp;

	while (!myQueue.empty())
	{
		pairTemp = myQueue.front();
		myQueue.pop();

		iTemp = (2 * pairTemp.first) % 10000;
		if (iTemp == B)
		{
			cout << pairTemp.second + 'D' << '\n';
			return;
		}
		else if (!bVisit[iTemp])
		{
			myQueue.push(make_pair(iTemp, pairTemp.second + 'D'));
			bVisit[iTemp] = true;
		}

		iTemp = (pairTemp.first - 1 == -1) ? 9999 : pairTemp.first - 1;
		if (iTemp == B)
		{
			cout << pairTemp.second + 'S' << '\n';
			return;
		}
		else if (!bVisit[iTemp])
		{
			myQueue.push(make_pair(iTemp, pairTemp.second + 'S'));
			bVisit[iTemp] = true;
		}

		iTemp = (pairTemp.first % 1000) * 10 + pairTemp.first / 1000;
		if (iTemp == B)
		{
			cout << pairTemp.second + 'L' << '\n';
			return;
		}
		else if (!bVisit[iTemp])
		{
			myQueue.push(make_pair(iTemp, pairTemp.second + 'L'));
			bVisit[iTemp] = true;
		}

		iTemp = (pairTemp.first / 10) + 1000 * (pairTemp.first % 10);
		if (iTemp == B)
		{
			cout << pairTemp.second + 'R' << '\n';
			return;
		}
		else if (!bVisit[iTemp])
		{
			myQueue.push(make_pair(iTemp, pairTemp.second + 'R'));
			bVisit[iTemp] = true;
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--)
	{
		cin >> A >> B;
		BFS();
		memset(bVisit, 0, 10000);
	}


	return 0;
}