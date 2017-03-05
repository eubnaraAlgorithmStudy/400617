#-*- coding: utf-8 -*-



'''
solve: 짐바브웨 문제를 풀기위한 함수

어떤 문자열이 주어지고, 그 문자열의 순서를 바꾼 후보들이 있다고 치자.
그 후보들 중에서, 현재 계란 값(e)보다 작고, m의 배수인 경우를 다 고르기.

기본적으로 모든 경우를 완성해 놓고 m의 배수를 고려한다면(dfs방식) 시간초과가 걸린다.

그렇다면, 중복적인 계산을 줄여야할 것이다.

무엇이 중복적인 계산인가?

 - 고를 수 있는 숫자가 같고
 - m이 같은 경우

이거면 충분한가?
원래의 계란 값보다 크거나 작은 경우는 어떻게 고려할 것인가?
앞의 숫자가 이미 작다면, 뒤에 숫자는 상관없이 모든 조합이 가능하다.
앞의 숫자가 같다면, 뒤에 숫자후보들은 e의 값보다 작은지 비교를 해야한다.
앞의 숫자가 크다면, 아무것도 안된다.(방문을 안하면 된다.)

그렇다면,

 - 현재 고를 수 있는 숫자후보
 - 현재까지의 나머지
 - 앞의 숫자가 이미 작은지 큰지

이 세 가지가 주어진다면 [같은 경우]로 볼 수 있을까? 그런 것 같다.

basecase는?
 처음에는 모든 숫자를 m보다 작은지 비교해야 한다.
 만들어진 숫자가 없기 때문에,
 앞의 숫자가 이미 작은 경우란 없다.
 앞의 숫자가 같은 경우로 볼 수 있다.(0으로서)


풀기
1. 저장되어 있는 값이 있다면, 이미 한 번 계산했다는 것이므로 갖다가 쓴다.
2. 없다면, 아래 계산이 진행되어야 한다.
 1. 남아있는 후보가 없다면, m의 배수인지 확인한다.
 2. 있다면, 후보를 하나 고른다. 그리고 나서, 남은 숫자후보, 현재까지의 나머지, 크기 비교의 정보를 넘겨주며 재귀함수 호출한다.

len: 현재까지 완성된 단어
taken: 현재 무엇을 골랐는지 안골랐는지에 대한 bit vector
remainder: 현재까지의 나머지
less: 작은지 큰지



중복 처리를 어떻게 할 것인가?

정렬을 하여 저장하고, 앞뒤 관계를 이용한다..


'''


def solve(strLen, taken, remainder, less):
    if (len(e) <= strLen):
        #print strLen, taken, remainder, less
        return less and remainder == 0

    if(-1 != cache[taken][remainder][less]):
        return cache[taken][remainder][less]


    cache[taken][remainder][less] = 0


    for i in range(0, len(e)):
        choose = 1 << i
        if(taken & choose != 0):
            continue



        if(less == False and e[strLen] < sorted_e[i]):
            continue
        if(0 < i and sorted_e[i-1] == sorted_e[i] and (taken & (1 << i-1) == 0) ):
            continue
        cache[taken][remainder][less] += solve(strLen+1, taken | choose, (remainder * 10 + int(sorted_e[i]) ) % m, less or sorted_e[i] < e[strLen])
        cache[taken][remainder][less] %= 1000000007

        '''
        아래 코드의 오류는 solve( , , , True) 인 경우를 2번 호출할 수 있다는 점이다. 경우의 수를 잘못 계산했다...ㅜ_ㅜ
        제약조건(중복제거, 크기가 작아야함, 이미 있는 수를 자리만 바꿔야함)을 제외하고는 다음의 두 경우만 따져야 하는데, 중복해서 더해준 점이 실수였다.
         - cache[taken][remainder][less] =
          * solve(strLen+1, taken | choose, (remainder * 10 + int(sorted_e[i]) ) % m, True)
          * solve(strLen+1, taken | choose, (remainder * 10 + int(sorted_e[i]) ) % m, False)

        현재까지의 숫자들의 비교에서 less 에 따라서, solve()의 두가지 길 중 하나만 선택해서 가는 셈이다. 두 가지 값을 모두 더하는 건 아니다. 그냥 단지 이미 구해놓은 값을 이용하는 것 뿐이다. 두 가지의 경우는 다르다고 여겨지기 때문에 값을 따로 저장하는 것 뿐이다. 만일, 현재 계란 값보다 작다 라는 조건이 없다면, True, False 를 나눌 필요가 없는 것이다.

        - dynamic programming을 다시 한 번 생각해보자.
         * 미리 저장해둔 값을 이용하자. (중복된 계산을 하지말자.)라는 취지이다.
         * 그런데 이 문제에서, 이미 고른 숫자는 2번 고를 수 없기 때문에, 다른 경우를 다르게 구해서 저장하는 것이고(taken)
         * 나머지가 현재까지 몇인지에 따라 다른 경우니까 다르게 구해서 저장하는 것이고(remainder)
         * 그 전의 값들에서 작다 안작다 라는 경우를 나눌 수 있으니까 다르게 구해서 저장하는 것이다.(less)
         * 즉, 재활용하기 위해선 정확하게 같은 경우일 때만 재활용 할 수 있다. 다른 경우를 구해놓은 값을 이용하는 건 상식적으로 말이 안되겠지.

        점화식을 생각하며, 현재 값은 어느 값들의 합인가를 우선 생각해보자. 무턱대고 경우의 수를 나누지 말고..
        '''
        '''
        if(less == True):
            cache[taken][remainder][less] += solve(strLen+1, taken | choose, (remainder * 10 + int(sorted_e[i]) ) % m, True)
        # int형으로 안바꿔도 비교가 된다.
        elif( sorted_e[i] <= e[strLen]):
            if(0 < i and sorted_e[i-1] == sorted_e[i] and (taken & (1 << i-1) == 0) ):
                continue
            cache[taken][remainder][less] += solve(strLen+1, taken | choose, (remainder * 10 + int(sorted_e[i]) ) % m, sorted_e[i] < e[strLen])
        '''

    return cache[taken][remainder][less]







def main():
    c = input()
    for i in range(0, c):
        global sorted_e
        global cache
        global e
        global m
        '''
        파이썬에서는 다음과 같은 경우를 처리할 때
        char* someStr;
        int someInt;
        scanf("%s %d", someStr, &someInt)

        이렇게 처리할 수 있다.
        e, m = raw_input().split()

        raw_input()은 한 줄을 싹다 받아버리기 때문에 string 만 받고 같은 줄에 input()을 이용하여 int 형을 받을 수 없다.

        따라서,
        e, m = raw_input().split() 으로 문자열로 파싱한 뒤,
        m = int(m) 형태로 하면 될 것이다.
        '''
        e, m = raw_input().split()
        m = int(m)


        # initialize cache
        '''
        파이썬에서는 타입명시를 안하기 때문에, global 변수를 쓸 때, 변수에 할당을 하는 경우 처음 선언하는 것인지 분간이 안된다.
        따라서, 여기에서 cache = [] 라는 표현을 또 쓴다면, 이는 지역변수로 인식하는 것 같다.
        원하는 동작을 달성하기 위해, 기존의 cache 리스트의 내용을 없애는 del 키워드를 사용한다.

        아니다, 그냥 global 키워드 이용하면 된다.
        '''
        cache = []
        for i in range(0, 1<<14):
            cache.append([])
            for j in range(0, m):
                cache[i].append([])
                for k in range(0, 2):
                    cache[i][j].append(-1)


        sorted_e = ''.join(sorted(e))
        #print e, m, sorted_e
        #print sorted_e
        print solve(0, 0, 0, False)

main()
