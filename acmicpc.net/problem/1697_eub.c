#include <stdio.h>

const int max = (100000 + 1) * 3;
const int TRUE = 1;
const int FALSE = 0;
int head = -1;
int tail = -1;
int visited[max];


typedef struct Data {
    int p; //position
    int s; //second
} DATA;
DATA queue[max];


void push(DATA d) {
    tail = tail + 1;
    queue[tail] = d;
}

DATA pop() {
    head = head + 1;
    return queue[head];
}

int empty() {
   return tail == head; 
}



int bfs(int target) {
   // 큐에 데이터가 있으면 꺼내서 다음 경우의 수 탐색하기 
   // 만약에 도착지점이 발견되었다면, 루프를 중지하고 값을 반환한다.
    while (!empty()) {
        DATA cur = pop();
        if (cur.p == target) {
            return cur.s;
        }
        if (visited[cur.p]) {
            continue;
        }
        int cand[3] = {cur.p - 1, cur.p + 1, cur.p * 2};
        for(int i=0;i<3;i++) {
            if(cand[i] < 0 || cand[i] > 100000) {
                continue;
            }
            if(visited[cand[i]]) {
                continue;
            }
            DATA temp;
            temp.p = cand[i];
            temp.s = cur.s + 1;
            push(temp);
        }
        visited[cur.p] = TRUE;
    }
    return -1;
}

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);
    DATA cur;
    cur.p = N;
    cur.s = 0;
    push(cur);
    printf("%d\n", bfs(K));
    return 0;
}
