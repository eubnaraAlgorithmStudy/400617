/*
	오답노트:
	- 전역변수는 항상 테스트케이스마다 초기화가 잘 되고 있는지 확인하자.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define MAX 25
/*
	왼쪽 상단부터 ㄱ 형태를 채워나갈 때, 회전시켜서 채울 수 있는 모양을 나타낸다.
	총 4가지 경우가 있다. ㄱ, ㄱ과 좌우반전, ㄴ, ㄴ과 좌우반전
*/
const int shapes[4][2][2] = {
	{ { 0, 1 }, { 1, 0 } },
	{ { 0, 1 }, { 1, 1 } },
	{ { 1, 0 }, { 1, 1 } },
	{ { 1, 0 }, { 1, -1 } }
};
//경계처리를 원할하게 하기 위하여 인덱스는 1부터 시작하는 것으로 하며,
//전역변수에 기본적으로 0값이 채워지는 것에 착안하여 0값은 검은 칸, 1값은 흰 칸을 나타내도록 한다.
int map[MAX][MAX];
//가로, 세로길이
int H, W;
//현재까지 채워진 흰 칸의 수
int curWhites;

//4가지의 모양 중에 하나를 넣으면, 그 모양대로 덮을 수 있는지 참,거짓을 반환
//제자리는 당연히 흰 칸 이어야하는 전제조건
int canCover(const int shape[2][2],int x, int y);
//map을 덮어서 채울 수 있는 경우의 수를 반환
int cover(int x, int y);
void paint(const int shape[2][2], int x, int y);
void unpaint(const int shape[2][2], int x, int y);

int main(void) {
	int T;	//testcase의 수

	scanf("%d", &T);
	while (T--) {
		//초기화
		memset(map, 0, sizeof(int)*MAX*MAX);	//ERROR: 이 부분을 빼먹어서 오류를 냈었음.
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

		//채워야 하는 흰 칸의 개수가 3의 배수가 아니라면 채울 수 있는 경우의 수가 0
		if (curWhites % 3 != 0){
			printf("0\n");
			continue;
		}
		
		//함수 호출
		printf("%d\n", cover(1, 1));

	}


	return 0;
}



int canCover(const int shape[2][2], int x, int y) {
	//map[][]==1 이라는 뜻은 map[][] 그 자체의 값을 사용해도 같은 뜻이 된다.
	//모양에 해당하는 위치가 흰 칸 인지 아닌지 판단
	if (map[x][y] && map[x + shape[0][0]][y + shape[0][1]] && map[x + shape[1][0]][y + shape[1][1]])
		return TRUE;
	else
		return FALSE;
}


//색칠하기
void paint(const int shape[2][2], int x, int y) {
	map[x][y] = 0;
	map[x + shape[0][0]][y + shape[0][1]] = 0;
	map[x + shape[1][0]][y + shape[1][1]] = 0;
}
//색칠 지우기
void unpaint(const int shape[2][2], int x, int y) {
	map[x][y] = 1;
	map[x + shape[0][0]][y + shape[0][1]] = 1;
	map[x + shape[1][0]][y + shape[1][1]] = 1;
}
int cover(int x, int y) {
	int ret = 0;
	if (0 == curWhites)
		return 1;
	//마지막 줄이라면 이제 더 이상 체크할 수 없음, 아래로 뻗을 수가 없으므로
	if (x == H){
		//흰색을 모두 채웠으면 경우의 수 증가
		if (0 == curWhites)
			return 1;
		//아니라면 그냥 돌아가기
		else
			return 0;
	}
	//현재 위치가 검은 칸이라면 다른 칸 조사
	if (0 == map[x][y]){
		if (y != W)
			ret += cover(x, y + 1);
		else
			ret += cover(x + 1, 1);
	}

	for (int i = 0; i < 4; i++) {
		
		if (canCover(shapes[i], x, y))
		{
			//색칠하기
			paint(shapes[i], x, y);
			curWhites = curWhites - 3;
			//자기자신 호출하기
			if (y != W)
				ret+=cover(x, y + 1);
			else
				ret+=cover(x + 1, 1);
			//원상태로 돌리기
			unpaint(shapes[i], x, y);
			curWhites = curWhites + 3;
		}
		//해당 모양으로 덮을 수 없다면 반복문을 그대로 진행하여 다른 경우 고려
	}

	return ret;
}