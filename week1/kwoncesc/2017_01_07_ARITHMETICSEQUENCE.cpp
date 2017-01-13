// Header files inclusion
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Define namespace
using namespace std;

// Functions definition
long long FINDMIN(long long a, long long b)
{
	return a > b ? b : a;
}
long long FINDMAX(long long a, long long b)
{
	return a < b ? b : a;
}

int main(int argc, char ** argv)
{
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	//freopen("input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	C++���� printf�� ����� ���, printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	���� printf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	// Local variables declare
	int T;
	int test_case;

	// Statements
	scanf("%d", &T);    // Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.

	for (test_case = 1; test_case <= T; test_case++)
	{
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.

		long long  n;
		cin >> n;

		long long arr[100005] = { 0, };

		for (int i = 0; i < n; i++)
			scanf("%llu", &arr[i]);

		long long min = 10000000000001;
		long long max = -10000000000001;
		n--;

		for (long long i = 1; i <= n; i++)
		{
			long long t = (arr[i] - arr[i - 1]);
			min = FINDMIN((arr[i] - arr[i - 1]), min);
			max = FINDMAX((arr[i] - arr[i - 1]), min);
		}
		//r_min�� �������
		long long  k = sqrt(min);

		long long  res = 0;

		if (min == 0 && max == 0)
		{
			printf("Case #%d\n", test_case);
			printf("1\n");
			continue;
		}
		else if (min == 0 && max != 0)
		{
			printf("Case #%d\n", test_case);
			printf("0\n");
			continue;
		}
		else
		{
			for (long long i = 1; i <= k; i++)
			{
				if (min % i == 0)
					res++;
			}

			if ((double)k == ((double)min / (double)k))
			{
				printf("Case #%d\n", test_case);
				printf("%d\n", 2 * res - 1);
			}
			else
			{
				// n�� �Ǵ��� �ȵǴ��� �Ǻ� �߰�
				printf("Case #%d\n", test_case);
				printf("%d\n", 2 * res);
			}

		}
	}

	return 0;    // �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}

