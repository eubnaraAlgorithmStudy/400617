#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int P[10000+5], Q[10000+5], ans[10000+5];

void calFee(int week) {
	//base case
	ans[0] = P[0] > Q[0] ? P[0] : Q[0];
	if(week == 1)
		return;
	ans[1] = (ans[0] + P[1]) > Q[1] ? ans[0] + P[1] : Q[1];




	for(int i=2; i<week; i++) {
		int bigger = (ans[i-1] + P[i]) > (ans[i-2] + Q[i]) ? ans[i-1] + P[i] : ans[i-2] + Q[i];
		ans[i] = bigger;
	}
}

int main(void) {
	int T;
	scanf("%d", &T);
	for(int i=1; i<=T; i++) {
		int week;
		scanf("%d", &week);
		//TODO: 이거 빼도 되나? 타임아웃 발생 시 한 번 고려해 볼 것
		memset(ans, 0, (week+5)*sizeof(int));

		for(int j=0; j<week; j++) {
			scanf("%d", &P[j]);
		}

		for(int j=0; j<week; j++) {
			scanf("%d", &Q[j]);
		}


		calFee(week);



		printf("Case #%d\n", i);
		printf("%d\n", ans[week-1]);
	}



	return 0;
}