#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

struct vertex
{
	int		start;		// ó�� ��
	int		end;		// ���� ��

	void swap()
	{
		int tmp = 0;
		tmp = start;
		start = end;
		end = tmp;
	}
};

vector<vertex> v;
queue<int> q;
int N, M, V, arr[1001];

bool compare(vertex& a, vertex& b)
{
	if (a.start == b.start) return a.end < b.end;
	return a.start < b.start;
}

void _DFS(int num)
{
	if (!arr[num])
	{
		arr[num] = 1;
		cout << num << ' ';
	}
	else return;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].start == num || v[i].end == num)
		{
			if (v[i].start == num) _DFS(v[i].end);
			else _DFS(v[i].start);
		}
	}
}

void _BFS(int num)
{
	int temp = 0;
	q.push(num);

	while (!q.empty())
	{
		temp = q.front();
		if (!arr[temp])
		{
			arr[temp] = 1;
			cout << temp << ' ';
		}
		q.pop();
		for (int i = 0; i < v.size(); i++)
		{
			if ((v[i].start == temp && !arr[v[i].end]) || (v[i].end == temp && !arr[v[i].start]))
			{
				if (v[i].start == temp) q.push(v[i].end);
				else  q.push(v[i].start);
			}
		}
	}
}

int main()
{
	cin >> N >> M >> V;
	v.resize(M);		// ������ ����ŭ v�� ������ ����

	for (int i = 0; i < M; i++)
	{
		cin >> v[i].start >> v[i].end;
		if (v[i].start > v[i].end) v[i].swap();	// ������̹Ƿ� ������ �߿����� �ʱ� ������ ���� ������ ����
	}
	sort(v.begin(), v.end(), compare);

	_DFS(V);
	cout << '\n';
	memset(arr, 0, sizeof(int) * 1001);		// ����ߴ��� Ȯ���ϴ� �迭 �ʱ�ȭ

	_BFS(V);

	return 0;
}