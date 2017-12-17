#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct _coord {
  long long x;
  long long y;
} COORD;


int L, N;
long long moveInfo[1000+1][2];
COORD curPos;
COORD point[1000+1]; // 직선이 끝나는 점을 저장한다. (0, 0) 에서 시작
COORD endPoint;
int curDir;

long long curTime;
long long limit;


enum DIR {NORTH, EAST, SOUTH, WEST};



const COORD dir[4] = {
  {0, 1},
  {1, 0},
  {0, -1},
  {-1, 0}
};

/*
  - type: 두 직선의 형태
    * 1: - -
    * 2: - |
    * 3: | -
    * 4: | |

*/
bool isCrossed(COORD a0, COORD a1, COORD b0, COORD b1, long long type) {
  // printf("a0(%d, %d), a1(%d, %d)\n", a0.x, a0.y, a1.x, a1.y);
  // printf("b0(%d, %d), b1(%d, %d)\n", b0.x, b0.y, b1.x, b1.y);
  long long up, down, left, right;
  switch(type) {
    case 1:
      if ( a0.y == b0.y) {
        if (b0.x < b1.x) {
          left = b0.x;
          right = b1.x;
        } else {
          left = b1.x;
          right = b0.x;
        }
        /*
          ERR: case 1, 4 부분에서 버그 있었음
        */
        if (a0.x < left && left <= a1.x) {
          endPoint.x = left;
        } else if (right < a0.x && a1.x <= right){
          endPoint.x = right;
        } else {
          break;
        }
        endPoint.y = a0.y;
        return true;
      }
      break;
    case 2:
      if (a0.x < a1.x) {
        left = a0.x;
        right = a1.x;
      } else {
        left = a1.x;
        right = a0.x;
      }
      if (b0.y < b1.y) {
        down = b0.y;
        up = b1.y;
      } else {
        down = b1.y;
        up = b0.y;
      }
      if (left <= b0.x && b0.x <= right) {
          if (down <= a0.y && a0.y <= up) {
            endPoint.y = a0.y;
            endPoint.x = b0.x;
            return true;
          }
      }
      break;
    // | -
    case 3:
      if (b0.x < b1.x) {
        left = b0.x;
        right = b1.x;
      } else {
        left = b1.x;
        right = b0.x;
      }
      if (a0.y < a1.y) {
        down = a0.y;
        up = a1.y;
      } else {
        down = a1.y;
        up = a0.y;
      }
      if (left <= a0.x && a0.x <= right) {
          if (down <= b0.y && b0.y <= up) {
            endPoint.y = b0.y;
            endPoint.x = a0.x;
            return true;
          }
      }
      break;
    // | |
    case 4:
      if ( a0.x == b0.x) {
        if (b0.y < b1.y) {
          down = b0.y;
          up = b1.y;
        } else {
          down = b1.y;
          up = b0.y;
        }
        if (a0.y < down && down <= a1.y) {
          endPoint.y = down;
        } else if (up < a0.y && a1.y <= up){
          endPoint.y = up;
        } else {
          break;
        }
        endPoint.x = a0.x;
        return true;
      }
      break;
  }
  // printf("%d %d %d %d %d\n", up, down, left, right, type);
  return false;
};



void move() {
  // N 번째는 현재 방향대로 그대로 직진할 경우를 뜻함.
  bool crossed = false;
  long long crossedDist = 2147483647;
  for(int i=0; i<=N; i++) {
    // printf("(x, y): (%d, %d)\n", curPos.x, curPos.y);
    COORD newPos;

    newPos.x = curPos.x + dir[curDir].x * moveInfo[i][0];
    newPos.y = curPos.y + dir[curDir].y * moveInfo[i][0];

    point[i+1].x = newPos.x;
    point[i+1].y = newPos.y;

    // 장외가 아니라면, 직선을 만들고, 해당 직선과 지금까지 만들어진 직선과 crossed 인지 확인
    for(int j=0; j<i-1; j++) {
      int type;
      // 짝수라면 가로 직선
      if(j % 2 == 0) {
        type = 1;
      } else {
        type = 2;
      }
      switch(curDir) {
        // 세로 직선
        case NORTH:
        case SOUTH:
          type += 2;
          break;
        // 가로 직선
        case EAST:
        case WEST:
          break;
      }
      /*
        ERR: cross 되는 모든 선분들 중에서 가장 짧은 걸 선택했어야 했음
      */
      if (isCrossed(point[i],point[i+1],point[j],point[j+1], type)) {
        // printf("type: %d\n", type);
        // printf("crossed when (%lld, %lld)\n", endPoint.x, endPoint.y);
        long long tmp = moveInfo[i][0] - abs(newPos.x - endPoint.x + newPos.y - endPoint.y);
        crossedDist = min(crossedDist, tmp);
        crossed = true;
        // curTime += tmp;
        // return;
      }
    }
    if(crossed) {
      curTime += crossedDist;
      return;
    }

    // 장외
    switch(curDir) {
      case NORTH:
        if(newPos.y > limit) {
          curTime += (limit - curPos.y + 1);
          return;
        }
        break;
      case EAST:
        if(newPos.x > limit) {
          curTime += (limit - curPos.x + 1);
          return;
        }
        break;
      case SOUTH:
        if(newPos.y < -limit) {
          curTime += (limit + curPos.y + 1);
          return;
        }
        break;
      case WEST:
        if(newPos.x < -limit) {
          curTime += (limit + curPos.x + 1);
          return;
        }
        break;
    }

    curTime += moveInfo[i][0];
    curDir = (curDir + moveInfo[i][1]) % 4;
    curPos.x = newPos.x;
    curPos.y = newPos.y;
  }
}

int main(void) {
  scanf("%d", &L);
  scanf("%d", &N);
  for(int i=0;i<N;i++) {
    char dir;
    scanf("%llu %c", &moveInfo[i][0], &dir);
    // 0 1 2 3 : 북 동 남 서
    if(dir == 'L') {
      // trick 3을 더하고 % 4 연산을 할 예정
      moveInfo[i][1] = 3;
    } else {
      moveInfo[i][1] = 1;
    }
  }
  moveInfo[N][0] = 2 * 100000000 + 1; // 마지막은 현재 방향대로 직진
  limit = L;
  curPos.x = curPos.y = 0;
  curDir = EAST;
  move();
  printf("%lld\n", curTime);

  return 0;
}
