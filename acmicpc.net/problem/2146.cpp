#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

const int MAX = 2147483647;
/*
10
1 1 1 0 0 0 0 1 1 1
1 1 1 1 0 0 0 0 1 1
1 0 1 1 0 0 0 0 1 1
0 0 1 1 1 0 0 0 0 1
0 0 0 1 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0

3
*/
int N;
int numOfCont = 0;
int shortest = MAX;
// map 은 대륙을 구분한 내용을 저장한 뒤, 재활용한다.
int map[100][100];
// tmpMap 은 각 대륙에서 다른 대륙 간 거리를 조사할 때 임시로 사용한다.
// memcpy 로 map 을 복사한 뒤 사용
int tmpMap[100][100];
typedef struct _coord {
  int y;
  int x;
} coord;
std::queue<coord> *q;
int isVisited[100][100];


// 같은 대륙은 음수로 매겨진다. -1 -2 -3 순서대로
void spread(int y, int x) {
  // 범위가 넘어가는 경우
  if (x < 0 || x >= N || y < 0 || y >= N) {
    return;
  }
  // 이미 같은 대륙인 것을 확인한 경우
  if (map[y][x] == -numOfCont) {
    return;
  }

  if(map[y][x] == 1) {
      map[y][x] = -numOfCont;
      spread(y-1, x);
      spread(y+1, x);
      spread(y, x-1);
      spread(y, x+1);
  }
}

void categorizeContinent() {
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      if(map[i][j] == 1) {
        numOfCont = numOfCont + 1;
        // spread() 함수를 호출한 뒤, 같은 대륙은 같은 음수로 매겨진다.
        spread(i,j);
        /*
        // 대륙별로 구분되는지 테스트
        printf("--------------\n");
        for(int a=0;a<N;a++) {
          for(int b=0;b<N;b++) {
            printf("%d ", map[a][b]);
          }
          printf("\n");
        }
        printf("--------------\n");
        */
      }
    }
  }
}


void findBoundary(int y, int x) {
  if(isVisited[y][x] || tmpMap[y][x] == 1) {
    return;
  }
  if(y<0 || x<0 || x>=N || y>=N) {
    return;
  }
  isVisited[y][x] = 1;
  if(tmpMap[y][x] == 0) {
    coord loc;
    loc.y = y;
    loc.x = x;
    (*q).push(loc);
    tmpMap[y][x] = 1;
  } else {
    findBoundary(y-1, x);
    findBoundary(y+1, x);
    findBoundary(y, x-1);
    findBoundary(y, x+1);
  }
}


coord dir4[4] = {
  {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};
void findNearCont(int contNum) {
  while(!q->empty()) {

    coord curLoc = q->front();
    q->pop();

    for(int i=0;i<4;i++) {
      int y = curLoc.y - dir4[i].y;
      int x = curLoc.x - dir4[i].x;
      if(y<0 || x<0 || x>=N || y>=N) {
        continue;
      }
      if(isVisited[y][x]) {
        continue;
      } else {
        isVisited[y][x] = 1;
      }
      if(tmpMap[y][x] < 0) {
        if (tmpMap[y][x] != contNum) { // 다른 대륙을 만난 경우
            shortest = std::min(shortest, tmpMap[curLoc.y][curLoc.x]);
            // printf("--------------\n");
            // for(int a=0;a<N;a++) {
            //   for(int b=0;b<N;b++) {
            //     printf("%d ", tmpMap[a][b]);
            //   }
            //   printf("\n");
            // }
            // printf("--------------\n");
            // printf("cur shortest: %d\n",shortest);
            return;
        }
      } else {
        tmpMap[y][x] = tmpMap[curLoc.y][curLoc.x] + 1;
        coord tmpLoc = {y, x};
        q->push(tmpLoc);
      }
    }
  }
}

void calShortestPath(int contNum) {
  // 초기화
  memcpy(tmpMap, map, sizeof(int) * 100 * 100 );
  memset(isVisited, 0, sizeof(int) * 100 * 100);
  std::queue<coord> curQ;
  q = &curQ;
  coord start;
  start.x = 0;
  start.y = 0;
  // starting point 찾기
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      if (tmpMap[i][j] == contNum){
        start.y = i;
        start.x = j;
        goto start;
      }
    }
  }
  start:
  /*
  printf("--------------\n");
  for(int a=0;a<N;a++) {
    for(int b=0;b<N;b++) {
      printf("%d ", tmpMap[a][b]);
    }
    printf("\n");
  }
  printf("--------------\n");
  printf("contNum(%d) starts at: %d %d\n", contNum, start.y, start.x);
  */

  // 퍼져나가며 초기에 이 대륙에 바로 맞닿아 있는 부분을 큐에 넣으며 초기화
  findBoundary(start.y, start.x);

  // 근처 대륙을 찾고, shortest 갱신
  findNearCont(contNum);


}

int main(void) {

  scanf("%d", &N);
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      scanf("%d", &map[i][j]);
    }
  }
  categorizeContinent();
  for(int contNum = 1; contNum <= numOfCont; contNum++) {
    // hack
    // 대륙번호는 음수로 매겼다.
    calShortestPath(-contNum);
  }
  printf("%d\n", shortest);
  return 0;
}
