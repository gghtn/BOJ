#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

priority_queue<int, vector<int>, greater<int>> positiveQueue;
priority_queue<int>  negativeQueue;
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, x;
	cin >> N;
	while (N--)
	{
		cin >> x;
		if (x == 0)
		{
			if (positiveQueue.empty() && negativeQueue.empty())
				cout << "0\n";
			else if (positiveQueue.empty())
			{
				cout << negativeQueue.top() << '\n';
				negativeQueue.pop();
			}
			else if (negativeQueue.empty())
			{
				cout << positiveQueue.top() << '\n';
				positiveQueue.pop();
			}
			else
			{
				if (abs(negativeQueue.top()) == abs(positiveQueue.top()))
				{
					cout << negativeQueue.top() << '\n';
					negativeQueue.pop();
				}
				else if (abs(negativeQueue.top()) < abs(positiveQueue.top()))
				{
					cout << negativeQueue.top() << '\n';
					negativeQueue.pop();
				}
				else
				{
					cout << positiveQueue.top() << '\n';
					positiveQueue.pop();
				}

			}
		}
		else if (x < 0)
		{
			negativeQueue.push(x);
		}
		else
		{
			positiveQueue.push(x);
		}
	}

	return 0;
}