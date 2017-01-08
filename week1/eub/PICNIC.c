/*
	오답노트:
	- 전역변수를 초기화할 때 주의할 것
	- 전역배열을 초기화할 때 부분적으로만 초기화하진 않았는지 유의할 것(memset()함수를 이용하는 경우 특히 주의)

*/




#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

int areFriends[MAX][MAX];	//서로 친구인지 기록하는 배열
int taken[MAX];	//짝이 지어졌는지 기록하는 배열
int makeTeam(int n);
int main(void) {
	int T,n,m;
	scanf("%d", &T);
	while (T--) {
		//n: 학생의 수 2 <= n <= 10
		//m: 친구 쌍의 수 0 <= m <= n*(n-1)/2
		scanf("%d %d", &n, &m);
		//n*n길이만큼을 초기화하면 안 돼! MAX*MAX 배열이라는 점에 주목, 착각!!!!!
		//memset(areFriends, 0, sizeof(int)*n*n);
		memset(areFriends, 0, sizeof(int)*MAX*MAX);
		memset(taken, 0, sizeof(int)*n);
		for (int i = 0; i < m; i++){
			int p1, p2;//person1 person2
			scanf("%d %d", &p1, &p2);
			areFriends[p1][p2] = 1;
			areFriends[p2][p1] = 1;
		}
		printf("%d\n", makeTeam(n));
	}
	return 0;
}
/*
	짝을 만들고, 만들어질 수 있는 경우의 수를 반환

	Argument
	taken[] : 짝이 지어졌는지 기록하는 배열
	n : 총 인원의 수
*/
int makeTeam(int n) {
	int person = -1;
	//가장 앞 번호의 고르지 않은 사람을 하나 추려낸다.
	for (int i = 0; i < n; i++) {
		if (!taken[i])
		{
			person = i;
			break;
		}
	}
	//모두 짝지어진 경우
	if (person == -1){
		return 1;
	}
		

	taken[person] = 1;
	int ret = 0;
	for (int i = person + 1; i < n; i++) {
		//이 부분에서 실수 했었다. || taken[i]를 빼먹었었다.
		//일단 친구인지 확인도 해야하며, 이미 짝이 지어진 사람은 제외시켜야 한다.
		if ((!areFriends[person][i]) || taken[i])
			continue;
		else {
			taken[i] = 1;
			ret += makeTeam(n);
			taken[i] = 0;
		}
	}
	taken[person] = 0;
	return ret;
}