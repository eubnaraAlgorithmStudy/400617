//
//  TRIANGLEPATH.cpp
//  ProblemSolving
//
//  Created by mindol on 2017. 1. 10..
//  Copyright © 2017년 mindol. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 입력받은 배열, dp용 배열
int path(vector<vector<int>> V, vector<vector<int>> dp) {
    for (int i=0; i<V.size()-1; i++) {
        for (int j=0; j<V[i].size(); j++) {
            // -1이면 바로 리턴할 수 있도록
            if (V[i][j] == -1)
                break;
            // 아래, 우측아래 값을 동적으로 설정
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + V[i+1][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + V[i+1][j+1]);
        }
    }
    
    int ans = 0;
    int size = V.size();
    
    // 맨 아래부분이 최대값이므로, 맨 아래부분만 검색
    for (int i=0; i<size; i++) {
        ans = max(dp[size-1][i], ans);
    }
    
    return ans;
}

int main(void) {
    int T, N;
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d", &N);
        vector<vector<int>> V;
        V.assign(N, vector<int>(N, -1));
        
        for (int i=0; i<N; i++) {
            for (int j=0; j<=i; j++) {
                scanf("%d", &V[i][j]);
            }
        }
            
        int ans = path(V, V);
        printf("%d\n", ans);
    }
}
