#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	set<string> mySet;
	vector<string> strArr;
	string str;

	for (int i = 0; i < N; ++i)
	{
		cin >> str;
		mySet.insert(str);
	}

	int total = 0;
	for (int i = 0; i < M; ++i)
	{
		cin >> str;
		if (mySet.end() != mySet.find(str))
		{
			++total;
			strArr.push_back(str);
		}
	}

	int size = strArr.size();
	sort(strArr.begin(), strArr.end());
	cout << total << '\n';
	for (int i = 0; i < size; ++i)
	{
		cout << strArr[i] << '\n';
	}
	return 0;
}
