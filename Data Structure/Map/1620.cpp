#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// ���� N, ����� �ϴ� ���� �� M
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	string str;
	map<string, int> m;
	vector<string> v(N + 1);

	for (int i = 1; i <= N; ++i)
	{
		cin >> str;
		v[i] = str;
		m[str] = i;
	}

	int iTemp = 0;
	map<string, int>::iterator itr;
	for (int i = 0; i < M; ++i)
	{
		cin >> str;
		if (9 >= str[0] - '0')
		{
			iTemp = stoi(str);
			cout << v[iTemp] << '\n';
			continue;
		}

		itr = m.find(str);
		cout << itr->second << '\n';

		//cout << m.at(str) << '\n'; 
		//cout << m[str] << '\n';
	}

	return 0;
}