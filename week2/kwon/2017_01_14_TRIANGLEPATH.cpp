#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int ** input;
int ** result;
int n;

void TRIANGLEPATH(int row, int col)
{
	// �Ʒ����� �ϳ�
	if (result[row + 1][col] < result[row][col] + input[row + 1][col])
	{
		result[row + 1][col] = result[row][col] + input[row + 1][col];
	}
	// �Ʒ����� �ϳ�
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

		// input���� �迭�� �޸������̼� ���� �迭 �Ҵ� �� �ʱ�ȭ
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

		// �Է¹���
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				scanf("%d", &input[i][j]);
			}
		}
		// �迭 �࿭ ���鼭 ��
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