#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];		// �������� �����ϴ� �迭
int arr_num[1001];	// index���� �ڿ� �� ū ���� � �ִ��� �����ϴ� �迭

int main()
{
	int N, length = 1, temp = 0, temp2 = 0, max_num = 1;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	fill(arr_num, arr_num + 1001, 1);

	for (int i = N - 2; 0 <= i; i--)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr_num[i] + arr_num[j];
				temp2 = max(temp2, temp);
			}
		}
		if (temp2 > 0) arr_num[i] = temp2;
		max_num = max(max_num, arr_num[i]);
		temp = 0, temp2 = 0;
	}

	cout << max_num;

	return 0;
}