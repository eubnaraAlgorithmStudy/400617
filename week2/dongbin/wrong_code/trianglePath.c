#include<stdio.h>
#include<stdlib.h>

int tri_cal(int **arr, int size);					//����ġ���� ����ϱ� ���� �Լ�
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
		//2���� �迭 �����Ҵ�
		tri = (int**)malloc(sizeof(int*)*size);
		for (row = 0; row < size; row++){
			*(tri + row) = (int*)malloc(sizeof(int)*size);
		}
		//test case��ŭ
		//�ﰢ�� ����� �迭�� data �Է�

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
		//����� �ִ밪�� ���ϱ� ���� �Լ� ����
		test[i] = tri_cal(tri,size);

		/*for (row = 0; row < size; row++){
			for (col = 0; col < size; col++){
				printf("%d ", tri[row][col]);
			}
			printf("\n");
		}*/
		//�Ҵ��� �迭 ����
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
	
	//�޸������̼��� ���� �����迭�� ���� �߰��迭����
	result = (int**)malloc(sizeof(int*)*size);
	for (row = 0; row < size; row++){
		*(result + row) = (int*)malloc(sizeof(int)*size);
	}
	//�޸������̼�
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
	//�������࿡�� �ִ� ����
	for (col = 1; col < size; col++){
		max_value = max_num(result[size][col - 1], result[size][col]);
	}
	//�߰��迭�� �Ҵ�����
	for (row = 0; row < size; row++){
		free(result[row]);
	}
	free(result);
	return max_value;
}