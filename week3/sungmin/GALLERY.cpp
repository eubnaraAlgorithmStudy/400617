////
////  GALLERY.cpp
////  ProblemSolving
////
////  Created by mindol on 2017. 1. 16..
////  Copyright © 2017년 mindol. All rights reserved.
////
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//vector<bool> VISITED;
//vector<vector<int> > GRAPH;
//int G, H;
//int ans;
//
//int dfs(int galleryNo) {
//    int status[3] = { 0, 0, 0 }; // [0]: 안 보여지는지 여부 [1]: 설치 여부 [2] 보여지는 여부
//    
//    VISITED[galleryNo] = true;
//    for (int i=0; i<GRAPH[galleryNo].size(); i++) {
//        int next = GRAPH[galleryNo][i];
//        if (!VISITED[next]) {
//            status[dfs(next)]++;
//        }
//    }
//    
//    if (status[0]) { // 자식이 안보여지냐?
//        ans++;
//        return 1; // 설치된 것으로 리턴
//    } else if (status[1]) { // 혹시 자식이 설치했냐?
//        return 2; // 보여지는 것으로 리턴 (이게 무슨 역할을 하는거지?????)
//    } else {
//        return 0; // 그게 아니면 안 보여지는 상태로 리턴
//    }
//}
//
//void visitAllGallery() {
//    for (int u=0;u<G; u++) {
//        if(!VISITED[u] && dfs(u) == 0)
//            ans++;
//    }
//}
//
//int main(void) {
//    int C;
//    scanf("%d", &C);
//    
//    while(C--) {
//        
//        scanf("%d %d", &G, &H);
//        
//        VISITED.clear();
//        VISITED.assign(G, false);
//        
//        GRAPH.clear();
//        GRAPH.assign(G, vector<int>());
//        
//        while(H--) {
//            int inGallery, outGallery;
//            scanf("%d %d", &outGallery, &inGallery);
//            
//            GRAPH[outGallery].push_back(inGallery);
//            GRAPH[inGallery].push_back(outGallery);
//        }
//        ans = 0;
//        visitAllGallery();
//        printf("%d\n", ans);
//    }
//    return 0;
//}
