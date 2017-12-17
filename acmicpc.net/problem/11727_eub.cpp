#include <iostream>
#include <cstdio>

int cache[1001];

int dp(int n) {
  for(int i=3; i<=n; i++) {
    cache[i] = (cache[i-1] + (cache[i-2] * 2)) % 10007;
  }
  return cache[n];
}

int main(void) {
  int n;
  scanf("%d", &n);
  cache[1] = 1;
  cache[2] = 3;
  printf("%d\n", dp(n));

  return 0;
}
