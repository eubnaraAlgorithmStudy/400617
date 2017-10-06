#include <iostream>
#include <cstdio>

typedef struct _coord {
  int r;
  int c;
} COORD;

const COORD dir[4] = {
  {-1, 0},
  {0, 1},
  {1, 0},
  {0, -1}
};


int L, N;
COORD moveInfo[1000+1][2];

int main(void) {
  scanf("%d", &L);
  scanf("%d", &N);
  for(int i=0;i<N;i++) {
    scanf("%d", &moveInfo[i][0]);
    char dir;
    scanf("%c", &dir);
    // 0 1 2 3 : 북 동 남 서
    if(dir == 'L') {
      // trick 3을 더하고 % 4 연산을 할 예정
      moveInfo[i][1] = 3;
    } else {
      moveInfo[i][1] = 1;
    }
  }


  return 0;
}
