#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> v;
vector<int> numVec;
int N, num;

int search(int i, int j)
{
	++num;
	v[i][j] = '0';

	if (0 <= i - 1 && v[i - 1][j] == '1') search(i - 1, j);
	if (N - 1 >= i + 1 && v[i + 1][j] == '1') search(i + 1, j);
	if (0 <= j - 1 && v[i][j - 1] == '1') search(i, j - 1);
	if (N - 1 >= j + 1 && v[i][j + 1] == '1') search(i, j + 1);


	return num;
}

int main()
{
	int total = 0;
	cin >> N;
	v.resize(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (v[i][j] == '1')
			{
				numVec.push_back(search(i, j));
				++total;
				num = 0;
			}
		}
	}

	cout << total << endl;
	int size = numVec.size();
	sort(numVec.begin(), numVec.end());

	for (int i = 0; i < size; i++)
	{
		cout << numVec[i] << endl;
	}

	return 0;
}