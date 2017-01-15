#include<stdio.h>
#include<stdlib.h>

int tri_cal(int **arr, int size);					//경험치값을 계산하기 위한 함수
int max_num(int a, int b);

void main(){

	int testcase;
	int size, test_case, row, col, i;
	int **tri = NULL;
	int *test = NULL;

	scanf("%d", &test_case);
	test = (int*)malloc(sizeof(int)*test_case);

	for (i = 0; i < test_case; i++){
		size = 0;
		scanf("%d", &size);
		//2차원 배열 동적할당
		tri = (int**)malloc(sizeof(int*)*size);
		for (row = 0; row < size; row++){
			*(tri + row) = (int*)malloc(sizeof(int)*size);
		}
		//test case만큼
		//삼각형 모양의 배열에 data 입력

		for (row = 0; row < size; row++){
			for (col = 0; col < size; col++){
				if (row == col){
					scanf("%d", &tri[row][col]);
				}
				else if (row >= col){
					scanf("%d", &tri[row][col]);
				}
				else
					tri[row][col] = 0;
			}
		}
		//경로의 최대값을 구하기 위한 함수 선언
		test[i] = tri_cal(tri,size);

		/*for (row = 0; row < size; row++){
			for (col = 0; col < size; col++){
				printf("%d ", tri[row][col]);
			}
			printf("\n");
		}*/
		//할당한 배열 해제
		for (row = 0; row < size; row++){
			free(tri[row]);
		}
		free(tri);
	}
	for (i = 0; i < test_case; i++){
		printf("%d\n", test[i]);
	}
	free(test);
}
int max_num(int a, int b){
	if (a > b)
		return a;
	else
		return b;
}
int tri_cal(int **tri, int size){

	int row = 0, col = 0;
	int **result = NULL;
	int max_value = 0;
	
	//메모이제이션을 위한 원본배열과 같은 추가배열생성
	result = (int**)malloc(sizeof(int*)*size);
	for (row = 0; row < size; row++){
		*(result + row) = (int*)malloc(sizeof(int)*size);
	}
	//메모이제이션
	result[0][0] = tri[0][0];
	for (row = 1; row < size; row++){
		for (col = 0; col <= row; col++){
			if (col == 0){
				result[row][0] = result[row - 1][0] + tri[row][0];
			}
			else if (row == col){
				result[row][col] = result[row - 1][col - 1] + tri[row][col];
			}
			else{
				result[row][col] = max_num(result[row-1][col-1],result[row - 1][col]) + tri[row][col];
			}
		}
	}
	//마지막행에서 최대 값비교
	for (col = 1; col < size; col++){
		max_value = max_num(result[size][col - 1], result[size][col]);
	}
	//추가배열의 할당해제
	for (row = 0; row < size; row++){
		free(result[row]);
	}
	free(result);
	return max_value;
}