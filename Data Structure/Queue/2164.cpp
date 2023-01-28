#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N;
	cin >> N;

	queue<int> q;

	for (int i = 1; i <= N; ++i)
		q.push(i);

	int iTemp = 0;
	while (true)
	{
		if (q.size() == 1) break;
		if (iTemp % 2 == 0) q.pop();
		else
		{
			q.push(q.front());
			q.pop();
		}
		++iTemp;
	}

	cout << q.front();


	return 0;
}