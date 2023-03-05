#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

const long long INF = LLONG_MAX;

vector<long long> vecDist;

struct tEdge
{
	int from, to, cost;
};

bool Bellman_Ford(vector<tEdge>& v, int N)
{
	vecDist[1] = 0;	// ������ ����

	for (int i = 0; i < N; ++i)		// N - 1�� ����
	{
		for (const auto& edge : v)
		{
			// ���� ����(from)�� ���ŵ� ���� �����鼭(INF�� �ƴϸ鼭) ���� �������� �ּҺ�� + from->to ����� ������ ����(to)�� �ּҺ�뺸�� ������ ����
			if (vecDist[edge.from] != INF && vecDist[edge.from] + edge.cost < vecDist[edge.to])
			{
				vecDist[edge.to] = vecDist[edge.from] + edge.cost;
			}
		}
	}

	// ���� ����Ŭ ���� ���� Ȯ��
	for (const auto& edge : v)
	{
		// ���� �ȴٸ� ���� ����Ŭ�� ����
		if (vecDist[edge.from] != INF && vecDist[edge.from] + edge.cost < vecDist[edge.to])
		{
			return true;
		}
	}

	return false;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	int A, B, C;
	cin >> N >> M;

	vector<tEdge> vecGraph(M);
	vecDist.resize(N + 1, INF);

	for (int i = 0; i < M; ++i)
	{
		cin >> A >> B >> C;
		vecGraph[i] = { A, B, C };
	}

	if (Bellman_Ford(vecGraph, N)) cout << -1;
	else
	{
		for (int i = 2; i <= N; ++i)
		{
			if (vecDist[i] == INF) cout << "-1\n";
			else cout << vecDist[i] << '\n';
		}
	}

	return 0;
}