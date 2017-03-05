#include <cstring>
#include <iostream>

//error: 이 값으로 모듈러 연산을 하면, cache[][]의 최대값은 100000000이 아니라 그보다 1 작은 99999999가 된다..
//const int K_MAX = 100000000;
const int K_MAX = 100000001;



using namespace std;

int c, n, m, k;
int cache[101][101];

int prepCal(int a, int b) {
  int &ret = cache[a][b];
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
  //error: ret %= K_MAX; 로 하면 답이 틀리다.
  //왜냐하면, 최대값이 채워지는 게 아니라, 나머지가 채워지므로 K_MAX보다 작은 값이 들어갈 수도 있고,
  //이는 원하는 동작이 아니다.
  //printKthWord()에서 prepCal(n, m)을 호출하였을 때, 숫자가 많아서 K_MAX보다 당연히 훨씬 많은데
  //잘못된 계산으로 NONE이 출력되었었다.
  if(ret > K_MAX)
    ret = K_MAX;

  return ret;
}

void printKthWord(int k) {
  if (prepCal(n, m) < k) {
    printf("NONE\n");
    return;
  }
  int a = n;
  int b = m;
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
    if(n == 0 && m == 0) {
      printf("NONE\n");
      continue;
    }
    memset(cache, -1, sizeof(int) * 101 * 101);
    printKthWord(k);
  }

  return 0;
}
