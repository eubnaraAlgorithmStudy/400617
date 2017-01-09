//
//  JUMPGAME.cpp
//  ProblemSolving
//
//  Created by mindol on 2017. 1. 9..
//  Copyright © 2017년 mindol. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > MAP;
vector<vector<int> > cache;
int N;

// 현재 좌표가 MAP에 존재하는지 확인
bool isMapIn(int y, int x) {
    return (y > N) || (x > N) ? false : true;
}

bool traverse(int y, int x) {
    if (y == N && x == N) {
        return true;
    }
    
    // 메모리제이션 기법 (DFS의 전체 탐색 시, 중복된 내용을 탐색할 수 있으므로 이를 피하기 위함)
    if (cache[y][x] != -1)
        return false; // 이미 방문 했는데 결과가 아니라면 false 값 반환

    int n = MAP[y][x];
    // 이미 방문한 내용으로 체크
    cache[y][x] = 1;

    if (isMapIn(y, x+n) && traverse(y, x+n)) {
        return true;
    }
    
    if (isMapIn(y+n, x) && traverse(y+n, x)) {
        return true;
    }
    
    return false;
}

int main(void) {
    int T;
    scanf("%d", &T);
    
    while(T--) {
        scanf("%d", &N);
        MAP.clear();
        cache.clear();
        
        MAP.assign(N+1, vector<int>(N+1, 0));
        cache.assign(N+1, vector<int>(N+1, -1));
        
        for (int i=1; i<N+1; i++) {
            for (int j=1; j<N+1; j++) {
                scanf("%d", &MAP[i][j]);
            }
        }
        
        if (traverse(1, 1)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}
