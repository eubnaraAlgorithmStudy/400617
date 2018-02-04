#include <cstdio>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 2147483647;

typedef struct Edge {
    int to;
    int w;
    Edge(int To, int W) : to(To), w(W) { }
} EDGE;

typedef struct Vertex {
    int v;
    int d;
    Vertex(int V, int D) : v(V), d(D) { }
    bool operator<(const Vertex& a) {
        return (a.d) > d;
    }
    bool operator=(const Vertex& a) {
        v = a.v;
        d = a.d;
    }

} VERTEX;

bool operator<(VERTEX a, VERTEX b){
    return a.d > b.d;
}


// struct comp {
//   bool operator()(const VERTEX& a,const VERTEX& b) const{
//     return *a.d < *b.d;
//   }
// };
bool isCompleted[20000+1];

int main(void) {
    int V, E, start;
    scanf("%d %d", &V, &E);
    scanf("%d", &start);
    int dist[20000+1];
    list<EDGE> edge[300000+1];
    priority_queue<VERTEX> q;
    for(int i = 1; i <= V; i++) {
        dist[i] = INF;
        if (start != i) {
            q.push(VERTEX(i, dist[i]));
        }
    }
    
    for(int i = 0; i < E; i++) {
        int from, to, w;
        scanf("%d %d %d", &from, &to, &w);
        if (start == to) {
            continue;
        } else {
            edge[from].push_back(EDGE(to, w));
        }
    }
    q.push(VERTEX(start, 0));
    dist[start] = 0;
    while(!q.empty()) {
        VERTEX cur = q.top();
        q.pop();
        if(isCompleted[cur.v]) {
            continue;    
        } else {
            isCompleted[cur.v] = true;
        }
        for(auto it = edge[cur.v].begin(); it != edge[cur.v].end(); it++) {
            if (0 <= cur.d + it->w && cur.d + it->w < dist[it->to]) {
                dist[it->to] = cur.d + it->w;
                if (!isCompleted[it->to]) {
                    q.push(VERTEX(it->to, dist[it->to]));
                }
            }
        }
    }

    for(int i=1;i<=V;i++) {
        if(INF == dist[i]) {
            printf("INF\n");
        } else {
            printf("%d\n", dist[i]);
        }
    }

    return 0;
}