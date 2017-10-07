#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int A[1000];
int longest = 0;
int cnt[10000];

int main(void) {
  int N;
  scanf("%d", &N);
  for(int i=0;i<N;i++) {
    scanf("%d", &A[i]);
  }
  for(int i=0;i<N;i++) {
    int cur = A[i];
    for(int j=i+1;j<N;j++) {
      if(cur < A[j] && cnt[j] < cnt[i] + 1 ) {
        cnt[j] = cnt[i] + 1;
        longest = max(longest, cnt[j]);
      }
    }
  }


  printf("%d\n", longest + 1); // 하나만 있는 경우



  return 0;
}
