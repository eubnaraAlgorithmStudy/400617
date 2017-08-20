#include <iostream>
#include <cstring>
#include <cstdio>

int N, K;
int count = 0;
int cache[201][201];
const int divider = 1000000000;

int dfs(int n, int k) {
  int sum = 0;
  if (k == 1) {
      cache[n][k] = 1;
      return 1;
  } else {
    for(int i=0;i<=n;i++) {
        if (cache[n-i][k-1] != -1) {
          sum += cache[n-i][k-1];
        } else {
          sum += dfs(n-i, k-1);
        }
        sum %= divider;
    }
    cache[n][k] = sum;
    return sum;
  }
}


int main(void) {

  memset(cache, -1, sizeof(int) * 201 * 201);
  scanf("%d %d", &N, &K);
  printf("%d\n", dfs(N, K));

  return 0;
}
