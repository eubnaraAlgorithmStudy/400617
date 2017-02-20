#include <iostream>
#include <cstring>
#include <cmath>

int n, w;
int coord[1000+2][2];
int chosenCar[1000+5];

int distance(int* a, int* b) {
  int result = abs(a[0] - b[0]);
  result += abs(a[1] - b[1]);
  return result;
}


int calMinDist(int* cop1, int* cop2, int idx, int len) {
    int result = 0;
    int dist_cop1, dist_cop2;
    if(idx == len) {
      return 0;
    }

    chosenCar[idx] = 1;
    dist_cop1 = calMinDist(coord[idx], cop2, idx+1, len) + distance(cop1, coord[idx]);

    chosenCar[idx] = 2;
    dist_cop2 = calMinDist(cop1, coord[idx], idx+1, len) + distance(cop2, coord[idx]);

    if(dist_cop1 < dist_cop2) {
      chosenCar[idx] = 1;
      result = dist_cop1;
    } else {
      chosenCar[idx] = 2;
      result = dist_cop2;
    }
    return result;
}


int main(void) {

    int minDist = 987654321;
    int* start[2];
    start[0] =  new int[2];
    start[1] = new int[2];



    scanf("%d", &n);
    scanf("%d", &w);
    start[0][0] = start[0][1] = 1;
    start[1][0] = start[1][1] = n;

    for(int i=0; i<w; i++) {
      scanf("%d", &coord[i][0]);
      scanf("%d", &coord[i][1]);
    }

    printf("%d\n", calMinDist(start[0], start[1], 0, w));
    for (int i=0; i<w; i++) {
      printf("%d\n",chosenCar[i]);
    }

    return 0;
}
