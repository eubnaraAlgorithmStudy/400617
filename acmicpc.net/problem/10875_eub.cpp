#include <iostream>
#include <cstdio>
#include <cmath>


typedef struct _coord {
  int x;
  int y;
} COORD;


int L, N;
int moveInfo[1000+1][2];
COORD curPos;
COORD point[1000+1]; // 직선이 끝나는 점을 저장한다. (0, 0) 에서 시작
COORD endPoint;
int curDir;

int curTime;
int limit;


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
bool isCrossed(COORD a0, COORD a1, COORD b0, COORD b1, int type) {
  int up, down, left, right;
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
        if (a0.x < left) {
          endPoint.x = left;
        } else {
          endPoint.x = right;
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
      if (left <= b0.x || b0.x <= right) {
          if (down <= a0.y || a0.y <= up) {
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
      if (left <= a0.x || a0.x <= right) {
          if (down <= b0.y || b0.y <= up) {
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
        if (a0.y < down) {
          endPoint.y = down;
        } else {
          endPoint.y = up;
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
  for(int i=0; i<N; i++) {
    // printf("(x, y): (%d, %d)\n", curPos.x, curPos.y);
    // 장외
    switch(curDir) {
      case NORTH:
        if(curPos.y + moveInfo[i][0] > limit) {
          curTime += (limit - curPos.y + 1);
          return;
        }
        break;
      case EAST:
        if(curPos.x + moveInfo[i][0] > limit) {
          curTime += (limit - curPos.x + 1);
          return;
        }
        break;
      case SOUTH:
        if(curPos.y - moveInfo[i][0] < -limit) {
          curTime += (limit + curPos.y + 1);
          return;
        }
        break;
      case WEST:
        if(curPos.x - moveInfo[i][0] < -limit) {
          curTime += (limit + curPos.x + 1);
          return;
        }
        break;
    }
    curPos.x = curPos.x + dir[curDir].x * moveInfo[i][0];
    curPos.y = curPos.y + dir[curDir].y * moveInfo[i][0];

    point[i+1].x = curPos.x;
    point[i+1].y = curPos.y;

    // 장외가 아니라면, 직선을 만들고, 해당 직선과 지금까지 만들어진 직선과 crossed 인지 확인
    for(int j=0; j<i-1; j++) {
      int type;
      // 짝수라면 가로 직선
      if(j % 2 == 0) {
        type = 1;
      } else {
        type = 3;
      }
      switch(curDir) {
        // 세로 직선
        case NORTH:
        case SOUTH:
          type += 1;
          break;
        // 가로 직선
        case EAST:
        case WEST:
          break;
      }
      if (isCrossed(point[i],point[i+1],point[j],point[j+1], type)) {
        // printf("crossed when (%d, %d)\n", endPoint.x, endPoint.y);
        int tmp = moveInfo[i][0] - abs(curPos.x - endPoint.x + curPos.y - endPoint.y);
        curTime += tmp + 1;
        return;
      }
    }
    curTime += moveInfo[i][0];
    curDir = (curDir + moveInfo[i][1]) % 4;
  }
}

int main(void) {
  scanf("%d", &L);
  scanf("%d", &N);
  for(int i=0;i<N;i++) {
    char dir;
    scanf("%d %c", &moveInfo[i][0], &dir);
    // 0 1 2 3 : 북 동 남 서
    if(dir == 'L') {
      // trick 3을 더하고 % 4 연산을 할 예정
      moveInfo[i][1] = 3;
    } else {
      moveInfo[i][1] = 1;
    }
  }
  // moveInfo[N][0] = 2 * 100000000 + 1; // 마지막은 현재 방향대로 직진
  limit = L;
  curPos.x = curPos.y = 0;
  curDir = EAST;
  move();
  printf("%d\n", curTime);

  return 0;
}
