/*
	�����Ʈ:
	- ���������� �ʱ�ȭ�� �� ������ ��
	- �����迭�� �ʱ�ȭ�� �� �κ������θ� �ʱ�ȭ���� �ʾҴ��� ������ ��(memset()�Լ��� �̿��ϴ� ��� Ư�� ����)

*/




#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

int areFriends[MAX][MAX];	//���� ģ������ ����ϴ� �迭
int taken[MAX];	//¦�� ���������� ����ϴ� �迭
int makeTeam(int n);
int main(void) {
	int T,n,m;
	scanf("%d", &T);
	while (T--) {
		//n: �л��� �� 2 <= n <= 10
		//m: ģ�� ���� �� 0 <= m <= n*(n-1)/2
		scanf("%d %d", &n, &m);
		//n*n���̸�ŭ�� �ʱ�ȭ�ϸ� �� ��! MAX*MAX �迭�̶�� ���� �ָ�, ����!!!!!
		//memset(areFriends, 0, sizeof(int)*n*n);
		memset(areFriends, 0, sizeof(int)*MAX*MAX);
		memset(taken, 0, sizeof(int)*n);
		for (int i = 0; i < m; i++){
			int p1, p2;//person1 person2
			scanf("%d %d", &p1, &p2);
			areFriends[p1][p2] = 1;
			areFriends[p2][p1] = 1;
		}
		printf("%d\n", makeTeam(n));
	}
	return 0;
}
/*
	¦�� �����, ������� �� �ִ� ����� ���� ��ȯ

	Argument
	taken[] : ¦�� ���������� ����ϴ� �迭
	n : �� �ο��� ��
*/
int makeTeam(int n) {
	int person = -1;
	//���� �� ��ȣ�� ���� ���� ����� �ϳ� �߷�����.
	for (int i = 0; i < n; i++) {
		if (!taken[i])
		{
			person = i;
			break;
		}
	}
	//��� ¦������ ���
	if (person == -1){
		return 1;
	}
		

	taken[person] = 1;
	int ret = 0;
	for (int i = person + 1; i < n; i++) {
		//�� �κп��� �Ǽ� �߾���. || taken[i]�� ���Ծ�����.
		//�ϴ� ģ������ Ȯ�ε� �ؾ��ϸ�, �̹� ¦�� ������ ����� ���ܽ��Ѿ� �Ѵ�.
		if ((!areFriends[person][i]) || taken[i])
			continue;
		else {
			taken[i] = 1;
			ret += makeTeam(n);
			taken[i] = 0;
		}
	}
	taken[person] = 0;
	return ret;
}