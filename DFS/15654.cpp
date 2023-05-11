#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int arr[8];
bool bVisit[8];
vector<int> vec;

void DFS(int _vecIdx, int _idx)
{
	if (_idx == M)
	{
		for (int i = 0; i < M; ++i)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (bVisit[i]) continue;
		bVisit[i] = true;
		arr[_idx] = vec[i];

		DFS(i + 1, _idx + 1);
		bVisit[i] = false;
	}
}

int main()
{
	int n;
	cin >> N >> M;
	vec.resize(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());

	DFS(0, 0);

	return 0;
}