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
void Caldistance(int nth) // �� �������� ��ġ���� �� �� �Ÿ� ���
{
	for (int i = 1; i <= 2; i++)
	{
		for (int j = nth; j <= W; j++)
		{
			distanceInfo[i][j] = (abs(Policecar[i][0] - way[j][0]) + abs(Policecar[i][1] - way[j][1]));
		}
	} // distanceInfo ���� ä����... ���������� �� ȸ���� ������ �Ÿ�,,,,.,.,
}
void Initializer()
{
	scanf("%d", &N);
	scanf("%d", &W);
	way.clear();
	way.assign(W + 1, vector<int>(2, 0)); // ������ ��ǥ ��Ÿ�� 2 X W +1 ���, 1,2,3,,,,,nȸ���� ��Ÿ��������..,
	distanceInfo.clear();
	distanceInfo.assign(3, vector<int>(W + 1, 0)); // 3 X W+1���, row�� 1ȣ�� 2ȣ���� ��Ÿ���� col�� ����. 
	// ��ǥ�޴´�.
	for (int i = 1; i <= W; i++)
	{
		scanf("%d %d", &way[i][0], &way[i][1]); 
	}
	// ������ ��ġ �ʱ�ȭ
	Policecar[0][0] = 0; Policecar[0][1] = 0; 
	Policecar[1][0] = 1; Policecar[1][1] = 1;
	Policecar[2][0] = N; Policecar[2][1] = N;
	// �Ÿ����� �ʱ�ȭ
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
		return; // ��������
	if (result[nth].isVal == 'F') // ������ �ٲ����
	{
		// �ٲٱ��� ���ܰ�� ������ �ǵ�������..
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
		Policecar[result[nth].numOfcar][0] = way[nth][0];// ������ ��ġ ����  
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
		Policecar_prev[result[nth].numOfcar][1] = Policecar[result[nth].numOfcar][1]; // �̵��ϱ� ���� ������ �ٷ� �� ��ġ ����
		Policecar[result[nth].numOfcar][0] = way[nth][0];// ������ ��ġ ����  
		Policecar[result[nth].numOfcar][1] = way[nth][1];
		Caldistance(nth + 1); // �� ���� �Ÿ� ���.
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
	// �ʱ�ȭ
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