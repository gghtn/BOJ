#include <iostream>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string str;
	stack<char> st;

	while (true)
	{
		getline(cin, str);
		int size = str.size();
		bool bBalance = true;

		if (size == 1)
		{
			break;
		}
		else
		{
			for (int i = 0; i < size; ++i)
			{
				if (str[i] == '(' || str[i] == '[' || str[i] == ')' || str[i] == ']')
				{
					if (str[i] == '(' || str[i] == '[')
						st.push(str[i]);
					else if (!st.empty())
					{
						if (st.top() == '(' && str[i] == ')') st.pop();
						else if (st.top() == '[' && str[i] == ']') st.pop();
						else
						{
							bBalance = false;
							break;
						}
					}
					else
					{
						bBalance = false;
						break;
					}
				}
			}

			if (bBalance && st.empty()) cout << "yes\n";
			else
			{

				st = stack<char>();
				cout << "no\n";
			}
		}

	}

	return 0;
}