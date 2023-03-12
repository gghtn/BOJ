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
// 앞 부분
in		-> 시작 ~ root의 index - 1까지
post	-> 시작 ~ 시작 + in배열의 개수

// 뒷 부분
in		-> root의 Index + 1 ~ 끝
post	-> 시작 ~ 시작 + 앞 부분 in배열의 개수
*/

void Preorder(int _inStart, int _inEnd, int _postStart, int _postEnd)
{
	if (_inStart > _inEnd || _postStart > _postEnd) return;		// 시작 인덱스가 더 크다면 return
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
		inRecord[in[i]] = i;		// 인덱스 값 저장
	}

	for (int i = 1; i < N + 1; ++i)
	{
		cin >> post[i];
	}
	Preorder(1, N, 1, N);

	return 0;
}