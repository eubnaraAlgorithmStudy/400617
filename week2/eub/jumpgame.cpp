#include <iostream>
#include <cstring>

using namespace std;

int input[100+5][100+5];
int canJump[100+5][100+5]; // -1 미탐색, 0 거짓, 1 참

//index는 0이 아니라 1부터 시작
bool jump(int row, int col, int size) {
	// 경계를 넘어설 경우의 처리
	// 오른쪽이나 아래로만 점프를 하니까 그쪽 방향에 대해서만 처리를 하면 됨.
	if(row > size || col > size)
		return false;

	// 목표에 도달한 경우
	if(row == size && col == size) {
		// printf("success\n");
		return true;
	}

	// 거짓
 	if(canJump[row][col] == 0) {
 		return false;
 	}
 	int range = input[row][col];

 	if(jump(row + range, col, size)) {
 		return true;
 	}
 	if(jump(row, col + range, size)) {
 		return true;
 	}

 	canJump[row][col] = 0;
 	return false;
}

int main(void) {
	int T;
	scanf("%d", &T);
	while(T--) {
		int size;	// 격자의 크기
		scanf("%d", &size);
		// 2 * (100+5) 로 초기화하면 안됨
		memset(canJump, -1, sizeof(int)*(100+5)*(100+5));

		for(int i=1; i<=size; i++) {
			for(int j=1; j<=size; j++) {
				scanf("%d", &input[i][j]);
			}
		}

		if(jump(1, 1, size)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}

	}

	return 0;
}