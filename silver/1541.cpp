#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int minNumber = 0;
	vector<int> numVec;
	vector<char> operVec;
	string str;
	cin >> str;

	int numStart = 0, size = str.length();
	for (int i = 0; i < size; i++)
	{
		if (str[i] == '-' || str[i] == '+')
		{
			numVec.push_back(stoi(str.substr(numStart, i - numStart)));
			operVec.push_back(str[i]);
			numStart = i + 1;
		}

		if (i == size - 1)
		{
			numVec.push_back(stoi(str.substr(numStart, size - numStart)));
		}
	}

	size = operVec.size();
	for (int i = 0, j = 0; i < size; i++, j++)
	{
		if (operVec[j] == '+')
		{
			numVec[j] += numVec[j + 1];
			numVec.erase(numVec.begin() + j + 1);
			operVec.erase(operVec.begin() + j);
			--j;
		}
	}

	size = numVec.size();
	minNumber = numVec[0];
	for (int i = 1; i < size; i++)
	{
		minNumber -= numVec[i];
	}

	cout << minNumber;
	return 0;
}