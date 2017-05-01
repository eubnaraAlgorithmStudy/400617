#include <stdio.h>

long long fib(int n) {
    if ( n <= 0 ) return -1;
    if ( n < 2 ) return 1;
    long long a = 1, b = 1;
    for(int i=3; i<=n; i++) {
        a = a + b;
        long long tmp = a;
        a = b;
        b = tmp;
    }
    return b;
}


int main() {
    while(1) {
        long long num;
        scanf("%lld", &num);
        printf("%lld\n", fib(num));
    }

    return 0;
}
