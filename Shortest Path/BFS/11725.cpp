#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 100001
vector<int> graph[MAX];
int ans[MAX];
bool bVisit[MAX];

void BFS()
{
	queue<int> q;
	q.push(1);

	while (!q.empty())
	{
		int iCur = q.front();
		bVisit[iCur] = true;
		q.pop();

		for (int i = 0; i < graph[iCur].size(); ++i)
		{
			if (!bVisit[graph[iCur][i]])
			{
				q.push(graph[iCur][i]);
				ans[graph[iCur][i]] = iCur;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	int a, b;
	cin >> N;

	for (int i = 0; i < N - 1; ++i)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	BFS();

	for (int i = 2; i < N + 1; ++i)
	{
		cout << ans[i] << '\n';
	}

	return 0;
}
