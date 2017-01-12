// https://algospot.com/judge/problem/read/TRIANGLEPATH#
#include <stdio.h>
#include <memory.h>
int dir[2][2] = {1,0,1,1};
int triangle[100][100];
int max = 0;
void DFS(int row, int col, int sum);
int main(void)
{
	int c, n;
	int test_case, i, j, k;	
	
	scanf("%d", &c);
	for (test_case = 0; test_case < c; test_case++) {
		memset(triangle, 0, sizeof(int) * 10000);
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			for (j = 0; j <= i; j++) {
				scanf("%d", &triangle[i][j]);
			}
		}
		// END of input

		/*for (i = 0; i < n; i++) {
			for (j = 0; j <n; j++) {
				printf("%d ", triangle[i][j]);
			}
			printf("\n");
		}*/
		// DFS ·Î Å½»öÇÏ±â
		DFS(0, 0, 0);
		printf("%d\n", max);
	}
	return 0;
}

void DFS(int row, int col, int sum)
{
	int i, j;
	if (triangle[row][col] == 0) {
		//printf("row: %d, col: %d\n", row, col)
		if (sum > max) max = sum;
		return ;
	}
	else {
		sum += triangle[row][col];
		for (i = 0; i < 2; i++) {
			//printf("i: %d, dir[%d][0] = %d, dir[%d][1] = %d \n", i, i, dir[i][0], i, dir[i][1]);
			DFS(row+dir[i][0], col+dir[i][1], sum);
		}
	}
}