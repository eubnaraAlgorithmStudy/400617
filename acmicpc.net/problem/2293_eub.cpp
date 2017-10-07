#include <iostream>
#include <cstdio>
#include <cstring>

unsigned short val[100];
unsigned short cnt[101][10001];

int n,k;

int dp(int lowestIdx, int curVal) {
  if (curVal == 0) {
    return 1;
  } else if (curVal < 0) {
    return 0;
  } else if (cnt[lowestIdx][curVal] != 0) {
    return cnt[lowestIdx][curVal];
  }
  int sum = 0;
  for(int i=lowestIdx; i<n; i++) {
    sum += dp(i, curVal - val[i]);
  }
  if (sum <= 65535) {
      cnt[lowestIdx][curVal] = sum;
  }
  return sum;
}

int main(void) {

  scanf("%d", &n);
  scanf("%d", &k);
  for(int i=0;i<n;i++) {
    scanf("%hu", &val[i]);
  }
  int sum = 0;
  for(int i=0; i<n; i++) {
    sum += dp(i, k - val[i]);
  }
  printf("%d\n", sum);

  return 0;
}
