#include <stdio.h>
#include <stdlib.h>

int max_num(int a, int b){
	if (a > b)
		return a;
	else
		return b;
}
int payCalculation(int *p, int *q, int week){
	int *payment = NULL;
	int result = 0, i = 0;
	payment = (int*)malloc(sizeof(int)*week);
	
	/*P의 작업은 한주에 끝낼수 있고 Q의 작업은 2주가 걸린다.
	그렇지만 Q의 작업을 첫번째 주에 받는다면 완료할수 있다.
	이 조건들을 나눠 본다면
	1. week2까지 p의 작업만하는 경우
	2. week1에서 q의 작업을 끝내고 week2에서 p작업을 하는 경우
	3. week2까지 Q회사의 작업을 하는 경우*/

	if (p[0] > q[0] && p[1] > q[1]){
		for (i = 0; i <= 1; i++){
			payment[i] = p[i];
		}
	}
	else{
		if (p[0] < q[0] && p[1] > q[1]){
			payment[0] = q[0]; payment[1] = p[1];
		}
		else if (p[0] < q[0] && p[1] < q[1] && q[0] < q[1]){
			payment[0] = 0; payment[1] = q[1];
		}
	}
	for (i = 2; i < week; i++){
		payment[i] = max_num(p[i], q[i]);
	}
	printf("number of array p and array q\n");
	for (i = 0; i < week; i++){
		printf("%2d ", p[i]);
	}
	printf("\n");
	for (i = 0; i < week; i++){
		printf("%2d ", q[i]);
	}
	printf("\nnumber of payment array\n");
	for (i = 0; i < week; i++){
		printf("%d ", payment[i]);
	}

	for (i = 0; i < week; i++){
		result += payment[i];
	}
	return result;
}

int main(void) {
	/* 아래 freopen 함수는 sample_input.txt를 read only 형식으로 열고, 표준입력(키보드) 대신 sample_input.txt 로 부터 읽어오겠다는 의미의 코드입니다.
	만약 본인 PC 에서 테스트 할 때는, 입력값을 sample_input.txt에 저장한 후 freopen 함수를 사용하면
	그 아래에서 scanf 함수를 사용하여 표준입력 대신 sample_input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야만 합니다. */
	// freopen("sample_input.txt", "r", stdin);

	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 '시간 초과'로 강제 종료 되었을 때,
	printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	시간 초과 전까지 실행된 결과 점수를 받고자 하신다면 "setbuf(stdout, NULL);" 를 사용하시기 바랍니다. */
	setbuf(stdout, NULL);

	int T;
	int test_case;
	int *Ppay;
	int *Qpay;
	int week;
	int i;

	//두개의 배열을 동적할당으로 생성후에 week마다 수수료를 비교해서 큰것 끼리 더한다.
	//Q회사의 첫번째 수수료는 더하거나 비교하지 않는다. 왜냐하면 Q회사의 작업마감에는 2주가 걸리기 때문이다.
	//T는 test case의 갯수 
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
		week = 0;
		scanf("%d", &week);
		Ppay = (int*)malloc(sizeof(int)*week);
		Qpay = (int*)malloc(sizeof(int)*week);
		for (i = 0; i < week; i++){
			scanf("%d", &Ppay[i]);
		}
		for (i = 0; i < week; i++){
			scanf("%d", &Qpay[i]);
		}
		printf("\n");
		printf("Case #%d\n", test_case);
		printf("%d\n", payCalculation(Ppay, Qpay, week));
		free(Ppay); free(Qpay);
		// 이 부분에서 정답을 출력하십시오.
		
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}