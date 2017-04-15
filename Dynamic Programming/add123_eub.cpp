//https://www.acmicpc.net/problem/9095
#include <iostream>
#include <cstdio>
using namespace std;

int ans[12];

int solve(int n) {
  if(n<=0) {
    printf("ERROR! zero or minus.\n");
    return -1;
  }
  if(n<=3) {
    return ans[n];
  }
  if(ans[n] != 0) {
    return ans[n];
  }

  for(int i=4; i<=n; i++) {
    ans[i] = ans[i-1] + ans[i-2] + ans[i-3];
  }
  return ans[n];
}

int main(void) {
  int t;
  scanf("%d", &t);
  ans[1] = 1;
  ans[2] = 2;
  ans[3] = 4;

  while(t--) {
    int n;
    scanf("%d", &n);
    cout << solve(n) << endl;
  }


  return 0;
}
