/*
	�����Ʈ:
	- ���������� �׻� �׽�Ʈ���̽����� �ʱ�ȭ�� �� �ǰ� �ִ��� Ȯ������.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define MAX 25
/*
	���� ��ܺ��� �� ���¸� ä������ ��, ȸ�����Ѽ� ä�� �� �ִ� ����� ��Ÿ����.
	�� 4���� ��찡 �ִ�. ��, ���� �¿����, ��, ���� �¿����
*/
const int shapes[4][2][2] = {
	{ { 0, 1 }, { 1, 0 } },
	{ { 0, 1 }, { 1, 1 } },
	{ { 1, 0 }, { 1, 1 } },
	{ { 1, 0 }, { 1, -1 } }
};
//���ó���� �����ϰ� �ϱ� ���Ͽ� �ε����� 1���� �����ϴ� ������ �ϸ�,
//���������� �⺻������ 0���� ä������ �Ϳ� �����Ͽ� 0���� ���� ĭ, 1���� �� ĭ�� ��Ÿ������ �Ѵ�.
int map[MAX][MAX];
//����, ���α���
int H, W;
//������� ä���� �� ĭ�� ��
int curWhites;

//4������ ��� �߿� �ϳ��� ������, �� ����� ���� �� �ִ��� ��,������ ��ȯ
//���ڸ��� �翬�� �� ĭ �̾���ϴ� ��������
int canCover(const int shape[2][2],int x, int y);
//map�� ��� ä�� �� �ִ� ����� ���� ��ȯ
int cover(int x, int y);
void paint(const int shape[2][2], int x, int y);
void unpaint(const int shape[2][2], int x, int y);

int main(void) {
	int T;	//testcase�� ��

	scanf("%d", &T);
	while (T--) {
		//�ʱ�ȭ
		memset(map, 0, sizeof(int)*MAX*MAX);	//ERROR: �� �κ��� ���Ծ ������ �¾���.
		H = 0;
		W = 0;
		curWhites = 0;
		scanf("%d %d", &H, &W);
		for (int i = 1; i <= H; i++){
			for (int j = 1; j <= W; j++){
				char tmp;
				while (1) {
					tmp = getchar();
					if ('\n' == tmp || ' ' == tmp)
						continue;
					else
						break;
				}
				
				if ('#' == tmp)
					map[i][j] = 0;
				else if ('.' == tmp) {
					map[i][j] = 1;
					curWhites++;
				}
				else
				{
					printf("%c: input error\n",tmp);
					exit(-1);
				}
			}
		}

		//ä���� �ϴ� �� ĭ�� ������ 3�� ����� �ƴ϶�� ä�� �� �ִ� ����� ���� 0
		if (curWhites % 3 != 0){
			printf("0\n");
			continue;
		}
		
		//�Լ� ȣ��
		printf("%d\n", cover(1, 1));

	}


	return 0;
}



int canCover(const int shape[2][2], int x, int y) {
	//map[][]==1 �̶�� ���� map[][] �� ��ü�� ���� ����ص� ���� ���� �ȴ�.
	//��翡 �ش��ϴ� ��ġ�� �� ĭ ���� �ƴ��� �Ǵ�
	if (map[x][y] && map[x + shape[0][0]][y + shape[0][1]] && map[x + shape[1][0]][y + shape[1][1]])
		return TRUE;
	else
		return FALSE;
}


//��ĥ�ϱ�
void paint(const int shape[2][2], int x, int y) {
	map[x][y] = 0;
	map[x + shape[0][0]][y + shape[0][1]] = 0;
	map[x + shape[1][0]][y + shape[1][1]] = 0;
}
//��ĥ �����
void unpaint(const int shape[2][2], int x, int y) {
	map[x][y] = 1;
	map[x + shape[0][0]][y + shape[0][1]] = 1;
	map[x + shape[1][0]][y + shape[1][1]] = 1;
}
int cover(int x, int y) {
	int ret = 0;
	if (0 == curWhites)
		return 1;
	//������ ���̶�� ���� �� �̻� üũ�� �� ����, �Ʒ��� ���� ���� �����Ƿ�
	if (x == H){
		//����� ��� ä������ ����� �� ����
		if (0 == curWhites)
			return 1;
		//�ƴ϶�� �׳� ���ư���
		else
			return 0;
	}
	//���� ��ġ�� ���� ĭ�̶�� �ٸ� ĭ ����
	if (0 == map[x][y]){
		if (y != W)
			ret += cover(x, y + 1);
		else
			ret += cover(x + 1, 1);
	}

	for (int i = 0; i < 4; i++) {
		
		if (canCover(shapes[i], x, y))
		{
			//��ĥ�ϱ�
			paint(shapes[i], x, y);
			curWhites = curWhites - 3;
			//�ڱ��ڽ� ȣ���ϱ�
			if (y != W)
				ret+=cover(x, y + 1);
			else
				ret+=cover(x + 1, 1);
			//�����·� ������
			unpaint(shapes[i], x, y);
			curWhites = curWhites + 3;
		}
		//�ش� ������� ���� �� ���ٸ� �ݺ����� �״�� �����Ͽ� �ٸ� ��� ���
	}

	return ret;
}