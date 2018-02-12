#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);
    while(T--) {
        int a, b;
        scanf("%d %d", &a, &b);
        int ans = a % 10;
        for(int i=0;i<b-1;i++) {
            ans *= a;
            ans %= 10; 
        }
        ans = 0 == ans ? 10 : ans;
        printf("%d\n", ans);
    }
    return 0;
}
