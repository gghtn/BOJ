#include <iostream>
using namespace std;

long long Pow(long long a, long long b, long long c)
{
	long long result = 0;

	if (b == 0) return 1;
	if (b == 1) return a % c;

	long long half = Pow(a, b / 2, c);
	result = (half * half) % c;

	if (b % 2 == 1)
	{
		return (result * a) % c;
	}
	return result;
}

int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	cout << Pow(A, B, C);

	return 0;
}