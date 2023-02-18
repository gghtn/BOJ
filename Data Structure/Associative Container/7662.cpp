#include <iostream>
#include <set>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T, k;
	cin >> T;

	multiset<int> mS;

	int iTemp;
	char cTemp;
	while (T--)
	{
		cin >> k;
		for (int i = 0; i < k; ++i)
		{
			cin >> cTemp >> iTemp;

			if (cTemp == 'I') mS.insert(iTemp);
			else
			{
				if (!mS.empty())
				{
					if (iTemp == 1)
					{
						if (mS.size() > 1)
							mS.erase(--mS.end());
						else
							mS.erase(mS.begin());
					}
					else
					{
						mS.erase(mS.begin());
					}
				}
			}
		}
		if (mS.empty()) cout << "EMPTY\n";
		else if (mS.size() == 1) cout << *mS.begin() << ' ' << *mS.begin() << '\n';
		else cout << *(--mS.end()) << ' ' << *mS.begin() << '\n';

		mS.clear();
	}

	return 0;
}