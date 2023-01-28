#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	queue<int> q;

	for (int i = 1; i <= N; ++i)
		q.push(i);

	cout << '<';
	int index = K;
	while (true)
	{
		if (index == 1)
		{
			cout << q.front();
			q.pop();
			index = K;
			if (q.empty()) break;
			cout << ", ";
		}
		else
		{
			q.push(q.front());
			q.pop();
			--index;
		}
	}

	cout << '>';

	return 0;
}