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
	// ����, greedy algorithm�� ����, �տ��� ���� ���� ���� �͵��� ���ذ��� ���� �ּ��̴�.
}
int main(void)
{
	// ����
	scanf("%d", &N);
	input.resize(N);
	result.resize(N);

	//�ʱ�ȭ
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &input[i]);
	}

	// ����, greedy algorithm�� ����, �տ��� ���� ���� ���� �͵��� ���ذ��� ���� �ּ��̴�.
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