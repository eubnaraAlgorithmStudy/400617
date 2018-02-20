#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int INF = 2147483647;

typedef struct Vertex {
    int r, c; // row, column
    int lu; // luffy
    Vertex(int R, int C, int Lu): r(R), c(C), lu(Lu) {}
} VERTEX;

bool operator<(const VERTEX& x, const VERTEX& y) {
    return x.lu > y.lu;
}
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int cave[125][125];
int luffy[125][125];

int dijkstra(int size) {
    bool completed[125][125];
    memset(completed, false, sizeof(bool) * size * 125);
    for(int i=0;i<size;i++) {
        for(int j=0;j<size;j++) {
            luffy[i][j] = INF;
        }
    }
    luffy[0][0] = cave[0][0];
    priority_queue<VERTEX> pq;
    pq.push(VERTEX(0, 0, luffy[0][0]));
    while(!pq.empty()) {
        VERTEX cur = pq.top();
        pq.pop();
        if(completed[cur.r][cur.c]) {
            continue;
        }
        if(cur.r == size-1 && cur.c == size-1) {
            break;
        }
        for(int i=0;i<4;i++) {
            int nextR = cur.r + dir[i][0];
            int nextC = cur.c + dir[i][1];
            if(nextR < 0 || nextR >= size || nextC < 0 || nextC >= size) {
                continue;
            }
            if(luffy[cur.r][cur.c] + cave[nextR][nextC] < luffy[nextR][nextC]) {
                luffy[nextR][nextC] = luffy[cur.r][cur.c] + cave[nextR][nextC];
                pq.push(VERTEX(nextR, nextC, luffy[nextR][nextC]));
            }
        }
        completed[cur.r][cur.c] = true;
    }
    return luffy[size-1][size-1];
}



int main(void) {
    for(int i=1;;i++) {
        int N;
        scanf("%d", &N);
        if(0 == N) {
            break;
        }
        for(int j=0;j<N;j++) {
            for(int k=0;k<N;k++) {
                scanf("%d", &cave[j][k]);
            }
        }
        printf("Problem %d: %d\n", i, dijkstra(N));
    }

    return 0;
}
