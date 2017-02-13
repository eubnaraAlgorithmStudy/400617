//
//  11399.cpp
//  ProblemSolving
//
//  Created by mindol on 2017. 2. 13..
//  Copyright © 2017년 mindol. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> D;

int solve() {
    int sum = 0;
    int ans = 0;
    
    for (int i=0; i<D.size(); i++) {
        sum += D[i];
        ans += sum;
    }
    
    return ans;
}

int main(void) {
    int N;
    scanf("%d", &N);
    
    while (N--) {
        int temp;
        scanf("%d", &temp);
        D.push_back(temp);
    }
    sort(D.begin(), D.end());
    printf("%d\n", solve());
    
    return 0;
}
