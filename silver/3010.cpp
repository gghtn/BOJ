#include <iostream>

using namespace std;

int main()
{
	int total = 0;
	char board[7][7] = { 0, };
	for (int i = 0; i < 7; i++)
	{

		cin.getline(board[i], '\n');
	}

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (board[i][j] == '.')
			{
				if (j < 5 && board[i][j + 1] == 'o' && board[i][j + 2] == 'o')
				{
					total++;
				}
				if (j > 1 && board[i][j - 1] == 'o' && board[i][j - 2] == 'o')
				{
					total++;
				}
				if (i < 5 && board[i + 1][j] == 'o' && board[i + 2][j] == 'o')
				{
					total++;
				}
				if (i > 1 && board[i - 1][j] == 'o' && board[i - 2][j] == 'o')
				{
					total++;
				}
			}
		}
	}

	cout << total;
	return 0;
}