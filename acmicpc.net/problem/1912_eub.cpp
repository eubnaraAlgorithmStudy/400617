#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

/*
 * 10 -4 3 1 5 6 -35 12 21 -1 에서
 * 처음에 biggest 는 10 이고,
 *     6 3 1 5 6 -35 12 21 -1
 * 또는,
 *    -4 3 1 5 6 -35 12 21 -1
 *  중에서 선택한다고 볼 수 있다.
 * 6 3 1 5 6 -35 12 21 -1 이 선택될 것이고,
 * 이는
 *   9 1 5 6 -35 12 21 -1
 * 또는,
 *   3 1 5 6 -35 12 21 -1
 * 중에서 선택하는 꼴
 * 이렇게 진행하는 과정에서, biggest 는 확인하며 갱신
 */

int val[100000];
int biggest = -1001;
int main(void) {
  int n;
  int sum = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &val[i]);
  }
  for (int i = 0; i < n; i++) {
    if (sum + val[i] < val[i]) {
      sum = val[i];
      biggest = max(biggest, sum);
    } else {
      sum += val[i];
      biggest = max(biggest, sum);
    }
  }
  printf("%d\n", biggest);
  return 0;
}
