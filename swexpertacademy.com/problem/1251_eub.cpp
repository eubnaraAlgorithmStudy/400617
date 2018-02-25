#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
#include <limits>

using namespace std;
typedef struct Coord {
    int x, y;
} COORD;

typedef struct Edge {
    int from, to;
    double weight;
    Edge(int From, int To, double Weight): from(From), to(To), weight(Weight) {}
} EDGE;

double dists[1000+1][1000+1];

bool operator<(const EDGE& x, const EDGE& y) {
    return x.weight > y.weight;
}


double ans;
COORD coord[1000 + 1];
bool isVisited[1000 + 1];

int main(void) {
    int T;
    scanf("%d", &T);
    for(int caseNum = 1; caseNum <= T; caseNum++) {
        int N;
        double E;
        // initialize
        ans = 0.0;
        scanf("%d", &N);
        memset(isVisited, false, sizeof(bool) * N);
        for(int i=0;i<N;i++) {
            scanf("%d", &coord[i].x);
        }
        for(int i=0;i<N;i++) {
            scanf("%d", &coord[i].y);
        }
        scanf("%lf", &E);
        priority_queue<EDGE> q;
        // edge 거리 미리 계산
        for(int i=0;i<N;i++) {
            for(int j=i+1;j<N;j++) {
                double dist = pow(coord[i].x - coord[j].x , 2.0) + pow(coord[i].y - coord[j].y , 2.0);
                dists[i][j] = dists[j][i] = dist;
            }
        }
        EDGE cur(0, 0, numeric_limits<double>::infinity());
        for(int i=1;i<N;i++) {
            if (cur.weight > dists[cur.from][i]) {
                cur.weight = dists[cur.from][i];
                cur.to = i;
            }
        }
        isVisited[cur.from] = true;
        q.push(cur);
        while(!q.empty()) {
            cur = q.top();
            q.pop();
            if(isVisited[cur.from] && isVisited[cur.to]) {
                continue;
            }
            if((!isVisited[cur.from]) && (!isVisited[cur.to])) {
                q.push(cur);
                continue;
            }
            isVisited[cur.from] = isVisited[cur.to] = true;
            int froms[2] = {cur.from, cur.to};
            for(int i=0;i<2;i++) {
                int from = froms[i];
                for(int j=0;j<N;j++) {
                    if(from == j || isVisited[j]) {
                        continue;
                    } else {
                        q.push(EDGE(from, j, dists[from][j]));
                    }
                }
            }
            ans += cur.weight;
        }
        printf("#%d %lld\n", caseNum, (long long)(ans * E + 0.5));
    }
    return 0;
}
