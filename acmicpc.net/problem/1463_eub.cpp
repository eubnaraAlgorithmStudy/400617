#include <iostream>
#include <cstdio>


int cnt[1000000+1];

int main(void) {
  int N;
  scanf("%d", &N);

  for(int i=1; i<=N; i++) {
    if (3 * i <= N) {
      if ( cnt[3*i] == 0) {
        cnt[3*i] = cnt[i] + 1;
      } else {
        cnt[3*i] = cnt[3*i] < cnt[i] + 1 ? cnt[3*i] : cnt[i] + 1;
      }
    }
    if (2 * i <= N) {
      if ( cnt[2*i] == 0) {
        cnt[2*i] = cnt[i] + 1;
      } else {
        cnt[2*i] = cnt[2*i] < cnt[i] + 1 ? cnt[2*i] : cnt[i] + 1;
      }
    }
    if (cnt[i+1] == 0) {
      cnt[i+1] = cnt[i] + 1;
    } else {
      cnt[i+1] = cnt[i+1] < cnt[i] + 1 ? cnt[i+1] : cnt[i] + 1;
    }
  }
  printf("%d\n", cnt[N]);


  return 0;
}
