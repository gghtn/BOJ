#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int iArr[1001][1001];

// 점화식 찾기

int main()
{
	string str1, str2;

	cin >> str1;
	cin >> str2;

	int len1 = str1.size(), len2 = str2.size();
	for (int i = 1; i <= len1; ++i)
	{
		for (int j = 1; j <= len2; ++j)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				iArr[i][j] = iArr[i - 1][j - 1] + 1;
			}
			else
			{
				iArr[i][j] = max(iArr[i - 1][j], iArr[i][j - 1]);
			}
		}
	}

	cout << iArr[len1][len2];
	return 0;
}