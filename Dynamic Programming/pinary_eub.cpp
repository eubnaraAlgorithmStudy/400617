#include <iostream>
#include <cstring>
using namespace std;

/*
  첫자리는 무조건 1

  현재 자리가 0 이라면 이전 자리의 숫자는 아무거나와도 돼
  현재 자리가 1이라면 이전 자리의 숫자는 0이어야만 해



*/
long long int ans[2][2];
int main(void) {
  bool toggle = false;
  long long int n;
  scanf("%lld", &n);
  ans[toggle][0] = 0;
  ans[toggle][1] = 1;

  for (int i=1; i<n; i++) {
    toggle = !toggle;
    ans[toggle][0] = ans[!toggle][0] + ans[!toggle][1];
    ans[toggle][1] = ans[!toggle][0];

  }
  printf("%lld", ans[toggle][0] + ans[toggle][1]);

  return 0;
}
