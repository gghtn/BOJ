#include <iostream>
#include <vector>
using namespace std;

vector<long long> v{ 1,1,1,2,2 };

long long Padovan(int _n)
{
	if (6 > _n) return v[_n - 1];
	if (v.size() + 1 < _n)
	{
		while (v.size() + 1 != _n)
		{
			int iSize = v.size();
			v.push_back(v[iSize - 1] + v[iSize - 5]);
		}
	}
	return v[_n - 2] + v[_n - 6];
}

int main()
{
	int T, N;
	cin >> T;

	while (T--)
	{
		cin >> N;
		cout << Padovan(N) << '\n';
	}

	return 0;
}