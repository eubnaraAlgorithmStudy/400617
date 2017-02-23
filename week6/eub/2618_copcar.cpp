#include <iostream>
#include <cmath>
#include <cstring>

int n, w;
int cache[1000+1][1000+1];
int incident[1000+1][2];
int p[1000+1][1000+1][2];

int dist(int inc1, int inc2) {
  return abs(incident[inc1][0] - incident[inc2][0]) + abs(incident[inc1][1] - incident[inc2][1]);
}


void dp() {

  incident[0][0] = incident[0][1] = 1;
  cache[1][0] = dist(0, 1);

  incident[0][0] = incident[0][1] = n;
  cache[0][1] = dist(0, 1);

  for(int i=2; i <= w; i++) {
    //cop1
    for(int j=0; j <= i - 2; j++) {
      cache[i][j] = cache[i-1][j] + dist(i, i-1);
      p[i][j][0] = i-1;
      p[i][j][1] = j;
    }
    incident[0][0] = incident[0][1] = 1;
    for(int j=0; j<= i-2; j++) {
      if(cache[i][i-1] > cache[j][i-1] + dist(i, j)) {
        cache[i][i-1] = cache[j][i-1] + dist(i, j);
        p[i][i-1][0] = j;
        p[i][i-1][1] = i-1;
      }
    }

    //cop2
    for(int j=0; j <= i - 2; j++) {
      cache[j][i] = cache[j][i-1] + dist(i, i-1);
      p[j][i][0] = j;
      p[j][i][1] = i-1;
    }
    incident[0][0] = incident[0][1] = n;
    for(int j=0; j<= i-2; j++) {
      if(cache[i-1][i] > cache[i-1][j] + dist(i, j)) {
        cache[i-1][i] = cache[i-1][j] + dist(i, j);
        p[i-1][i][0] = i-1;
        p[i-1][i][1] = j;
      }
    }
  }


}

int max(int x, int y) {
  return x < y ? y : x;
}

void printOrder(int x, int y) {
  // basecase
  if(max(x,y) == 1) {
    if(x > y) {
      printf("%d\n",1);
    }
    else {
      printf("%d\n",2);
    }
    return;
  }

  printOrder(p[x][y][0], p[x][y][1]);

  if(x > y){
    printf("%d\n", 1);
  } else {
    printf("%d\n", 2);
  }

}


int main(void) {
  int minCost = 987654321;
  int lastX, lastY;
  memset(cache, 127, 1001 * 1001);

  scanf("%d", &n);
  scanf("%d", &w);

  for(int i = 1; i <= w; i++) {
    scanf("%d %d", &incident[i][0], &incident[i][1]);
  }

  dp();

  for(int i=0; i<w; i++) {
    if(minCost > cache[i][w]) {
      minCost = cache[i][w];
      lastX = i;
      lastY = w;
    }
    if(minCost > cache[w][i]) {
      minCost = cache[w][i];
      lastX = w;
      lastY = i;
    }
  }

  printf("%d\n",minCost);
  printOrder(lastX, lastY);

  return 0;
}
