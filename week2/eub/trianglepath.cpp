#include <iostream>
#include <cstring>

using namespace std;

int ans[100+5];

/*
	int calMaxSum(int size)

	size 크기의 삼각형에 대해서, 숫자를 입력받고 그 숫자들을 이용하여
	모든 경로 중 최대 합을 반환한다.

	주의사항:
		이 함수는 전역배열인 ans[ ]를 사용한다.

*/
int calMaxSum(int size) {
	int max = 0;
	int input[100+5];

	memset(ans, 0, sizeof(int) * size);	// 전역배열인 ans 초기화

	// size 개의 row에 대해서 입력을 받으며 처리한다.
	for(int i = 0; i < size; i++) {
		// 하나의 row에 대해 i개의 column에 대해서 입력을 받는다.
		for(int j = 0; j <= i; j++) {
			scanf("%d", &input[j]);
		}
		/*
			입력을 받았다면, i번째 row에 대한 ans[ ] 를 갱신한다.
			거꾸로 처리해야하므로 뒤에서부터 시작하는데,
			위 아래 for문을 안쓰고 stack을 쓰는 방법을 생각해 볼 수도 있다.
		*/
		for(int j = i; j > 0; j--) {
			ans[j] = input[j] + (ans[j-1] > ans[j] ? ans[j-1] : ans[j]);
		}
		// 0번째에 대해서는 바로 윗칸에서 내려올 수밖에 없으므로 따로 처리
		ans[0] = ans[0] + input[0];
	}


	// 마지막 row에서 계산된 값들 중 최대값을 찾는다.
	for(int i = 0; i < size; i++) {
		max = (max > ans[i]) ? max : ans[i];
	}
	return max;
}

int main(void) {
	int T;
	scanf("%d", &T);

	while(T--) {
		int size;	// 삼각형의 크기
		scanf("%d", &size);
		printf("%d\n", calMaxSum(size));
	}
	return 0;
}