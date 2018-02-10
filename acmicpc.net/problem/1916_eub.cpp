#include <queue>
#include <iostream>
using namespace std;

const int INF = 2147483647;
int n, m;
int s, e;

typedef struct To {
    int v;
    int w;
} TO;

typedef struct Vertex {
    int v;
    int cost;
    Vertex(int v, int cost): v(v), cost(cost) {}
} VERTEX;

bool operator<(VERTEX a, VERTEX b){
    return a.cost > b.cost;
}

vector<TO> * edges = new vector<TO>[100000 + 1];
int main(void) {
    scanf("%d", &n);
    scanf("%d", &m);
    int * cost = new int[n+1];
    bool * completed = new bool[n+1];
    priority_queue<Vertex> pq;
    for (int i=0;i < m; i++) {
        int from;
        TO to;
        scanf("%d %d %d", &from, &to.v, &to.w);
        if (s == to.v) {
            continue;
        }
        edges[from].push_back(to);
    }
    scanf("%d %d", &s, &e);

    // initialize
    for (int i=1;i<=n;i++) {
        completed[i] = false;
        cost[i] = INF;
    }
    cost[s] = 0;
    pq.push(Vertex(s, 0));
    while(!pq.empty()) {
        Vertex cur = pq.top();
        pq.pop();
        if(completed[cur.v]) {
            continue;
        } else {
            if (completed[e]) {
                break;
            }
            completed[cur.v] = true;
        }
        vector<TO> edge = edges[cur.v];
        for (auto it = edges[cur.v].begin(); it != edges[cur.v].end(); it++) {
            if (cur.cost + it->w < cost[it->v]) {
                cost[it->v] = cur.cost + it->w;
                if (!completed[it->v]) {
                    pq.push(VERTEX(it->v, cost[it->v]));
                }
            }
        }
    }
    printf("%d\n", cost[e]);

    delete[] cost;
    delete[] edges;
    return 0;
}