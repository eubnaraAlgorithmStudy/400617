#include <cstdio>
#include <algorithm>

using namespace std;

int C;
int N;
int L;
double * arr;
double MIN; 
double sum = 0;
// 전역변수에서의 초기화는 좋지않다,,,,,
void CAL(int num)
{
	int count = 0;
	int num_temp = num;
	int i = 0;

	while (i <= ((N - 1) - (num_temp - 1)))
	{
		int j = i;
		while (count != num)
		{
			sum += arr[j++];
			count++;
		}
		double avg = sum / double(num);
		MIN = min(MIN, avg);
		sum = 0;
		count = 0;
		i++;
	}
}
int main(void)
{
	scanf("%d", &C);
	while (C--)
	{
		MIN = 100;
		scanf("%d %d", &N, &L);
		arr = new double[N];
		for (int i = 0; i < N; i++)
		{
			scanf("%lf", &arr[i]);
		}
		for (int i = L; i <= N; i++)
		{
 			CAL(i);
		}
		printf("%.12lf\n", MIN);
	}
	return 0;
}