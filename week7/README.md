# ZIMBABWE

 - [algospot ZIMBABWE 문제](https://algospot.com/judge/problem/read/ZIMBABWE)

### 접근 방법

 1. 조건을 만족하는 모든 경우의 수를 찾기.
  1. 현재 계란 가격보다 작은 가격이어야 한다.
  2. 현재 계란 가격에서 숫자 위치만 바뀐다.
  3. m의 배수여야 한다.

 2. 모든 경우의 수를 DFS를 사용해서 구해보자. -> 시간초과가 뜬다. -> DP를 이용해보자.
 3. DP를 어떻게 이용할 것인가?
  - 현재 기준에서 고정되는 것이 무엇인가?
    - 현재까지의 나머지(remainder or modular)
    - 현재까지 남은 숫자 후보들(taken)
    - 현재 완성해야될 숫자의 위치(사실 이것은 전체 글자의 길이와 현재까지 남은 숫자 후보들 간의 관계에서 추론이 가능하다. 따로 cache의 배열 인덱스로 만들 필요는 없다.)
    - 현재 계란 가격보다 작은지 안작은지(이를 구분하는이유는 현재위치까지의 나머지와 숫자 후보들이 같아도 이미 지나온 숫자들에 따라 다른 경우가 있을 수 있다. 3321 1221 은 둘다 3의 배수지만 2211보다 크거나 작은 경우로 달라지기 때문)
    
  - 고정되어야 하는 것을 기준으로 미리 구해놓은 값들을 저장하자.
    - `cache[현재까지 남은 숫자 후보들][나머지][작은지 안작은지]`
    - `cache[1<<14][20][2]`
    - `cache[][][]` 는 -1 값으로 세팅해놓고, 이 값이 -1이 아니라면 이미 답을 구해놓은 상태라는 뜻이므로, 추가적인 재귀호출 없이 이 값을 그대로 쓴다. 

### 특이사항

 - 한 줄에 가능한 가격의 수를 1,000,000,007로 나눈 나머지를 출력하라.
