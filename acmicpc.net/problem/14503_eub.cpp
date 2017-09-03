#include <iostream>
#include <cstdio>
#include <cstring>

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


int isCompleted(int r, int c) {
  int ret = 1;
  for(int i=0; i<4; i++) {
    int nextR = r + dir[i].r;
    int nextC = c + dir[i].c;
    if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= M) {
      continue;
    }
    if (map[nextR][nextC] == 0 && !isVisited[nextR][nextC]) {
      ret=0;
      break;
    }
  }
  return ret;
}
/*
  현재 위치를 청소한 후에
  4방향이 모두 청소가 되었거나 벽인 경우에는 그 방향대로 뒤로 돌아온다.
*/
void clean() {
  while(true) {
    isVisited[r][c] = 1;

    // 네 방향 모두 청소가 이미 되어있거나 벽인 경우 확인
    if(isCompleted(r, c)) {
      int oppositeDir = (d + 2) % 4;
      int backR = r + dir[oppositeDir].r;
      int backC = c + dir[oppositeDir].c;
      // 경계를 넘어가서 후진을 할 수 없는 경우, 작동을 멈춘다.
      if (backR < 0 || backR >= N || backC < 0 || backC >= M) {
        break;
      }
      // 벽으로 막혀서 후진을 할 수 없는 경우, 작동을 멈춘다.
      if(map[backR][backC] == 1) {
        break;
      } else {
        // 후진을 할 수 있는 경우, r c 를 갱신하고 d(방향)은 그대로 유지한다.
        // "방향은 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다."
        r = backR;
        c = backC;
        continue;
      }
    }

    // 왼쪽방향 확인해 보기
    int nextDir = (d + 3) % 4;
    int nextR = r + dir[nextDir].r;
    int nextC = c + dir[nextDir].c;

    // 장외인 경우 무시
    if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= M) {
      continue;
    }

    // 벽으로 막혀있거나 이미 방문한 경우 무시
    if (map[nextR][nextC] == 1 || isVisited[nextR][nextC]) {
      d = nextDir;
      continue;
    }

    // 청소를 해야하는 경우, 청소한 횟수를 하나 늘리며, 해당 위치와 방향으로 변경한다.
    count = count + 1;
    r = nextR;
    c = nextC;
    d = nextDir;

  }
}

int main(void) {

  scanf("%d %d", &N, &M);
  scanf("%d %d %d", &r, &c, &d);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      scanf("%d", &map[i][j]);
    }
  }
  clean();
  printf("%d\n", count);

  return 0;
}


/*
2번째 인풋이 57이 나오는 이유.(59가 아니라)

1111111111
1222222221
1222111121
1221122221
1211222201
1222222221
1222220121
1222221121
1222221121
1222222221
1111111111

*/
