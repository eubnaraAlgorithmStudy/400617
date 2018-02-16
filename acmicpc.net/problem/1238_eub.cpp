#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int INF = 2147483647;
int N, M, X;
int cost[1000+1];
bool completed[1000+1];

typedef struct Edge {
    int to;
    int c;
} EDGE;

vector<EDGE> edges[1000+1];

typedef struct Vertex {
    int v;
    int d;
    Vertex(int V, int D): v(V), d(D) {}
} VERTEX;

bool operator<(const VERTEX& x, const VERTEX& y) {
    return x.d > y.d;
}

int dijkstra(int start, int end) {
    for(int i=1;i<=N;i++) {
        cost[i] = INF;
    }
    memset(completed, false, sizeof(bool) * (N+1));
    cost[start] = 0;
    priority_queue<VERTEX> pq;
    pq.push(VERTEX(start, 0));
    while(!pq.empty()) {
        VERTEX cur = pq.top();
        pq.pop();
        if (completed[cur.v]) {
            continue;
        } else if (cur.v == end) { 
            break;
        } else {
            completed[cur.v] = true;
        }
        for(auto it = edges[cur.v].begin(); it != edges[cur.v].end(); it++) {
            if(cost[cur.v] + it->c < cost[it->to]) {
                cost[it->to] = cost[cur.v] + it->c;
                pq.push(VERTEX(it->to, cost[it->to]));
            }
        }
    }
    return cost[end];
}

int main(void) {
    scanf("%d %d %d", &N, &M, &X);
    for(int i=0;i<M;i++) {
        int from;
        EDGE edge;
        scanf("%d %d %d", &from, &edge.to, &edge.c);
        edges[from].push_back(edge);
    }
    int highest = 0;
    for(int i=1; i<=N; i++) {
        int dist;
        dist = dijkstra(i, X);
        dist += dijkstra(X, i);
        highest = highest < dist ? dist : highest;
    }
    printf("%d\n", highest);

    return 0;
}
