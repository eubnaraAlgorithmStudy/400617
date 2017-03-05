#include <cstring>
#include <iostream>

using namespace std;

int c, n, m, k;
double cache[101][101];

double prepCal(int a, int b) {
  double &ret = cache[a][b];
  if (ret != -1)
    return ret;

  ret = 0;

  if (a == 0 || b == 0) {
    if (a != 0) {
      ret = prepCal(a - 1, b);
    }
    if (b != 0) {
      ret = prepCal(a, b - 1);
    }
    ret = 1;
  } else {
    ret += prepCal(a - 1, b);
    ret += prepCal(a, b - 1);
  }

  return ret;
}

void printKthWord(int k) {
  if (prepCal(n, m) < k) {
    printf("NONE\n");
    return;
  }
  int a = n;
  int b = m;
  printf("a, b = %d %d\n", a, b);
  while (a != 0 && b != 0) {
    if (cache[a - 1][b] >= k) {
      printf("a");
      a--;
    } else {
      printf("b");
      //TODO:
      k = k - cache[a - 1][b];
      b--;
    }
  }
  char c;
  int num;
  if (a > 0) {
    c = 'a';
    num = a;
  } else {
    c = 'b';
    num = b;
  }
  for (int i = 0; i < num; i++) {
    printf("%c", c);
  }
  printf("\n");
}

int main(void) {
  scanf("%d", &c);

  for (int i = 0; i < c; i++) {
    scanf("%d %d %d", &n, &m, &k);
    memset(cache, -1, sizeof(double) * 101 * 101);
    printKthWord(k);
  }

  return 0;
}
