#include <iostream>
#include <vector>
using namespace std;

int N, S, total = 0;
vector<int> v(20);

void dfs(int index, int sum)
{
	if (index == N) return;
	if (v[index] + sum == S) total++;

	dfs(index + 1, sum);			// 현재 index값 포함x
	dfs(index + 1, v[index] + sum); // 현재 index값 포함
}

int main() {

	cin >> N >> S;

	for(int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	dfs(0, 0);

	cout << total;

	return 0;
}