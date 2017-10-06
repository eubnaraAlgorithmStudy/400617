#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * cnt[i][0]: 현재 포도주를 안마심
 * cnt[i][1]: 바로 이전(i-1) 포도주는 안마시고, 현재 포도주(i) 마심
 * cnt[i][2]: 바로 이전(i-1) 포도주와 현재 포도주(i) 모두 마심
 */
int cnt[10000][3];
int amount[10000];

int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &amount[i]);
  }
  cnt[0][0] = 0;
  cnt[0][1] = amount[0];
  cnt[0][2] = 0;

  for (int i = 1; i < n; i++) {
    cnt[i][0] = max(cnt[i-1][0], cnt[i-1][1]);
    cnt[i][0] = max(cnt[i][0], cnt[i-1][2]);

    cnt[i][1] = cnt[i-1][0] + amount[i];

    cnt[i][2] = cnt[i-1][1] + amount[i];
  }
  int maxResult = max(cnt[n-1][0], cnt[n-1][1]);
  maxResult = max(maxResult, cnt[n-1][2]);
  printf("%d\n", maxResult);

  return 0;
}
