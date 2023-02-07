//#include <iostream>
//#include <queue>
//using namespace std;
//
//int main()
//{
//	cin.tie(NULL);
//	cout.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//	int N, x;
//	cin >> N;
//
//	priority_queue<int> pq;
//
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> x;
//		if (x == 0)
//		{
//			if (pq.empty()) cout << 0 << '\n';
//			else
//			{
//				cout << pq.top() << '\n';
//				pq.pop();
//			}
//		}
//		else
//			pq.push(x);
//	}
//
//	return 0;
//}

#include <iostream>
using namespace std;

int vArr[100001];
int g_arrSize = 1;

void Swap(int _idx1, int _idx2)
{
	int iTemp = vArr[_idx1];
	vArr[_idx1] = vArr[_idx2];
	vArr[_idx2] = iTemp;
}

template <typename T>
void _Insert(T x)
{
	int index = g_arrSize;
	vArr[g_arrSize++] = x;

	while (index > 1)
	{
		if (vArr[index] > vArr[index / 2])
		{
			Swap(index, index / 2);
			index /= 2;
		}
		else break;
	}
}

template<typename T>
T _Top()
{
	return vArr[1];
}

void _Pop()
{
	if (g_arrSize == 1) return;

	int index = --g_arrSize;
	Swap(index, 1);
	vArr[index] = 0;
	index = 1;

	int ilastIndex = g_arrSize - 1;
	if (ilastIndex == 0) return;

	while (true)
	{
		int iLeft = index * 2, iRight = index * 2 + 1;
		if (iLeft > ilastIndex) break;
		else if (iLeft == ilastIndex)
		{
			if (vArr[iLeft] > vArr[index])
			{
				Swap(index, iLeft);
			}
			break;
		}
		else
		{
			if (vArr[iLeft] < vArr[iRight])
			{
				if (vArr[iRight] > vArr[index])
				{
					Swap(index, iRight);
					index = iRight;
				}
				else break;
			}
			else
			{
				if (vArr[iLeft] > vArr[index])
				{
					Swap(index, iLeft);
					index = iLeft;
				}
				else break;
			}
		}

	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, x;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> x;
		if (x == 0)
		{
			if (vArr[1] == 0) cout << 0 << '\n';
			else
			{
				cout << _Top<int>() << '\n';
				_Pop();
			}
		}
		else
			_Insert(x);
	}

	return 0;
}