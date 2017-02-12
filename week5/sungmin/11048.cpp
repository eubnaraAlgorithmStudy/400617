////
////  11048.cpp
////  ProblemSolving
////
////  Created by mindol on 2017. 2. 4..
////  Copyright © 2017년 mindol. All rights reserved.
////
//
///*
//3 4
//1 2 3 4
//0 0 0 5
//9 8 7 6
//*/
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<vector<int> > MAP;
//vector<vector<int> > cache;
//
////int ans = 0;
//int dy[3] = { 1, 0, 1 };
//int dx[3] = { 0, 1, 1 };
//int N, M;
//int ans;
//
//int dfs(int y, int x) {
//    int &ret = cache[y][x];
//    if (ret != -1)
//        return ret;
//    
//    ret = MAP[y][x];
//    
//    for (int i=0; i<3; i++) {
//        int subret = 0;
//        
//        int nx = x + dx[i];
//        int ny = y + dy[i];
//        
//        if (nx < 1 || ny < 1 || nx > M || ny > N) continue;
//        
//        subret += dfs(ny, nx);
//        ret = max(ret, subret + MAP[y][x]);
//    }
//    
//    return ret;
//}
//
//int main(void) {
//    scanf("%d %d", &N, &M);
//    
//    MAP.assign(N+1, vector<int>(M+1, 0));
//    cache.assign(N+1, vector<int>(M+1, -1));
//    for (int i=1; i<=N; i++) {
//        for(int j=1; j<=M; j++) {
//            scanf("%d", &MAP[i][j]);
//        }
//    }
//    
//    //dfs(1, 1);
//    printf("%d\n", dfs(1, 1));
//    
//    return 0;
//}
