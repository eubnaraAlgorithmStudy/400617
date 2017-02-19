#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

const int CHANG_GYU = 0;
const int UI_JONG = 1;
const double NOT_THINK_YET = -1.0;

double m, d;
char suggest[100+5];

double maxProfitForC () {
    // 뒤에서부터 체크
    // 뒤에 나온 글자를 먼저 확인한다.
    // 앞으로 탐색해가며 그 글자가 다른글자로 바뀌기 전의 위치를 찾는다.
    // 그 위치까지 가격이 얼마로 떨어지는지 계산한다.
    // 그 값이 그 문자(창규 or 의종)가 그 다음 연속된 문자열에서 최소한 보장해줘야 하는 금액이다.
    // 즉 그 다음에 오는 다른 문자는 제시할 때, 이 값을 제외하고 제시하지 않으면 받아들이지 않을 것이다.

    // 위 원리대로 처음 위치까지 반복한다.


    // 각각이 현재까지 최소한 보장받고 싶은 금액
    double min[2] = { NOT_THINK_YET, NOT_THINK_YET };
    double invert_d = 1 - d * 0.01;

    int i = strlen(suggest) - 1; // 마지막 위치
    int curChar;
    while(i >= 0) {
        curChar = suggest[i];
        // 같은 문자가 나온다면 계속 반복, 맨앞에 도달했을 때 제외
        if( i > 0 && curChar == suggest[i-1] ) {
            i--;
            continue;
        }
        switch(curChar) {
            case 'C':
                min[CHANG_GYU] = m * pow(invert_d, i);

                if(min[UI_JONG] != NOT_THINK_YET) {
                    
                   min[CHANG_GYU] -= min[UI_JONG];

                }
                break;

            case 'U':
                min[UI_JONG] = m * pow(invert_d, i);

                if(min[CHANG_GYU] != NOT_THINK_YET) {

                    min[UI_JONG] -= min[CHANG_GYU];

                }
                break;

            default:
                printf("str input error\n");
                exit(-1);
        }
        i--; 
    }
    return (min[CHANG_GYU] == NOT_THINK_YET) ? 0.0 : min[CHANG_GYU];
}



int main(void) {
    int testcase;
    scanf("%d",&testcase);

    while(testcase--) {
        scanf("%lf %lf", &m, &d);
        scanf("%s", suggest);
        //1kg 당 만원
        m *= 10000.0;

        // 두 번째 자리에서 반올림하여 출력
        printf("%.1lf\n", maxProfitForC());
    }

    return 0;
}
