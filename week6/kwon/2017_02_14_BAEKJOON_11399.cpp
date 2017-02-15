#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int temp;
vector<int> input;
vector<int> result;

void ATM()
{
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
		{
			result[i] = input[i];
		}
		else
		{
			result[i] = result[i - 1] + input[i];
		}
	}
	// 정렬, greedy algorithm에 의해, 앞에서 부터 가장 작은 것들을 더해가는 것이 최선이다.
}
int main(void)
{
	// 선언
	scanf("%d", &N);
	input.resize(N);
	result.resize(N);

	//초기화
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &input[i]);
	}

	// 정렬, greedy algorithm에 의해, 앞에서 부터 가장 작은 것들을 더해가는 것이 최선이다.
	sort(input.begin(), input.begin() + N);
	ATM();
	temp = 0;
	for (int i = 0; i < N; i++)
	{
		temp += result[i];
	}

	printf("%d", temp);
	return 0;
}