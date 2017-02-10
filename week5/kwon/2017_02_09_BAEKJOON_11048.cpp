#include <cstdio>
#include <algorithm>
#include <stdlib.h>

using namespace std;
int N;
int M;
int ** input;
long long ** result; // 동적위해..

void Cal()
{
	result[0][0] = input[0][0];
	for (register int i = 1; i < M; i++)
	{
		result[0][i] = input[0][i - 1] + input[0][i];
	}
	// result row 0 , 맨 윗줄은 길이 -- 이렇게 하나이므로 그냥 구해준다.
	
	for (register int i = 1; i < N; i++)
	{
		for (register int j = 0; j < M; j++)
		{
			if (j == 0)
			{
				result[i][0] = result[i - 1][0] + input[i][0];
			}
			else
			{
				result[i][j] = max((input[i][j] + result[i][j - 1]), (input[i][j] + result[i - 1][j]));
			}
		}
	}
	//result배열에는 최댓값만 저장한다 
}

int main(void)
{
	scanf("%d %d", &N, &M);

	input = (int **)malloc(sizeof(int *)* N);
	result = (long long **)malloc(sizeof(long long *)* N);
	
	for (register int i = 0; i < N; i++)
	{
		input[i] = (int *)malloc(sizeof(int)* M);
		result[i] = (long long *)malloc(sizeof(long long)* M);
	}
	// 배열 할당
	for (register int i = 0; i < N; i++)
	{
		for (register int j = 0; j < M; j++)
		{
			scanf("%d", &input[i][j]);
		}
	}
	// 초기화

	Cal();
	printf("%lld\n", result[N - 1][M - 1]);

	free(input);
	free(result);
	return 0;
}