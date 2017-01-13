#include <iostream>
#include <cstdio>
using namespace std;

int max(int a, int b);

int max(int a, int b)
{
	if (a < b)
		return b;
	else
		return a;
}
//1.우선 숫자를 받음
//2.알고리즘 작성
/* 
	6							6
	1	2						7	8
	3	7	4					10	14와 15중 15가 크니까 15	12 이런식으로
	9	4	1	7
	2	7	5	9	4
*/
//그러면 위에가 행렬식으로 [i][j]에서 j가 1이면 무조건 위에것
//j랑 i가 같으면 무조건 같은것들 더하기
//아니면 만나는 두개중에 큰것
int main() {
	int TC;
	int test_case;
	int maxresult = 0;
	scanf("%d", &TC);	// cin 사용 가능
	for (test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.
		int n;
		scanf("%d", &n);
		int triangle[100][100];
		int total[100][100];
		for (int i = 0;i < n;i++)
		{
			for (int j =0;j <= i;j++)
			{
				scanf("%d", &triangle[i][j]);
			}
		}

		total[0][0] = triangle[0][0];
		for (int i = 1;i < n;i++)
		{
			for (int j = 0;j <= i;j++)
			{
				if (j ==0)
					total[i][0] = triangle[i][0] + total[i - 1][0];
				else if (i == j)
					total[i][j] = triangle[i][j] + total[i - 1][j - 1];
				else
					total[i][j] = triangle[i][j] + max(total[i - 1][j - 1], total[i - 1][j]);
			}
		}
		for (int i = 0;i < n;i++)
		{
			maxresult = max(maxresult, total[4][i]);
		}
		
		printf("%d", maxresult);
		printf("\n");
	}
	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}