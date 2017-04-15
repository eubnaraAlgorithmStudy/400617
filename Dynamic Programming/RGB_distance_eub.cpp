#include <iostream>
#include <cstdio>
using namespace std;
/*
  빨, 초, 파
  모든 이웃은 같은 색으로 칠할 수 없다.
  처음과 마지막 집은 이웃이 아니다.(원형이 아니다)

  각 색깔로 칠하는 비용

  비용을 최소화하기

  입력:
  N<=1000

  집의 수 N
  각 집을 칠할 때 드는 비용 N개 나열(빨, 초, 파) R, G, B


*/
/*
  풀이:
    현재 칠하는 색의 제한은 바로 전 이웃의 색깔에만 영향을 받는다.
    그렇다면, 이전 이웃이 어떤 하나의 색으로 끝났다고 할 때, 그 색깔을 가지면서 그때까지 칠한 값이 최소라는 것이 보장된다면, 동적프로그래밍 기법을 사용할 수 있다.




*/

const int MAX = 2147483647;
int cost[1000][3];
int ans[1000][3];
int main(void) {
  int n;
  scanf("%d",&n);

  for (int i=0; i<n; i++) {
    for (int j=0; j<3; j++) {
      scanf("%d", &cost[i][j]);
    }
  }
  // 처음 basecase 초기화
  for (int i=0; i<3; i++) {
    ans[0][i] = cost[0][i];
  }

  for (int i=1; i<n; i++) {
    for (int j=0; j<3; j++) {
      int min = MAX;
      for (int k=0; k<3; k++) {
        // 이웃은 같은 색이면 안된다.
        if (j == k) continue;
        if (ans[i-1][k] < min) min = ans[i-1][k];
      }
      ans[i][j] = min + cost[i][j];
    }
  }
  int answer = MAX;
  for (int i=0; i<3; i++) {
    if (ans[n-1][i] < answer) {
      answer = ans[n-1][i];
    }
  }
  printf("%d", answer);




  return 0;
}
