#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	string key, value;
	cin >> N >> M;

	unordered_map<string, string> myMap;

	while (N--)
	{
		cin >> key >> value;
		myMap[key] = value;
	}

	while (M--)
	{
		cin >> key;
		cout << myMap[key] << '\n';
	}

	return 0;
}