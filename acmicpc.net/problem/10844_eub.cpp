#include <iostream>
#include <cstdio>
using namespace std;


int N;
int ans[100+1][9+1]; // ans[idx][num]: idx 번째 수가 num 일 때의 개수
const int divider = 1000000000;


int dp(int idx, int num) {
  if(0 < ans[idx][num]) {
    return ans[idx][num];
  }
  if(idx == N) {
    return 1;
  }
  if(num == 9) {
    ans[idx][num] = dp(idx+1, 8);
  } else if(num == 0) {
    ans[idx][num] = dp(idx+1, 1);
  } else {
    ans[idx][num] = (dp(idx+1, num-1) + dp(idx+1, num+1)) % divider;
  }
  return ans[idx][num];
}


int main(void) {
  scanf("%d", &N);
  int sum = 0;
  for(int i=1;i<=9;i++) {
    sum = (sum + dp(1, i)) % divider;
  }
  // for(int i=1; i<=N; i++) {
  //   for(int j=1; j<=9; j++) {
  //     printf("%d ", ans[i][j]);
  //   }
  //   printf("\n");
  // }
  printf("%d\n", sum);


  return 0;
}
