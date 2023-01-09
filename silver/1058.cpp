#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

vector<string> v(50);
char tmp[50];

int _search(string s, int num)
{
	int result = 0, size = s.size();

	for (int i = 0; i < size; i++)
	{
		if (s[i] == 'Y')
		{
			tmp[i] = 1;
			for (int j = 0; j < size; j++)
			{
				if (v[i][j] == 'Y') tmp[j] = 1;
			}
		}
	}
	tmp[num] = 0;

	for (int k = 0; k < size; k++)
	{
		if (tmp[k]) result++;
	}
	return result;
}

int main()
{
	int N, max_num = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < N; i++)
	{
		max_num = max(max_num, _search(v[i], i));
		memset(tmp, 0, N * sizeof(char));
		if (max_num == N - 1)
			break;
	}

	cout << max_num;
	return 0;
}