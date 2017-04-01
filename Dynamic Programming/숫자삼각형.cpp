#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int *curRow = new int[500];
int *newRow = new int[500];
int main(void) {
  int n;
  scanf("%d", &n);
  int row = 1;
  memset(curRow, 0, sizeof(int) * 500);
  memset(newRow, 0, sizeof(int) * 500);
  while(row <= n) {
    for (int i=0; i < row; i++) {
      scanf("%d", &newRow[i]);
    }
    for (int i=0; i < row; i++) {
      if (i == 0) newRow[i] += curRow[i];
      else if (i == row-1) {
        newRow[i] += curRow[i-1];
      } else {
        newRow[i] += max(curRow[i-1], curRow[i]);
      }
    }
    int * tmp = newRow;
    newRow = curRow;
    curRow = tmp;
    row += 1;
  }
  int max = -1;
  for (int i=0; i < n; i++) {
    if (max < curRow[i]) {
      max = curRow[i];
    }
  }
  printf("%d\n", max);

  return 0;
}
