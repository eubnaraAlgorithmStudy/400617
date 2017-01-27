/*
 3
 100 50 0
 Case #1
 934849953
 100 10 0
 Case #2
 538396636
 100 20 0
 Case #3
 276891342
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int M = 1000000009;
int N, K, L;
vector<int> MINE;
vector<vector<long long> > DATA;
vector<long long> ANS;

long long solve() {
    for (int bridgeNo=1; bridgeNo<=N; bridgeNo++) {
        long long sum = 0;
        if (MINE[bridgeNo]) continue;
        for (int step=1; step<=K; step++) {
            int prevIdx = bridgeNo - step; // 현재에서 k값을 뺀 값을 가져온다
            if (prevIdx == 0) {
                sum += 1 % M;
                DATA[bridgeNo][step] = 1;
                break;
            } else {
                DATA[bridgeNo][step] = ANS[prevIdx] - DATA[prevIdx][step] % M;
                sum += ANS[prevIdx] - DATA[prevIdx][step] % M;
            }
        }
        
        ANS[bridgeNo] = sum % M;
    }
    
    return ANS[N];
}

int main(int argc, char** argv) {
    setbuf(stdout, NULL);
    
    int T;
    int test_case;
    
    scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
    for(test_case = 1; test_case <= T; test_case++) {
        // 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
        scanf("%d %d %d", &N, &K, &L);
        
        DATA.clear();
        DATA.assign(N+1, vector<long long>(K+1, 0));
        ANS.clear();
        ANS.assign(N+1, 0);
        MINE.clear();
        MINE.assign(N+1, 0);
        
        if (L > 0) {
            for (int i=0; i<L; i++) {
                int mineIndex;
                scanf("%d", &mineIndex);
                MINE[mineIndex] = 1;
            }
        }
        
        // 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
        printf("Case #%d\n", test_case);
        cout << solve() << endl;
        
    }
    
    return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
