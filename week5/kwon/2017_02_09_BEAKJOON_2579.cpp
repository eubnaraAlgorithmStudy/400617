#include <cstdio>
#include <algorithm>

using namespace std;

int T;
long long stair[301]; // 각 계단의 값 저장
long long temp[301]; // 계단을 오르면서 최대값을 저장

void dynamic(void) 
{
	for (int i = 0; i <= T; i++) 
	{
		if (i == 0) // 시작점 값은 0
			temp[i] = 0;
		else if (i == 1) // 첫번째 계단
			temp[i] = stair[i];
		else if (i == 2) // 두번째 계단
			temp[i] = max(stair[i - 1] + stair[i], temp[i - 2] + stair[i]);
		else // 3번째 계단
			temp[i] = max(temp[i - 3] + stair[i - 1] + stair[i], temp[i - 2] + stair[i]);
	}
}

int main(void) 
{
	scanf("%d", &T);

	for (int i = 1; i <= T; i++)
		scanf("%d", &stair[i]);

	dynamic();

	printf("%lld\n", temp[T]);

	return 0;
}
// 반복문의 변수는 register로 선언하면 빠름