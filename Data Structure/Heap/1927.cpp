#include <iostream>
using namespace std;

int index, left, right;
int iArr[100001];

void Swap(int _idx1, int _idx2)
{
	int iTemp = iArr[_idx1];
	iArr[_idx1] = iArr[_idx2];
	iArr[_idx2] = iTemp;
}

void Insert(int _x)
{
	int curidx = index;
	iArr[index] = _x;

	while (curidx >= 1)
	{
		if (iArr[curidx / 2] > iArr[curidx])
		{
			Swap(curidx / 2, curidx);
			curidx /= 2;
		}
		else
			break;
	}
	++index;
}

void Delete()
{
	int curidx = index - 1, iTempIdx = 1;
	Swap(curidx, iTempIdx);
	cout << iArr[curidx] << '\n';
	iArr[curidx--] = 0;

	while (curidx > 1)
	{
		int left = iTempIdx * 2, right = iTempIdx * 2 + 1;

		if (left > curidx) break;
		else if (left == curidx)
		{
			if (iArr[left] < iArr[iTempIdx]) Swap(left, iTempIdx);
			break;
		}
		else
		{
			if (iArr[left] < iArr[right])
			{
				if (iArr[left] < iArr[iTempIdx])
				{
					Swap(left, iTempIdx);
					iTempIdx = left;
				}
				else break;
			}
			else
			{
				if (iArr[right] < iArr[iTempIdx])
				{
					Swap(right, iTempIdx);
					iTempIdx = right;
				}
				else break;
			}
		}
	}

	--index;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, x;
	cin >> N;

	index = 1;
	for (int i = 0; i < N; ++i)
	{
		cin >> x;
		if (x == 0)
		{
			if (iArr[1] == 0) cout << "0\n";
			else Delete();
		}
		else
		{
			Insert(x);
		}


	}
}

/*
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, x;
	cin >> N;
	priority_queue<int> pq;
	//priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; ++i)
	{
		cin >> x;
		if (x == 0)
		{
			if (pq.empty()) cout << "0\n";
			else
			{
				cout << (-1) * pq.top() << '\n';
				pq.pop();
			}
		}
		else
		{
			pq.push((-1) * x);
		}
	}

	return 0;
}
*/