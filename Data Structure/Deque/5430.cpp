#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T, n;
	cin >> T;
	string orderStr, str;

	while (T--)
	{
		cin >> orderStr >> n >> str;
		deque<int> dq;
		int iSize = str.size(), pos = 1;
		for (int i = 2; i < iSize; ++i)			// ¹®Àå¿­ ÆÄ½Ì
		{
			if (n == 1)
			{
				dq.push_back(stoi(str.substr(pos, iSize - pos + 1)));
				break;
			}
			if (str[i] == ',')
			{
				dq.push_back(stoi(str.substr(pos, i - pos)));
				pos = i + 1;
				--n;
			}
		}

		bool bError = false;
		int iDir = 1;
		iSize = orderStr.size();
		for (int i = 0; i < iSize; ++i)
		{
			if (orderStr[i] == 'R') iDir *= -1;
			else
			{
				if (dq.empty())
				{
					cout << "error\n";
					bError = true;
					break;
				}

				if (iDir == 1)
				{
					dq.pop_front();
				}
				else
				{
					dq.pop_back();

				}
			}
		}

		if (bError) continue;
		if (dq.empty())
		{
			cout << "[]\n";
			continue;
		}

		iSize = dq.size();
		deque<int>::iterator iter;
		if (iDir == 1) iter = dq.begin();
		else iter = dq.end();

		cout << '[';
		for (int i = 0; i < iSize; ++i)
		{
			if (iDir == 1)
			{
				cout << (*iter++);
			}
			else
			{
				cout << (*--iter);
			}

			if (i == iSize - 1) cout << "]\n";
			else cout << ',';
		}

		dq.clear();
	}

	return 0;
}