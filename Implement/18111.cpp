#include <iostream>
#include <algorithm>

using namespace std;
// N세로 M가로 B인벤토리 블록의 개수
// 최소시간과 땅의높이 출력
// 제거 2초, 놓기 1초, 최소시간이 여러개면 땅의 높이가 제일 높은것 출력
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
		int iBig = 0, iSmall = 0, iBlock = B, iTempTime = 0; // 제거해야할 블록, 쌓아야할 블록, 현재 가지고 있는 블록
		for (int j = 0; j < 257; ++j)
		{
			if (iArr[j])
			{
				if (j >= i)							// 높이를 i로 맞출 경우 j > i이면  
				{
					iBig += iArr[j] * (j - i);		// 높이가 j이고 i보다 높은 블록의 수 : iArr[j], i보다 몇칸 높은지
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