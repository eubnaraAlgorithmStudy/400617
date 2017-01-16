#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int ** input;
int ** result;
int n;

void TRIANGLEPATH(int row, int col)
{
	// 아래방향 하나
	if (result[row + 1][col] < result[row][col] + input[row + 1][col])
	{
		result[row + 1][col] = result[row][col] + input[row + 1][col];
	}
	// 아래우측 하나
	if (result[row + 1][col + 1] < result[row][col] + input[row + 1][col + 1])
	{
		result[row + 1][col + 1] = result[row][col] + input[row + 1][col + 1];
	}
}
int FINDMAX()
{
	int temp = 0;

	for (int i = 0; i < n - 1; i++)
	{
		if (temp <= max(result[n - 1][i], result[n - 1][i + 1]))
		{
			temp = max(result[n - 1][i], result[n - 1][i + 1]);
		}
	}
	return temp;
}
int main(void)
{
	int T = 0;

	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);

		// input위한 배열과 메모이제이션 위한 배열 할당 및 초기화
		input = (int **)malloc(sizeof(int *) * n);
		result = (int **)malloc(sizeof(int *) * n);
		for (int i = 0; i < n; i++)
		{
			input[i] = (int *)malloc(sizeof(int) * n);
			result[i] = (int *)malloc(sizeof(int) * n);
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				input[i][j] = result[i][j] = 0;
			}
		}

		// 입력받음
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				scanf("%d", &input[i][j]);
			}
		}
		// 배열 행열 돌면서 비교
		result[0][0] = input[0][0];
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				TRIANGLEPATH(i, j);
			}
		}

		printf("%d\n", FINDMAX());

		free(input);
		free(result);
	}

	return 0;
}