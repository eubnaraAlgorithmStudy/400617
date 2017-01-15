#include <cstdio>
#include <iostream>
using namespace std;

int max(int a, int b);

int max(int a, int b)
{
	if (a < b)
		return b;
	else
		return a;
}
int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� sample_input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� sample_input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� sample_input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� sample_input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	//freopen("sample_input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	C++���� printf�� ����� ���, printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	���� printf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T;
	int test_case;
	int numjob;
	int p_time[10000];
	int q_time[10000];
	int week[10000];
	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		scanf("%d", &numjob);//�����ؾ� �� �۾��� ����
		for(int i=1;i<=numjob;i++)//P �۾��� ���ؼ� �޴� ������
			scanf("%d", &p_time[i]);
		for (int i = 1;i <= numjob;i++)//Q �۾��� ���� �޴� ������
			scanf("%d", &q_time[i]);
		week[1] = max(p_time[1], q_time[1]);//ù��° �ָ� ���� �� �ΰ���
		week[2] = max((q_time[1]+p_time[2]), max((p_time[1] + p_time[2]), q_time[2]));//�ι�° �ֿ����� p�۾� �ΰ��ϴ°Ŷ� q�۾� �Ѱ� �ϴ°�,ù �ֿ�q, ��°�ֿ� p�ϴ� ���߿� ��, ��� ������
		
		for (int i = 3;i <= numjob;i++)//3���Ŀ��� �� ���ֵ鿡�ٰ� p�۾��� �ҰŸ� 1�ָ� ���, q�� �ҰŸ� 2�� �������� ���
		{
			week[i] = max((week[i - 1] + p_time[i]), (week[i - 2] + q_time[i]));
		}
			
			//���� ������ ���� ���� �� �ִ� �۾� ����


		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		printf("%d", week[numjob]);
		printf("\n");

	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}