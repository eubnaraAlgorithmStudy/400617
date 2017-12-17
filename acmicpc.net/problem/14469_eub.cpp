#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct _cow {
  int arriveTime;
  int scanTime;
} COW;

bool comparator (COW i, COW j) {
    return i.arriveTime < j.arriveTime;
}

COW cow[1000000];

int main(void) {
  int N;
  scanf("%d", &N);
  for(int i=0; i<N; i++) {
    scanf("%d %d", &cow[i].arriveTime, &cow[i].scanTime);
  }
  sort(cow, cow+N, comparator);

  int curTime = 0;
  for(int i=0;i<N;i++) {
    if (curTime < cow[i].arriveTime) {
      curTime = cow[i].arriveTime + cow[i].scanTime;
    } else {
      curTime += cow[i].scanTime;
    }
  }
  printf("%d\n", curTime);




  return 0;
}
