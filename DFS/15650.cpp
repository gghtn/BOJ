#include "iostream"
using namespace std;

int N, M;
int arr[8];
bool bVisit[8];

void DFS(int _n, int _idx)
{
	if (M == _idx)
	{
		for (int i = 0; i < M; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = _n; i <= N; ++i)
	{
		if (bVisit[i]) continue;
		arr[_idx] = i;
		bVisit[i] = true;

		DFS(i + 1, _idx + 1);
		bVisit[i] = false;
	}
}

int main()
{
	cin >> N >> M;
	DFS(1, 0);


	return 0;
}