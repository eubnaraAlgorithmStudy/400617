// Header files inclusion
#include <iostream>
#include <stdio.h>

using namespace std;

// Global variables declare
int height;
int width;
char board[20][20];

// Functions definition
int DFS()
{
	// Local variables declare
	int pass = 0;
	bool checker = true;
	int ret = 0;

	// Statement
	// 계속 경로 찾기위해
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (board[i][j] == '.')
			{
				checker = false;
			}
		}
	}

	if (checker)
		return 1;
	
	for (int i = 0; i < height - 1; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (board[i][j] == '.')
			{
				if (j != width)
				{
					if (board[i][j + 1] == '.' && board[i + 1][j] == '.')
					{
						board[i][j] = board[i][j + 1] = board[i + 1][j] = '#';
						ret += DFS();
						board[i][j] = board[i][j + 1] = board[i + 1][j] = '.';
						pass = 1;
					}
					if (board[i][j + 1] == '.' && board[i + 1][j + 1] == '.')
					{
						board[i][j] = board[i][j + 1] = board[i + 1][j + 1] = '#';
						ret += DFS();
						board[i][j] = board[i][j + 1] = board[i + 1][j + 1] = '.';
						pass = 1;
					}
					if (board[i + 1][j + 1] == '.' && board[i + 1][j] == '.')
					{
						board[i][j] = board[i + 1][j + 1] = board[i + 1][j] = '#';
						ret += DFS();
						board[i][j] = board[i + 1][j + 1] = board[i + 1][j] = '.';
						pass = 1;
					}
					if (j != 0)
					{
						if (board[i + 1][j - 1] == '.' && board[i + 1][j] == '.')
						{
							board[i][j] = board[i + 1][j - 1] = board[i + 1][j] = '#';
							ret += DFS();
							board[i][j] = board[i + 1][j - 1] = board[i + 1][j] = '.';
							pass = 1;
						}
					}
				}
				if (pass == 1)
					break;
			}
			if (pass == 1)
				break;
		}
			
	}
	return ret;
}
int main(void)
{
	// Local variables declare
	int T;

	// Statements
	scanf("%d", &T);
	//getchar();

	while (T--)
	{
		scanf("%d %d", &height, &width);

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				cin >> board[i][j];
				//board[i][j] = getchar();
			}
			//getchar();
		}
		printf("%d\n", DFS());
	}
	return 0;
}