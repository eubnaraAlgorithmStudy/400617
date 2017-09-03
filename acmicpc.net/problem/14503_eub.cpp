#include <iostream>
#include <cstdio>
#include <cstring>

const int NORTH = 0;
const int EAST  = 1;
const int SOUTH = 2;
const int WEST  = 3;

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

int N, M, r, c, d;
int map[50+1][50+1];
int isVisited[50+1][50+1];
int count = 1;
int isEnded;
int lastDir = -1;

void clean(int r, int c, int d) {
  isVisited[r][c] = 1;

  int nextDir = d;

  for(int i = 0; i < 4; i++) {
    if(isEnded) {
      break;
    }
    // 왼쪽방향
    nextDir = (nextDir + 3) % 4;
    int nextR = r + dir[nextDir].r;
    int nextC = c + dir[nextDir].c;
    // printf("%d %d %d\n", nextR, nextC, nextDir);
    if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= M) {
      continue;
    }
    if (isVisited[nextR][nextC]) {
      // printf("isVisited %d %d %d\n", nextR, nextC, nextDir);
      continue;
    }
    if (map[nextR][nextC] == 1) {
      // printf("map==1 %d %d %d\n", nextR, nextC, nextDir);
      isVisited[nextR][nextC] = 1;
      continue;
    } else {
      count = count + 1;
      // printf("%d %d %d\n", nextR, nextC, nextDir);
      clean(nextR, nextC, nextDir);
      lastDir = nextDir;
    }
  }
  // 마지막으로 이동 성공했던 방향의 반대 방향 찾기
  // int oppositeDir = (d + 2) % 4;
  // // 후진을 할 수 있는가?
  // if (map[r + dir[oppositeDir].r][c + dir[oppositeDir].c] == 1) {
  //   printf("%d %d\n", r, c);
  //   isEnded = 1;
  // }

}

int main(void) {

  scanf("%d %d", &N, &M);
  scanf("%d %d %d", &r, &c, &d);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      scanf("%d", &map[i][j]);
    }
  }
  clean(r, c, d);
  printf("%d\n", count);

  return 0;
}
