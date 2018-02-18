#include <iostream>
#include <queue>
using namespace std;

typedef struct Data {
    int p;
    int s;
    Data(int P, int S): p(P), s(S) {}
} DATA;

const int MAX = (100000 + 1 ) * 3;
queue<DATA> q;
bool visited[MAX];

int bfs(int target) {
    while (!q.empty()) {
        DATA cur = q.front();
        q.pop();
        if(cur.p == target) {
            return cur.s;
        }
        int cand[3] = {cur.p - 1, cur.p + 1, cur.p * 2};
        for(int i=0;i<3;i++) {
            if(cand[i] < 0 || cand[i] > 100000) {
                continue;
            }
            if(visited[cand[i]]) {
                continue;
            }
            q.push(DATA(cand[i], cur.s + 1));
        }
        visited[cur.p] = true;
    }
    return -1;
}

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);
    q.push(DATA(N, 0));
    printf("%d\n", bfs(K));
    return 0;
}
