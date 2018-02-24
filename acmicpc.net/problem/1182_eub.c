#include <stdio.h>
#include <math.h>
int set[20 + 1];
int N, S;
int cnt;

void dfs(int lastSelectedIdx, int sum) {
    
    for(int i=lastSelectedIdx + 1; i<=N; i++) {
        int curSum = sum + set[i];
        if (S == curSum) {
            cnt++;
        }
        dfs(i, curSum);
    }
}

int main(void) {
    
    scanf("%d %d", &N, &S);
    for(int i=1;i<=N;i++) {
        scanf("%d", &set[i]);
    }
    // if empty set is included
    /*
    if (0 == S) {
        cnt++;
    }
    */
    dfs(0, 0);
    printf("%d\n", cnt);
    return 0;
}