// https://www.codeground.org/practice/practiceProbView.do?probId=16
#include <stdio.h>
int main(void)
{
	int c; // c: test case
	int m, num[100000], diff[100000]; // m: num of input
	int min_d, result;

	scanf("%d", &c);
	for (int Case = 0; Case < c; Case++) {
		scanf("%d", &m);
		for (int M = 0; M < m; M++) {
			scanf("%d", &num[M]);
		}
		// end of input
		result = 1; // intialize to 1, because '1' is always included

		// find smallest diff
		for (int i = m - 1; i > 0; i--) {
			diff[i - 1] = num[i] - num[i];
		}

		min_d = diff[0];
		for (int i = 1; i <= m-1; i++) { // diff : 0 ~ m-1
			if (min_d > diff[i]) min_d = diff[i];
		}

		for (int i = 2; i <= min_d; i++) {
			int n;
			while (n <= num[m - 1]) {
				// m배열에서 한칸 씩 움직이고, 넘었는데 그 수가 안나오면 중단 -> i++
				// 끝까지 가면 result++
			}
		}

	}
	return 0;
}