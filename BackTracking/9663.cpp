#include <iostream>
using namespace std;

int N, Total;
int Col[15];

bool	Pruning(int _num)
{
	for (int i = 0; i < _num; ++i)
	{
		// ���� ���� ���
		if (Col[i] == Col[_num])
			return false;
		// ������ ���� ��ġ�� �밢���� �ִ� ���
		if (_num - i == Col[_num] - Col[i] || _num - i == Col[i] - Col[_num])
			return false;
	}

	return true;
}

void	Queen(int _num)
{
	if (_num == N)
	{
		++Total;
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		Col[_num] = i;
		if (Pruning(_num))
		{
			Queen(_num + 1);
		}
	}
}

int main()
{
	cin >> N;
	Queen(0);
	cout << Total;

	return 0;
}