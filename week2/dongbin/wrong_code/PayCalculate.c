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
	
	/*P�� �۾��� ���ֿ� ������ �ְ� Q�� �۾��� 2�ְ� �ɸ���.
	�׷����� Q�� �۾��� ù��° �ֿ� �޴´ٸ� �Ϸ��Ҽ� �ִ�.
	�� ���ǵ��� ���� ���ٸ�
	1. week2���� p�� �۾����ϴ� ���
	2. week1���� q�� �۾��� ������ week2���� p�۾��� �ϴ� ���
	3. week2���� Qȸ���� �۾��� �ϴ� ���*/

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
	/* �Ʒ� freopen �Լ��� sample_input.txt�� read only �������� ����, ǥ���Է�(Ű����) ��� sample_input.txt �� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ���� PC ���� �׽�Ʈ �� ����, �Է°��� sample_input.txt�� ������ �� freopen �Լ��� ����ϸ�
	�� �Ʒ����� scanf �Լ��� ����Ͽ� ǥ���Է� ��� sample_input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž߸� �մϴ�. */
	// freopen("sample_input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� '�ð� �ʰ�'�� ���� ���� �Ǿ��� ��,
	printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	�ð� �ʰ� ������ ����� ��� ������ �ް��� �ϽŴٸ� "setbuf(stdout, NULL);" �� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T;
	int test_case;
	int *Ppay;
	int *Qpay;
	int week;
	int i;

	//�ΰ��� �迭�� �����Ҵ����� �����Ŀ� week���� �����Ḧ ���ؼ� ū�� ���� ���Ѵ�.
	//Qȸ���� ù��° ������� ���ϰų� ������ �ʴ´�. �ֳ��ϸ� Qȸ���� �۾��������� 2�ְ� �ɸ��� �����̴�.
	//T�� test case�� ���� 
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
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
		// �� �κп��� ������ ����Ͻʽÿ�.
		
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}