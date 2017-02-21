#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, w;
int incident[1000+5][2+5];
int alt = 0;
// [cop1위치][cop2위치][사건인덱스]
// '위치'가 나타내는 숫자는 어떤 사건을 가리킨다. 즉, 그 사건이 일어난 위치에 있다는 뜻
// cache에서의 0 인덱스는 시작점을 나타내고, incident에서는 [0] [w+1]이 각각 좌표를 나타낸다.
// 3번째 인덱스가 0이라면 바로 이전 layer를 1이라면 현재 레이어를 말함?
// alternative?
int cache[1000+5][1000+5][2];

// 어디서에서 이 자리에 오게 되었는지

//TODO: 이렇게 많은 배열이 필요 없을 수 있다. 사건을 순서대로 처리한다면.. 배열이 꽉 차지 않는다.ㄴ
// 자식은 여럿이지만 부모는 하나..? 가장 짧은 길을 택하니까
int parent[1000+5][1000+5][2];

int distance(int* a, int* b) {
    int diff = abs(a[0]-b[0]) + abs(a[1]-b[1]);
    return diff;
}

void dp(int numOfIncidents) {
    // base case
    cache[1][0][alt] = distance(incident[1], incident[0]);
    cache[0][1][alt] = distance(incident[1], incident[w+1]);

    parent[1][0][alt] = parent[1][0][alt] =  1;
    parent[0][1][alt] = parent[0][1][alt] =  n;

    for(int i = 2; i <= numOfIncidents; i++) {
        // cop1이 현재 사건으로 가는 경우
        for(int j = 0; j < i; j++) {
            cache[i][j][alt] = 987654321; // 초기화
        }
        // 바로 전 사건도 cop1이 처리한 경우
        for(int j = 0; j < i-1; j++) {
            cache[i][j][alt] = cache[i-1][j][alt ^ 1] + distance(incident[i-1], incident[i]);
            // 바로 전에 어느 위치에서 왔나.
            parent[i][j][0] = i-1;
            parent[i][j][1] = j;
        }

        // 바로 전 사건은 cop2가 처리한 경우
        for(int j = 0; j < i-1; j++) {
            if (cache[i][i-1][alt] > cache[j][i-1][alt ^ 1] + distance(incident[j], incident[i]) ) {
                cache[i][i-1][alt] = cache[j][i-1][alt ^ 1] + distance(incident[j], incident[i]);
                parent[i][i-1][0] = j;
                parent[i][i-1][1] = i-1;
            }
        }

        // cop2이 현재 사건으로 가는 경우
        for(int j = 0; j < i; j++) {
            cache[j][i][i] = 987654321; // 초기화
        }
        // 바로 전 사건도 cop2이 처리한 경우
        for(int j = 0; j < i-1; j++) {
            cache[j][i][alt] = cache[j][i-1][alt ^ 1] + distance(incident[i-1], incident[i]);
            // 바로 전에 어느 위치에서 왔나.
            parent[j][i][0] = j;
            parent[j][i][1] = i-1;
        }

        // 바로 전 사건은 cop1가 처리한 경우
        for(int j = 0; j < i-1; j++) {
            if (cache[i-1][i][alt] > cache[i-1][j][alt ^ 1] + distance(incident[j], incident[i])) {
                cache[i-1][i][alt] = cache[i-1][j][alt ^ 1] + distance(incident[j], incident[i]);
                parent[i-1][i][0] = i-1;
                parent[i-1][i][1] = j;
            }
        }
        alt ^= 1;
    }
}


void printOrder(int endCop1, int endCop2) {
  // 순서를 앞에서부터 찾아야하므로, stack에 넣고 다시 빼는 형식을 이용하자.
  vector<int> order;

  for(int i = w; i >= 1; i--) {
      //현재 i 가 가리키는 위치가 앞의 인덱스인지 뒤 인덱스인지에 따라서, 어느 경찰차에서 온지 알 수 있다.
      if(endCop1 == i) {
        order.push_back(1);
      } else {
        order.push_back(2);
      }
      endCop1 = parent[endCop1][endCop2][0];
      endCop2 = parent[endCop1][endCop2][1];
  }
  for(int i = w; i >= 1; i--) {
    printf("%d\n", order.back());
    order.pop_back();
  }
}

int main(void) {
    int curMin = 987654321;
    int endCop1, endCop2;
    scanf("%d",&n);
    scanf("%d",&w);

    //사건 인덱스를 헷갈리니까 1부터 쓴다.
    for(int i = 1; i <= w; i++) {
        scanf("%d %d", &incident[i][0], &incident[i][1]);
    }
    //incident[0] 은 cop1의 시작점으로
    //incident[w+1] 은 cop2의 시작점으로 두자.
    incident[0][0] = incident[0][1] = 1;
    incident[w+1][0] = incident[w+1][1] = n;


    dp(w);

    for(int i = 0; i < w; i++) {
        for(int j = 0; j < 2; j++) {
            int tmpEndCop1, tmpEndCop2;
            int min;
            if(cache[i][w][j] < cache[w][i][j]) {
              min = cache[i][w][j];
              tmpEndCop1 = i;
              tmpEndCop2 = w;
            } else {
              min = cache[w][i][j];
              tmpEndCop1 = w;
              tmpEndCop2 = i;
            }
            //int min = cache[i][w][w] < cache[w][i][w] ? cache[i][w][w] : cache[w][i][w];
            //curMin = curMin < min ? curMin : min;
            if( min < curMin) {
              curMin = min;
              endCop1 = tmpEndCop1;
              endCop2 = tmpEndCop2;
            }
        }
    }
    printf("%d\n",curMin);
    printOrder(endCop1,endCop2);
    //TODO: cache를 987654321로 초기화 해야한다? 느리지 않을까?




    return 0;
}
