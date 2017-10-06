#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int P[1000+1];
int val[1000+1];
int N;

int dp() {
  for(int idx=0; idx<N; idx++) {
    for(int i=1; i<=N; i++) {
      if (N < idx + i) {
        continue;
      }
      val[idx + i] = val[idx + i] < val[idx] + P[i] ? val[idx] + P[i] : val[idx + i];
    }
  }
}

int main(void) {

  scanf("%d", &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &P[i]);
  }

  dp();

  printf("%d\n", val[N]);


  return 0;
}
