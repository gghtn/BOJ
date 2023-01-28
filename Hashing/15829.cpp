#include <iostream>
#include <cmath>

using namespace std;
#define M 1234567891;

int main()
{
	int L;

	char cAlph[51] = {};
	cin >> L >> cAlph;

	unsigned long long result = 0, r = 1;
	for (int i = 0; i < L; ++i)
	{
		result = (result + ((long long)cAlph[i] - 96) * r) % M;	// mod 분배법칙
		r = (r * 31) % M;
	}
	cout << result;
	return 0;
}