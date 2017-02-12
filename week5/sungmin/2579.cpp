////
////  2579.cpp
////  ProblemSolving
////
////  Created by mindol on 2017. 2. 5..
////  Copyright © 2017년 mindol. All rights reserved.
////
//
//#include <stdio.h>
//#include <algorithm>
//
//using namespace std;
//
//int dp[301][2];
//int data[301];
//int N;
//
//int solve() {
//    dp[1][0] = data[1];
//    dp[1][1] = data[1];
//    dp[2][1] = data[1] + data[2];
//    dp[2][0] = data[2];
//    
//    for (int i=3; i<=N; i++) {
//        dp[i][1] = data[i] + dp[i-1][0];
//        dp[i][0] = data[i] + max(dp[i-2][1], dp[i-2][0]);
//    }
//    
//    return max(dp[N][0], dp[N][1]);
//}
//
//int main(void) {
//    scanf("%d", &N);
//    for (int i=1; i<=N; i++) {
//        scanf("%d", &data[i]);
//    }
//    
//    printf("%d\n", solve());
//    return 0;
//}
