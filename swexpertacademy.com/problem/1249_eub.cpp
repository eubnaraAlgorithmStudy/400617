#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
typedef struct Road {
    int row;
    int col;
    int cost;
    Road(int Row, int Col, int Cost): row(Row), col(Col), cost(Cost) {}
} ROAD;

bool operator<(const ROAD &x, const ROAD &y) {
    return x.cost > y.cost;
}

bool isVisited[100+1][100+1];
int map[100+1][100+1];
int cost[100+1][100+1];
const int INF = 2147483647;
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int main(void) {
    int T;
    scanf("%d", &T);
    for(int caseNum=1;caseNum<=T;caseNum++) {
        int N;
        scanf("%d", &N);
        memset(isVisited, false, sizeof(bool) * (100+1) * N);
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                scanf("%1d", &map[i][j]);
                cost[i][j] = INF;
            }
        }
        priority_queue<ROAD> q;
        q.push(ROAD(0, 0, 0));
        while(!q.empty()) {
            ROAD cur = q.top();
            q.pop();
            for(int i=0;i<4;i++) {
                int nextR = cur.row + dir[i][0];
                int nextC = cur.col + dir[i][1];
                if(nextR < 0 || nextR >= N || nextC < 0 || nextC >= N) {
                    continue;
                }
                if(isVisited[nextR][nextC]) {
                    continue;
                }
                if (cur.cost + map[nextR][nextC] < cost[nextR][nextC]) {
                    cost[nextR][nextC] = cur.cost + map[nextR][nextC];
                    q.push(ROAD(nextR, nextC, cost[nextR][nextC]));
                }
            }
            isVisited[cur.row][cur.col] = true;            
        }
        printf("#%d %d\n", caseNum, cost[N-1][N-1]);
    }

    return 0;
}