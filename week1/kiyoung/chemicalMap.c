/*
* [등차수열문제]
* 1. 등차수열인지 아닌지 : 앞 뒤를 뺀 값들의 배열에서, 가장 작은 수를 찾고, 그 수로 모든 배열에 나머지 연산을 통해 0임을 확인.
* 2. 등차수열이라면, min값을 2부터 나머지연산을 하면서 결과가 0 인 개수를 찾음.
* 정답형식을 잘못 만든건지, 결과값은 맞는데 제출을 틀림.
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
