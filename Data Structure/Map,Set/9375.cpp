#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T, n;
	cin >> T;
	string str1, str2;
	map<string, int> myMap;
	map<string, int>::iterator iter;
	while (T--)
	{
		int iTotal = 1;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> str1 >> str2;
			myMap[str2]++;
		}

		iter = myMap.begin();
		int iSize = myMap.size();
		for (; iter != myMap.end(); iter++)
		{
			iTotal *= (iter->second + 1);
		}
		myMap.clear();

		cout << --iTotal << '\n';
	}

	return 0;
}