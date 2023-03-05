#include <iostream>
#include <vector>
using namespace std;

//const int INF = 123456789;

struct tEdge
{
	int from, to, cost;
};

bool Bellman_Ford(vector<tEdge>& v, int N)
{
	vector<int> vecDist(N + 1);
	vecDist[1] = 0;						// ������ ����

	for (int i = 0; i < N; ++i)
	{
		for (auto& edge : v)
		{
			int fr = edge.from, to = edge.to, cost = edge.cost;
			// fr�������� �ּ� ��� + fr->to������ ����� to���������� �ּҺ�뺸�� �� �۴ٸ� ����
			// ���� ���� ����� ������� Ư���� �� ���� �� ������ �˰����̴�.
			// �� ������ Ư���� �������� �������� �ʾ����Ƿ� ��ü ������ ���� �˰����� �����ؾ� �Ѵ�.
			// ������ �� ��� �ð� �ʰ��� ���ɼ��� ����. ��, �� ������ �䱸�� ���� ����Ŭ�� ���� �����̹Ƿ�
			// vecDist[fr] != INF ��, ���ŵ� �� �ִ��� Ȯ���� �ʿ䰡 ����.
			if (vecDist[fr] + cost < vecDist[to])
				vecDist[to] = vecDist[fr] + cost;
		}
	}

	// ���� ����Ŭ�� �����ϴ��� ����
	for (auto& edge : v)
	{
		int fr = edge.from, to = edge.to, cost = edge.cost;
		// ����� ���ŵȴٸ� ���� ����Ŭ ����
		if (vecDist[fr] + cost < vecDist[to])
			return true;
	}
	return false;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int TC;
	cin >> TC;
	vector<tEdge> vecGraph;
	while (TC--)
	{
		int N, M, W;
		int S, E, T;
		cin >> N >> M >> W;
		vecGraph = vector<tEdge>(M * 2 + W);
		for (int i = 0; i < M; ++i)
		{
			cin >> S >> E >> T;
			vecGraph[i] = { S, E, T };
			vecGraph[i + M] = { E, S, T };
		}
		for (int i = M * 2; i < M * 2 + W; ++i)
		{
			cin >> S >> E >> T;
			vecGraph[i] = { S, E, -T };
		}

		if (Bellman_Ford(vecGraph, N)) cout << "YES\n";
		else cout << "NO\n";
	}
}