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
    int* d;
    Vertex(int V, int* D) : v(V), d(D) { }
    bool operator<(const Vertex& a) {
        return (a.d) < d;
    }
    bool operator=(const Vertex& a) {
        v = a.v;
        d = a.d;
    }

} VERTEX;



bool comp(const VERTEX& a, const VERTEX& b) {
    return (a.d) > (b.d);
}



int main(void) {
    int V, E, start;
    scanf("%d %d", &V, &E);
    scanf("%d", &start);
    int dist[20000+1];
    list<EDGE> edge[300000+1];
    vector<VERTEX> q;
    for(int i = 1; i <= V; i++) {
        dist[i] = INF;
        q.push_back(VERTEX(i, &dist[i]));
    }
    
    for(int i = 0; i < E; i++) {
        int from, to, w;
        scanf("%d %d %d", &from, &to, &w);
        if (start == from && w < dist[to]) {
            dist[to] = w;
        } else if (start == to) {
            continue;
        } else {
            edge[from].push_back(EDGE(to, w));
        }
    }

    dist[start] = 0;
    while(!q.empty()) {
        make_heap(q.begin(), q.end());
        VERTEX cur = q.front();
        pop_heap(q.begin(), q.end()); q.pop_back();
        for(auto it = edge[cur.v].begin(); it != edge[cur.v].end(); it++) {
            if (0 <= *cur.d + it->w && *cur.d + it->w < dist[it->to]) {
                dist[it->to] = *cur.d + it->w;
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