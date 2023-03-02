#include <iostream>
#include <set>
using namespace std;

// 진실을 아는 사람을 저장할 배열, 확인한 사람 번호, 확인한 파티
bool g_bArr[51], g_bVisit[51], g_bParty[51];
set<int> mySet[51];

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, iCnt, iNum, iMax = 0;
	cin >> N >> M;

	cin >> iCnt;
	for (int i = 0; i < iCnt; ++i)
	{
		cin >> iNum;
		g_bArr[iNum] = true;
	}

	for (int i = 1; i <= M; ++i)
	{
		cin >> iCnt;
		for (int j = 1; j <= iCnt; ++j)
		{
			cin >> iNum;
			mySet[i].insert(iNum);
		}
	}

	int resultArr[51] = {};
	bool bSearch = true;
	while (bSearch)
	{
		bSearch = false;
		for (int i = 1; i <= N; ++i)
		{
			if (g_bArr[i] && !g_bVisit[i])	// 진실을 아는 사람이면서 확인하지 않음
			{
				g_bVisit[i] = true;
				for (int j = 1; j <= M; ++j)
				{
					if (!g_bParty[j] && mySet[j].find(i) != mySet[j].end())	// 이미 확인한 파티가 아니면서 진실을 아는 사람을 포함한다면
					{
						g_bParty[j] = true;
						resultArr[j] = 1;
						set<int>::iterator iter = mySet[j].begin();
						for (; iter != mySet[j].end(); ++iter)
						{
							g_bArr[(*iter)] = true;
							bSearch = true;
						}
					}
				}
			}
		}
	}

	for (int i = 1; i <= M; ++i)
	{
		if (resultArr[i]) continue;
		++iMax;
	}
	cout << iMax;

	return 0;
}