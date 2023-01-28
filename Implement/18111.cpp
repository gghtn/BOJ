#include <iostream>
#include <algorithm>

using namespace std;
// N���� M���� B�κ��丮 ����� ����
// �ּҽð��� ���ǳ��� ���
// ���� 2��, ���� 1��, �ּҽð��� �������� ���� ���̰� ���� ������ ���
int main()
{
	int N, M, B;
	cin >> N >> M >> B;

	int iArr[257] = { 0, }, iTemp = 0, iTime = INT32_MAX, iHeight = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> iTemp;
			++iArr[iTemp];
		}
	}

	for (int i = 0; i < 257; ++i)
	{
		int iBig = 0, iSmall = 0, iBlock = B, iTempTime = 0; // �����ؾ��� ���, �׾ƾ��� ���, ���� ������ �ִ� ���
		for (int j = 0; j < 257; ++j)
		{
			if (iArr[j])
			{
				if (j >= i)							// ���̸� i�� ���� ��� j > i�̸�  
				{
					iBig += iArr[j] * (j - i);		// ���̰� j�̰� i���� ���� ����� �� : iArr[j], i���� ��ĭ ������
				}
				else
				{
					iSmall += iArr[j] * (i - j);
				}
			}
		}

		iBlock += iBig;
		if (iBlock >= iSmall)
		{
			iTempTime += iBig * 2;
			iTempTime += iSmall;
			if (iTime >= iTempTime)
			{
				iTime = iTempTime;
				iHeight = i;
			}
		}
	}

	cout << iTime << ' ' << iHeight;
	return 0;
}