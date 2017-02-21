#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct _INFO
{
	int distance;
	int numOfcar;
	char isVal;
}INFO;
int N;
int W;
vector<vector<int> > distanceInfo;
vector<vector<int> > way;
int Policecar[3][2];
int Policecar_prev[3][2];
INFO * result;
int MIN;
void Caldistance(int nth) // 각 경찰차의 위치에서 각 점 거리 계산
{
	for (int i = 1; i <= 2; i++)
	{
		for (int j = nth; j <= W; j++)
		{
			distanceInfo[i][j] = (abs(Policecar[i][0] - way[j][0]) + abs(Policecar[i][1] - way[j][1]));
		}
	} // distanceInfo 정보 채워줌... 경찰차에서 각 회차의 점까지 거리,,,,.,.,
}
void Initializer()
{
	scanf("%d", &N);
	scanf("%d", &W);
	way.clear();
	way.assign(W + 1, vector<int>(2, 0)); // 가야할 좌표 나타냄 2 X W +1 행렬, 1,2,3,,,,,n회차를 나타내기위해..,
	distanceInfo.clear();
	distanceInfo.assign(3, vector<int>(W + 1, 0)); // 3 X W+1행렬, row는 1호차 2호차를 나타내고 col은 순서. 
	// 좌표받는다.
	for (int i = 1; i <= W; i++)
	{
		scanf("%d %d", &way[i][0], &way[i][1]); 
	}
	// 경찰차 위치 초기화
	Policecar[0][0] = 0; Policecar[0][1] = 0; 
	Policecar[1][0] = 1; Policecar[1][1] = 1;
	Policecar[2][0] = N; Policecar[2][1] = N;
	// 거리정보 초기화
	Caldistance(1);
	result = new INFO[W + 1];
	result[0].distance = 0; result[0].numOfcar = 0; result[0].isVal = 'T';
	for (int i = 1; i <= W; i++)
	{
		result[i].isVal = 'T';
		result[i].distance = min(distanceInfo[1][i], distanceInfo[2][i]);
		if (result[i].distance == distanceInfo[1][i])
		{
			result[i].numOfcar = 1;
		}
		else
		{
			result[i].numOfcar = 2;
		}
	}

}
void dfs(int nth)
{
	if (nth > W)
		return; // 종료조건
	if (result[nth].isVal == 'F') // 경찰차 바꿔야해
	{
		// 바꾸기전 전단계로 완전히 되돌려야지..
		Policecar[result[nth].numOfcar][0] = Policecar_prev[result[nth].numOfcar][0];
		Policecar[result[nth].numOfcar][1] = Policecar_prev[result[nth].numOfcar][1];
		Caldistance(nth + 1);
		if (result[nth].distance == distanceInfo[1][nth])
		{
			result[nth].distance = distanceInfo[2][nth];
			result[nth].numOfcar = 2;
			result[nth].isVal = 'T';
		}
		else
		{
			result[nth].distance = distanceInfo[1][nth];
			result[nth].numOfcar = 1;
			result[nth].isVal = 'T';
		}
		Policecar[result[nth].numOfcar][0] = way[nth][0];// 경찰차 위치 갱신  
		Policecar[result[nth].numOfcar][1] = way[nth][1];
		Caldistance(nth + 1);
		dfs(nth + 1);
	}
	if (result[nth].distance <= min(distanceInfo[1][nth], distanceInfo[2][nth]) && result[nth].isVal == 'T')
	{
		if (distanceInfo[result[nth].numOfcar][nth] > result[nth].distance)
		{
			result[nth - 1].isVal = 'F';
			dfs(nth - 1);
		}
		Policecar_prev[result[nth].numOfcar][0] = Policecar[result[nth].numOfcar][0];
		Policecar_prev[result[nth].numOfcar][1] = Policecar[result[nth].numOfcar][1]; // 이동하기 이전 경찰차 바로 전 위치 갱신
		Policecar[result[nth].numOfcar][0] = way[nth][0];// 경찰차 위치 갱신  
		Policecar[result[nth].numOfcar][1] = way[nth][1];
		Caldistance(nth + 1); // 그 이후 거리 계산.
		dfs(nth + 1);
	}
	/*
	else
	{
		result[nth - 1].isVal = 'F';
		dfs(nth - 1);
	}
	*/
}
int main(void)
{
	// 초기화
	Initializer();
	dfs(1);
	for (int i = 1; i <= W; i++)
	{
		MIN += result[i].distance;
	}
	printf("%d\n", MIN);
	for (int i = 1; i <= W; i++)
	{
		printf("%d\n", result[i].numOfcar);
	}
	return 0;
}
/*
6
3
3 5
5 5
2 3

6
3
4 6
1 4
2 1

9
2
2
1

8
2
2
1
*/