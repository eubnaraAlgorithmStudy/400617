#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

int N;
int W;
queue<int> ANS; // ������ ȣ�� ť
vector<vector<int> > WAY; // �������� �� �� �ִ� ��
vector<vector<int> > POLICE; // �������� ��ġ, col ���� 1,2ȣ���� �ǹ�
vector<vector<int> > XY; // �Է¹޴� ��ǥ
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
		// / ��� �밢������ ������, �� 2ȣ���� �� �������
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
		else // �Ÿ��� ������� �� ������ȣ��,,,
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

	// �ʱ�ȭ
	WAY.clear();
	POLICE.clear();
	XY.clear();
	while (!ANS.empty()) ANS.pop();
	WAY.assign(N, vector<int>(N, 0)); //NxN ��� 0���� �ʱ�ȭ
	POLICE.assign(2, vector<int>(2, 0)); // 2,2 ���
	XY.assign(2, vector<int>(3, 0));

	for (int i = 0; i < W; i++)
	{
		scanf("%d %d", &a, &b);
		XY[0][i] = a - 1;
		XY[1][i] = b - 1;
	} // ��ǥ�Է�

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