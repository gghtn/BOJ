#include <iostream>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

vector<int> tmp, v;
int call, K;
void merge(vector<int>& v, int left, int mid, int right);
void merge_sort(vector<int>& v, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge_sort(v, left, mid);
		merge_sort(v, mid + 1, right);
		merge(v, left, mid, right);
	}
}

void merge(vector<int>& v, int left, int mid, int right)
{
	int i = left, j = mid + 1, t = 1;
	while (i <= mid && j <= right)
	{
		if (v[i] <= v[j])
			tmp[t++] = v[i++];
		else
			tmp[t++] = v[j++];
	}
	while (i <= mid)
		tmp[t++] = v[i++];
	while (j <= right)
		tmp[t++] = v[j++];
	i = left, t = 1;
	while (i <= right)
	{
		call++;
		if (call == K) cout << tmp[t];
		v[i++] = tmp[t++];
	}
}

int main()
{
	int N;
	cin >> N >> K;
	vector<int> v(N);
	tmp.resize(N + 1);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &v[i]);
	}

	merge_sort(v, 0, N - 1);

	if (call < K) cout << -1;
	return 0;
}