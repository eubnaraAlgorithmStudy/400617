#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int INF = 2147483647;
int N, E;
bool completed[800+1];

typedef struct Vertex {
    int v;
    int w;
    Vertex(int V, int W): v(V), w(W) {}
} VERTEX;

vector<VERTEX> edges[800+1];

bool operator<(const VERTEX& x, const VERTEX& y) {
    return x.w > y.w;
}

int dijkstra(int s, int e) {
    int cost[800+1];
    priority_queue<VERTEX> pq;
    // I made an error on hits line.
    // "completed" should be initialized with the length of not N but N+1
    memset(completed, false, sizeof(bool) * (N + 1));
    for(int i=1;i<=N;i++) {
        cost[i] = INF;
    }
    cost[s] = 0;
    pq.push(VERTEX(s, 0));

    while(!pq.empty()) {
        VERTEX cur = pq.top();
        pq.pop();
        if(completed[cur.v]) {
            continue;
        }
        if(cur.v == e) {
            break;
        }
        for(auto it = edges[cur.v].begin();it != edges[cur.v].end(); it++) {
            if (cost[cur.v] + it->w < cost[it->v]) {
                cost[it->v] = cost[cur.v] + it->w;
                pq.push(VERTEX(it->v, cost[it->v]));
            }
        }
        completed[cur.v] = true;
    }
    return cost[e];
}

int main(void) {
    scanf("%d %d", &N, &E);
    for(int i=0;i<E;i++) {
        int from, to, w;
        scanf("%d %d %d", &from, &to, &w);
        edges[from].push_back(VERTEX(to, w));
        edges[to].push_back(VERTEX(from, w));
    }
    int path[2][4] = {{1,0,0,N},{1,0,0,N}};
    int m1, m2;
    scanf("%d %d", &m1, &m2);
    path[0][1] = path[1][2] = m1;
    path[0][2] = path[1][1] = m2;
    int dist[2] = {0, 0};
    for(int i=0;i<2;i++) {
        for (int j=0;j<3;j++) {
            int temp = dijkstra(path[i][j], path[i][j+1]);
            if (INF == temp) {
                dist[i] = INF;
                break;
            } else {
                dist[i] += temp;
            }
        }
    }
    int ans = dist[0] < dist[1] ? dist[0] : dist[1];
    if (INF == ans) {
        printf("-1\n");
    } else {
        printf("%d\n", ans);
    }
    return 0;
}
