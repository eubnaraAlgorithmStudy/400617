#include <cstdio>
#include <algorithm>

using namespace std;

int T;
long long stair[301]; // �� ����� �� ����
long long temp[301]; // ����� �����鼭 �ִ밪�� ����

void dynamic(void) 
{
	for (int i = 0; i <= T; i++) 
	{
		if (i == 0) // ������ ���� 0
			temp[i] = 0;
		else if (i == 1) // ù��° ���
			temp[i] = stair[i];
		else if (i == 2) // �ι�° ���
			temp[i] = max(stair[i - 1] + stair[i], temp[i - 2] + stair[i]);
		else // 3��° ���
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
// �ݺ����� ������ register�� �����ϸ� ����