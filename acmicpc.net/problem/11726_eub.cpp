#include <iostream>
#include <cstdio>


int cnt[1000];

int main (void) {
  int n;
  scanf("%d", &n);
  cnt[0] = 1;
  cnt[1] = 2;

  for(int i = 2; i < n; i++) {
    cnt[i] = (cnt[i-2] + cnt[i-1]) % 10007;
  }
  printf("%d\n", cnt[n-1]);


  return 0;
}
