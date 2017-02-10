#include <cstdio>
#include <algorithm>

using namespace std;

int T;
long long stair[301]; 
long long temp[301]; // 동적계산위해 

void dynamic(void) 
{
	for (int i = 0; i <= T; i++) 
	{
		// 패턴에서 착안   
		if (i == 0)
			temp[i] = 0;
		else if (i == 1) 
			temp[i] = stair[i];
		else if (i == 2) 
			temp[i] = max(stair[i - 1] + stair[i], temp[i - 2] + stair[i]);
		else 
			temp[i] = max(temp[i - 3] + stair[i - 1] + stair[i], temp[i - 2] + stair[i]); // 더해지는 패턴  
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
