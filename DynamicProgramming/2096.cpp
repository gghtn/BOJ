#include <iostream>
#include <algorithm>
using namespace std;

struct stTemp
{
	int x, y, z;

	void operator=(const int(&_arr)[3])
	{
		x = _arr[0];
		y = _arr[1];
		z = _arr[2];
	}
};

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, x, y, z;
	int iMinArr[3] = {}, iMaxArr[3] = {};
	cin >> N;

	stTemp temp;
	for (int i = 0; i < N; ++i)
	{
		cin >> x >> y >> z;
		temp = iMaxArr;
		iMaxArr[0] = x + max(temp.x, temp.y);
		iMaxArr[1] = y + max({ temp.x, temp.y, temp.z });
		iMaxArr[2] = z + max(temp.y, temp.z);

		temp = iMinArr;
		iMinArr[0] = x + min(temp.x, temp.y);
		iMinArr[1] = y + min({ temp.x, temp.y, temp.z });
		iMinArr[2] = z + min(temp.y, temp.z);
	}

	cout << max({ iMaxArr[0], iMaxArr[1], iMaxArr[2] }) << ' ';
	cout << min({ iMinArr[0], iMinArr[1], iMinArr[2] });

	return 0;
}