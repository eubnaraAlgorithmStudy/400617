#include <iostream>
using namespace std;
 
int heap[100000 + 1];
 
int last;
 
void heapify(int cur) {
    if (last <= 1) {
        return;
    }
    int left = cur << 1;
    int right = left + 1;
    int curValue = heap[cur];
    while (left <= last) {
        int biggerIdx;
        if (last == left) {
            biggerIdx = left;
        } else {
            biggerIdx = heap[left] < heap[right] ? right : left;
        }
        if (curValue < heap[biggerIdx]) {
            heap[cur] = heap[biggerIdx];
            cur = biggerIdx;
        } else {
            break;
        }
        left = cur << 1;
        right = left + 1;
    }
    heap[cur] = curValue;
}
 
void push(int a) {
    last = last + 1;
    heap[last] = a;
    for(int i = last / 2; i>=1;i = i / 2) {
        heapify(i);
    }
}
 
int pop() {
    if (0 == last) {
        return -1;
    } 
    int ret = heap[1];
    heap[1] = heap[last];
    last = last - 1;
    heapify(1);
    return ret;
}
const int PUSH = 1;
const int POP = 2;
 
 
 
int main(void) {
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        last = 0;
        int numOfOps;
        printf("#%d", i);
        scanf("%d", &numOfOps);
        for(int j=0;j<numOfOps;j++) {
            int opcode, val;
            scanf("%d", &opcode);
            switch(opcode) {
                case PUSH:
                    scanf("%d", &val);
                    push(val);
                    break;
                case POP:
                    printf(" %d", pop());
                    break;
            }
        }
        printf("\n");
    }
    return 0;
}
