#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T = 0;
	int N = 0, M = 0, iTemp = 0;
	cin >> T;

	queue<int>	q;
	vector<int> v;

	while (T--)
	{
		cin >> N >> M;
		for (int i = 0; i < N; ++i)
		{
			cin >> iTemp;
			q.push(iTemp);
			v.push_back(iTemp);
		}
		sort(v.begin(), v.end());

		int iOrder = 1;

		while (true)
		{
			if (M == 0 && q.front() == v.back()) break;
			else if (M == 0)
			{
				M = q.size() - 1;
				q.push(q.front());
				q.pop();
			}
			else if (q.front() == v.back())
			{
				v.pop_back();
				q.pop();
				--M;
				++iOrder;
			}
			else
			{
				q.push(q.front());
				q.pop();
				--M;
			}
		}
		cout << iOrder << endl;
		v.clear();
		q = queue<int>();
	}

	return 0;
}