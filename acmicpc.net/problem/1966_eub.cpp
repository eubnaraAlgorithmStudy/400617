#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

typedef struct Doc {
    int idx;
    int pri;
} DOC;

int getMax(vector<DOC> q) {
    int max = -1;
    for(auto it=q.begin();it != q.end(); it++) {
        max = max > it->pri ? max : it->pri;
    }
    return max;
}

int main(void) {
    int T;
    scanf("%d", &T);
    while(T--) {
        int N,M;
        scanf("%d %d", &N, &M);
        vector<DOC> q; 
        for(int i=0;i<N;i++) {
            DOC cur;
            cur.idx = i;
            scanf("%d", &cur.pri);
            q.push_back(cur);
        }
        int order = 0;
        int max = getMax(q);
        while(!q.empty()) {
            DOC cur = q.front();
            q.erase(q.begin());
            if (cur.pri >= max) {
                order = order + 1;
                if (cur.idx == M) {
                    printf("%d\n", order);
                    break;
                }
                max = getMax(q);
            } else {
                q.push_back(cur);
            }
        }
    }
    return 0;
}
