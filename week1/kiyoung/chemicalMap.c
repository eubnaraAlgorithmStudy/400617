/*
* [������������]
* 1. ������������ �ƴ��� : �� �ڸ� �� ������ �迭����, ���� ���� ���� ã��, �� ���� ��� �迭�� ������ ������ ���� 0���� Ȯ��.
* 2. ���������̶��, min���� 2���� ������������ �ϸ鼭 ����� 0 �� ������ ã��.
* ���������� �߸� �������, ������� �´µ� ������ Ʋ��.
*/

#include<stdio.h>
int main()
{
	int T, L, N; //T : test case, L : Length, N : Number
	int i, j, k;
	int count = 1;
	int arr1[100 * 1000 + 10] = { 0, };
	int flag = 1;
	scanf("%d", &T);

	for (k = 0; k < T; k++)
	{
		int min = 9999;
		scanf("%d", &L);
		for (i = 0; i < L; i++)
		{
			scanf("%d", &arr1[i]);
		}

		for (j = 0; j < L - 1; j++)
		{
			arr1[j] = arr1[j + 1] - arr1[j];
		}

		for (i = 0; i < L - 1; i++)
		{
			if (arr1[i] != 1 && arr1[i] < min)
				min = arr1[i];
		}
		if (min != 0) {
			for (i = 0; i < L - 1; i++)
			{
				if (arr1[i] % min != 0)
				{
					flag = 0;
					break;
				}
			}
			if (flag != 0) {
				for (i = 2; i <= min; i++)
				{
					if (min%i == 0)
					{
						count++;
					}
				}
			}
		}

		else {
			for (int i = 0; i < L - 2; i++)
			{
				if (arr1[i + 1] - arr1[i] != 0)
				{
					count = 0;
					break;
				}
			}
		}

		printf("Case #%d\n", k + 1);
		printf("%d\n", count);
		count = 1;

	}

}
