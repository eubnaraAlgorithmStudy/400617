#include <iostream>
#include <cstdio>

int N,M,x,y,K;
int valOfDie[6+1];
enum Dir { EAST=1, WEST, NORTH, SOUTH };
typedef struct _coord {
  int x;
  int y;
} COORD;
int map[20+1][20+1];
COORD curPos;
COORD move[5] = {
  {0, 0},
  {0, 1},
  {0, -1},
  {-1, 0},
  {1, 0}
};

void rollDie(int dir) {
  curPos.x += move[dir].x;
  curPos.y += move[dir].y;
  if(curPos.x < 0 || curPos.x >= N || curPos.y < 0 || curPos.y >=M) {
    curPos.x -= move[dir].x;
    curPos.y -= move[dir].y;
    return;
  }

  int copy;
  switch(dir) {
    case EAST:
      copy = valOfDie[3];
      valOfDie[3] = valOfDie[1];
      valOfDie[1] = valOfDie[4];
      valOfDie[4] = valOfDie[6];
      break;
    case WEST:
      copy = valOfDie[4];
      valOfDie[4] = valOfDie[1];
      valOfDie[1] = valOfDie[3];
      valOfDie[3] = valOfDie[6];
      break;
    case NORTH:
      copy = valOfDie[2];
      valOfDie[2] = valOfDie[1];
      valOfDie[1] = valOfDie[5];
      valOfDie[5] = valOfDie[6];
      break;
    case SOUTH:
      copy = valOfDie[5];
      valOfDie[5] = valOfDie[1];
      valOfDie[1] = valOfDie[2];
      valOfDie[2] = valOfDie[6];
      break;
  }
  if (map[curPos.x][curPos.y] == 0) {
    map[curPos.x][curPos.y] = copy;
  } else {
    copy = map[curPos.x][curPos.y];
    map[curPos.x][curPos.y] = 0;
  }
  valOfDie[6] = copy;
  printf("%d\n", valOfDie[1]);
}

int main(void) {
  scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      scanf("%d", &map[i][j]);
    }
  }
  curPos.x = x;
  curPos.y = y;
  for(int i=0;i<K;i++) {
    int dir;
    scanf("%d", &dir);

    rollDie(dir);
    // printf("-------------\n");
    // printf("  %d\n", valOfDie[2]);
    // printf("%d %d %d\n", valOfDie[4], valOfDie[1], valOfDie[3]);
    // printf("  %d\n", valOfDie[5]);
    // printf("  %d\n", valOfDie[6]);
    // printf("-------------\n");
  }
  return 0;
}
