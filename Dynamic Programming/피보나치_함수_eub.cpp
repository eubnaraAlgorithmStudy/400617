// https://www.acmicpc.net/problem/1003

#include <iostream>

int numZero = 0;
int numOne = 0;

void fibonacci(int n) {
  if (n == 0) {
    numZero++;
  } else if (n == 1) {
    numOne++;
  } else {
    fibonacci(n-1);
    fibonacci(n-2);
  }
}

int main(void) {

  int T;
  scanf("%d", &T);
  while (T--) {
    int input;
    numOne = numZero = 0;
    scanf("%d", &input);
    fibonacci(input);
    printf("%d %d\n", numZero, numOne);
  }

  return 0;
}
