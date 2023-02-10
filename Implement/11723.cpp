#include <iostream>
#include <string>
#include <vector>
using namespace std;

int iArr[21];

void Add(int _x)
{
	if (iArr[_x] == 0) iArr[_x] = _x;
}

void Remove(int _x)
{
	if (iArr[_x] != 0) iArr[_x] = 0;
}

void Check(int _x)
{
	if (iArr[_x] != 0) cout << "1\n";
	else cout << "0\n";
}

void Toggle(int _x)
{
	if (iArr[_x] != 0) iArr[_x] = 0;
	else iArr[_x] = _x;
}

void All()
{
	for (int i = 1; i <= 20; ++i)
	{
		iArr[i] = i;
	}
}

void Empty()
{
	for (int i = 1; i <= 20; ++i)
	{
		iArr[i] = 0;
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int M, iNum = 0;
	string str;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> str;

		if (str != "all" && str != "empty")
		{
			cin >> iNum;
			if (str == "add") Add(iNum);
			else if (str == "check") Check(iNum);
			else if (str == "remove") Remove(iNum);
			else Toggle(iNum);
		}
		else
		{
			if (str == "all") All();
			else Empty();
		}


	}

	return 0;
}