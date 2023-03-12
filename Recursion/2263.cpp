#include <iostream>
using namespace std;

int N;
int in[100001];
int post[100001];
int inRecord[100001];
/*
4 2 1 5 3 6 7
4 2 5 7 6 3 1

1 = root
// �� �κ�
in		-> ���� ~ root�� index - 1����
post	-> ���� ~ ���� + in�迭�� ����

// �� �κ�
in		-> root�� Index + 1 ~ ��
post	-> ���� ~ ���� + �� �κ� in�迭�� ����
*/

void Preorder(int _inStart, int _inEnd, int _postStart, int _postEnd)
{
	if (_inStart > _inEnd || _postStart > _postEnd) return;		// ���� �ε����� �� ũ�ٸ� return
	int root = post[_postEnd];
	cout << root << ' ';

	int idx = inRecord[root];

	int cnt = idx - _inStart;
	Preorder(_inStart, idx - 1, _postStart, _postStart + cnt - 1);
	Preorder(idx + 1, _inEnd, _postStart + cnt, _postEnd - 1);
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;


	for (int i = 1; i < N + 1; ++i)
	{
		cin >> in[i];
	}
	for (int i = 1; i < N + 1; ++i)
	{
		inRecord[in[i]] = i;		// �ε��� �� ����
	}

	for (int i = 1; i < N + 1; ++i)
	{
		cin >> post[i];
	}
	Preorder(1, N, 1, N);

	return 0;
}