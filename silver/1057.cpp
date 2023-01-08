#include <iostream>

using namespace std;

int main()
{
	int N, jimin, hansu, round = 1;
	cin >> N >> jimin >> hansu;

	while ((jimin + 1) / 2 != (hansu + 1) / 2)
	{
		round++;
		jimin = (jimin + 1) / 2;
		hansu = (hansu + 1) / 2;
	}

	cout << round;
	return 0;
}