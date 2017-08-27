// http://codersbrunch.blogspot.kr/2016/08/2136.html
// 못풀어서 위 사이트를 참고하여 풀었음

/*
  - 문제를 다르게 생각해 보자. 모든 개미들이 다른 개미들을 관통하여 이동할 수 있다는 가정을 세워보자. 개미들이 떨어지는데 걸리는 시간은 동일하다.
  - 오른쪽으로 가는 개미를 "->" 으로, 왼쪽으로 가는 개미를 "<-" 으로 상상해 보자. 화살표의 개수만큼 각자 그 방향으로 떨어질 수밖에 없다. 어떤 개미가 다른 개미와 부딪혀서 방향이 바뀐다 하더라도, 그 자신이 아니라 다른 개미가 그 방향으로 떨어지게 되어있다.
  - 그렇다면, "<-" 왼쪽 화살표가 n 개 있다면, 전체 개미 중, 왼쪽에서 n 마리의 개미는 반드시 왼쪽으로 떨어진다.
  - 왼쪽으로 떨어지는 개미들 중 가장 오래걸리는 시간은 "<-" 개미들 중 가장 오른쪽에 있는 것이다. 걸리는 시간은 관통해서 계산하는 것과 같다.
  - "<-" 개미들 중 가장 오른쪽에 있는 것이 관통해서 왼쪽에 떨어지는 시간 vs. "->" 개미들 중 가장 왼쪽에 있는 것이 관통해서 오른쪽에 떨어지는 시간 을 계산하여 더 오래 걸리는 것을 찾는다.
  - 만약, "<-" 개미들이 c 마리이고, 왼쪽으로 떨어지는 시간 중 가장 긴 시간이 t 라면, 정답은 {c번째의 개미번호} {t} 로 출력하면 된다.
  - 참고로 입력은 위치대로 주어지지 않으니 정렬하는 과정이 필요하다.
    - 여기 코드에서는 "위치-개미번호" 를 pair 로 묶고, 위치를 기준으로 정렬하여 사용하였다.
    - 위치상 c번째의 개미번호를 출력하도록 하였다.
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

pair <int, int> p[100000];
int N, L;
int pcnt;
int lenToTheRight, lenToTheLeft;
int leftArrowCnt;

int main(void) {

  scanf("%d %d", &N, &L);
  for(int i=1; i<=N; i++) {
    int loc;
    scanf("%d", &loc);
    if(loc < 0) {
      leftArrowCnt += 1;
      lenToTheLeft = lenToTheLeft < abs(loc) ? abs(loc) : lenToTheLeft;
    } else {
      lenToTheRight = lenToTheRight < L - loc ? L - loc : lenToTheRight;
    }
    p[pcnt++] = {abs(loc), i};
  }
  sort(p, p + pcnt);
  if(lenToTheLeft < lenToTheRight) {
    printf("%d %d\n", p[leftArrowCnt].second, lenToTheRight);
  } else {
    printf("%d %d\n", p[leftArrowCnt-1].second, lenToTheLeft);
  }

  return 0;
}
