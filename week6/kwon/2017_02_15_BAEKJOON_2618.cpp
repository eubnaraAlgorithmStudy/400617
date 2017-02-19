#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

int N;
int W;
queue<int> ANS; // 경찰차 호차 큐
vector<vector<int> > WAY; // 경찰차가 갈 수 있는 길
vector<vector<int> > POLICE; // 경찰차의 위치, col 별로 1,2호차를 의미
vector<vector<int> > XY; // 입력받는 좌표
int MIN;

void CAR()
{
	MIN = 0;
	for (int i = 0; i < W; i++)
	{
		int x = XY[0][i];
		int y = XY[1][i];
		int P1 = (abs(POLICE[0][0] - x) + abs(POLICE[1][0] - y));
		int P2 = (abs(POLICE[0][1] - x) + abs(POLICE[1][1] - y));
		// / 모양 대각선에서 우하향, 즉 2호차가 더 가까울경우
		if (P1 > P2)
		{
			ANS.push(2);
			MIN += P2;
			POLICE[0][1] = x;
			POLICE[1][1] = y;
		}
		else if(P1 < P2)
		{
			ANS.push(1);
			MIN += P1;
			POLICE[0][0] = x;
			POLICE[1][0] = y;
		}
		else // 거리가 같은경우 그 다음신호로,,,
		{
			if (i < (W - 1))
			{
				if (XY[0][i + 1] + XY[1][i + 1] < (N - 1))
				{
					ANS.push(1);
					MIN += P1;
					POLICE[0][0] = x;
					POLICE[1][0] = y;
				}
				else
				{
					ANS.push(2);
					MIN += P2;
					POLICE[0][1] = x;
					POLICE[1][1] = y;
				}
			}
			else
			{
				ANS.push(2);
				MIN += P2;
				POLICE[0][1] = x;
				POLICE[1][1] = y;
			}
		}
	}
}
int main(void)
{
	int a = 0;
	int b = 0;

	scanf("%d", &N);
	scanf("%d", &W);

	// 초기화
	WAY.clear();
	POLICE.clear();
	XY.clear();
	while (!ANS.empty()) ANS.pop();
	WAY.assign(N, vector<int>(N, 0)); //NxN 헹렬 0으로 초기화
	POLICE.assign(2, vector<int>(2, 0)); // 2,2 행렬
	XY.assign(2, vector<int>(3, 0));

	for (int i = 0; i < W; i++)
	{
		scanf("%d %d", &a, &b);
		XY[0][i] = a - 1;
		XY[1][i] = b - 1;
	} // 좌표입력

	POLICE[0][0] = 0;
	POLICE[1][0] = 0;
	POLICE[0][1] = N - 1;
	POLICE[1][1] = N - 1;

	CAR();

	printf("%d\n", MIN);
	while (!ANS.empty())
	{
		printf("%d\n", ANS.front());
		ANS.pop();
	}
	return 0;
}
/*
6
3
3 5
5 5
2 3

9
2
2
1
*/