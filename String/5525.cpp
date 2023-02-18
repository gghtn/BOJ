#include <iostream>
#include <string>
#include <vector>
using namespace std;

string S;

int main()
{
	int N, M, total = 0;

	vector<int> v;
	cin >> N >> M >> S;


	for (int i = 0; i < M; ++i)
	{
		if (S[i] == 'I')
		{
			int iNum = 0;
			while (true)
			{
				if (S[++i] != 'O' || S[++i] != 'I')
				{
					--i;
					break;
				}
				++iNum;
			}
			if (iNum) v.push_back(iNum);
		}
	}

	int iSize = v.size();
	for (int i = 0; i < iSize; ++i)
	{
		if (0 < v[i] + 1 - N) total += v[i] + 1 - N;
	}

	cout << total;

	return 0;
}