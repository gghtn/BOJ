#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void Compare(string _str)
{
	string strTemp = _str;
	char cTemp = ' ';
	int size = _str.size() / 2, index = _str.size() - 1;
	for (int i = 0; i < size; ++i)
	{
		cTemp = _str[index];
		_str[index] = _str[i];
		_str[i] = cTemp;
		--index;
	}
	if (!strcmp(_str.c_str(), strTemp.c_str())) cout << "yes\n";
	else cout << "no\n";
}

int main()
{
	string str;

	while (true)
	{
		cin >> str;
		if (stoi(str) == 0) break;
		Compare(str);
	}


	return 0;
}