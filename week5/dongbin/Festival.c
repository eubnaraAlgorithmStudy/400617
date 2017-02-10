#include<stdio.h>
int N, L;
int payment[1000 + 1];

double min_payment(){

	int i, j, k;
	double sum = 0;
	double avg = 0;
	double min = 9999;

	for (i = L; i <= N; i++){
		for (j = 1; j <= N - i + 1; j++){
			for (k = j; k < j + i; k++){ sum += payment[k]; }
			avg = sum / i; sum = 0;
			if (min >= avg){ min = avg; }
		}
	}
	return min;
}
int main(){

	int Test_case, T;		// N�� �ִ������������, L�� Ȯ���� ���� ���� ��(L<=N), T�� test_case��ŭ �ݺ����� ���� Ƚ��
	
	scanf("%d", &Test_case);
	for (T = 0; T < Test_case; T++){
		scanf("%d %d", &N, &L);
		for (int i = 1; i <= N; i++){
			scanf("%d", &payment[i]);
		}
		printf("%.8f\n", min_payment());
	}
	return 0;
}