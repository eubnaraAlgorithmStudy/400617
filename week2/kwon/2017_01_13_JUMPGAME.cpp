#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define MAX 100
// Global variables declare
int n;
int ** arr;
int NAK[MAX][MAX];
int ret;

// Functions definition
int DFS_DYNAMIC(int row, int col)
{
	// Local variables declare
	int scope = 0;

	scope = arr[row][col];

	if ((row == (n - 1)) && (col == (n - 1)))
		return 1;
	// ��������� �� ���� ������ �Ǵ� �Ʒ�����Ž����, �Ʒ�->������
	if ((row + scope <= n - 1) && (NAK[row][col] < 2))
	{
		ret += DFS_DYNAMIC(row + scope, col); // �Ʒ��� �� �� ���� ��
		NAK[row][col]++;
	}
	if ((col + scope <= n - 1) && (NAK[row][col] < 2))
	{
		ret += DFS_DYNAMIC(row, col + scope);
		NAK[row][col]++;
	}
	
	return 0;
}
int main(void)
{
	int T = 0;
	scanf("%d", &T);

	while (T--)
	{
		// n�� �ް�
		scanf("%d", &n);
		ret = 0;

		// NAK �ʱ�ȭ
		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				NAK[i][j] = 0;
			}
		}

		// ������ �迭 �����
		arr = (int**)malloc(sizeof(int *) * n);
		for (int i = 0; i < n; i++)
		{
			*(arr + i) = (int*)malloc(sizeof(int) * n);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", (*(arr + i) + j));
			}
		}
		DFS_DYNAMIC(0, 0);
		if (ret > 0)
			printf("YES\n");
		else
			printf("NO\n");
	}

	free(arr);
	return 0;
}