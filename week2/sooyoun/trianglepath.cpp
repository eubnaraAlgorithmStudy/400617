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
//1.�켱 ���ڸ� ����
//2.�˰��� �ۼ�
/* 
	6							6
	1	2						7	8
	3	7	4					10	14�� 15�� 15�� ũ�ϱ� 15	12 �̷�������
	9	4	1	7
	2	7	5	9	4
*/
//�׷��� ������ ��Ľ����� [i][j]���� j�� 1�̸� ������ ������
//j�� i�� ������ ������ �����͵� ���ϱ�
//�ƴϸ� ������ �ΰ��߿� ū��
int main() {
	int TC;
	int test_case;
	int maxresult = 0;
	scanf("%d", &TC);	// cin ��� ����
	for (test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
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
	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}