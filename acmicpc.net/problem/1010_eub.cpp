#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int T, N, M;
int cnt[30+1][30+1];

int dp(int n, int m) {
  if (0 < cnt[n][m]) {
    return cnt[n][m];
  }
  if (n == N) {
    return 1;
  }
  int sum = 0;
  for(int i = m + 1;i <= M - (N - n) + 1; i++) {
    sum += dp(n+1, i);
  }
  cnt[n][m] = sum;
  return sum;
}

int main(void) {
  scanf("%d", &T);
  while(T--) {
    memset(cnt, 0, sizeof(int) * 30 * 30);
    scanf("%d %d", &N, &M);
    printf("%d\n", dp(0,0));
  }

  return 0;
}
