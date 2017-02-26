#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;


int c;
int m;
long long eVal;
char e[15];
int sortedE[15];
int len;

// 초기화 필요
int taken;

///////////////////////
//int cache[1<<16][10][2];
int cache[1<<16][20][2];

int cmpFunc (const void *a, const void *b) {
  return (*(int*)a - *(int*)b);
}


int solve(int curIdx, int mod, bool pass, int taken) {
  if(curIdx == len) {
    ////////////
    return pass && mod == 0;
  }
  int& ret = cache[taken][mod][pass];
  if(ret != -1)
    return ret;
/////////////////
  ret = 0;
  // int limit = 9;
  // if(pass == false) {
  //   limit = e[curIdx];
  // }
  for(int i=0; i<len; i++) {
    /*
      1 == true (true)
      2 == true (false)
    */
    if((taken & (1 << i)) > 0) {
      continue;
    }
    if(!pass && e[curIdx] < sortedE[i]) {
      continue;
    }
    if(0 < i && sortedE[i] == sortedE[i-1] && ((taken & (1 << (i-1)) ) == false) ) {
      continue;
    }
    ret += (solve(curIdx+1, (mod * 10 + sortedE[i]) % m, pass || (sortedE[i] < e[curIdx]), taken | (1 << i))) % 1000000007;
  }
  return ret;
}


int main(void) {

  scanf("%d", &c);

  while(c--) {
    memset(cache, -1, sizeof(int)*(1<<16)*20*2);
    taken = 0;

    scanf("%lld", &eVal);
    scanf("%d", &m);
    len = sprintf(e, "%lld", eVal);
    for(int i=0; i<len; i++) {
      sortedE[i] = e[i] -= '0';
    }
    qsort(sortedE, len, sizeof(int), cmpFunc);
    printf("%d\n", solve(0,0,0,0));


  }


  return 0;
}
