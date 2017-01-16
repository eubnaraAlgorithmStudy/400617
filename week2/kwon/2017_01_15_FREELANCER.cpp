#include<stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int ** input;
int * result;
int n;

int Cal()
{
	int total = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		if (input[0][i] == input[1][i])
			result[i] = input[0][i];
		else
		{
			if (input[1][i] == max(input[0][i], input[1][i]))
			{
				result[i] = max(input[0][i], input[1][i]);
				--i;
			}
			else
				result[i] = max(input[0][i], input[1][i]);
		}
		
	}
	for (int i = 0; i < n; i++)
	{
		total += result[i];
	}

	return total;
}
int main(void)
{
	int T = 0;

	scanf("%d", &T);

	for(int i = 0; i < T; i++)
	{
		scanf("%d", &n);
		
		input = (int **)malloc(sizeof(int *) * 2);
		result = (int *)malloc(sizeof(int *) * n);
		
		for (int i = 0; i < 2; i++)
		{
			input[i] = (int *)malloc(sizeof(int) * n);
		}
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				input[i][j] = result[j] = 0;
			}
		}
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &input[i][j]);
			}
		}

		printf("Case #%d\n", T);
		printf("%d\n", Cal());

		free(input);
		free(result);
	}
	return 0;
}