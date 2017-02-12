# This Python file uses the following encoding: utf-8
import os, sys

'''
접근방식: 동적프로그래밍

현재 위치에 도달할 수 있는 곳은 1개 혹은 2개 계단 아래이다.
두 개의 경우 중, 최대값을 선택하여 현재 위치의 값을 갱신한다.
(1층, 2층에 대한 basecase는 주어진 값을 넣어주고 시작한다.)
'''

'''
climbUp
입력:
    입력된 계단점수 리스트
출력:
    계산된 계단점수 리스트
설명:
    총 계단의 수만큼 반복문을 돌며, 한 반복문당 해당위치의 최대값을 구한다.
    basecase는 반복문 전에 미리 처리를 해주며, 반복문은 basecase 이후부터 시작한다.


    현재 위치로는 1칸 전 혹은 2칸 전에서 올 수 있다.
    
'''

def climbUp(inputList):
    # 연속된 3개의 계단을 방지위한 변수
    continuousStairs = 0
    result = []
    totalStairs = len(inputList)
    # basecase
    if totalStairs <= 2:
        return inputList[0] if totalStairs == 1 else inputList[0] if inputList[0] >= inputList[1] else (inputList[0] + inputList[1])

    result.append(inputList[0])
    result.append(inputList[0] + inputList[1])

    # result[2] == (inputList[0] + inputList[2], continuousStairs = 1)  or (inputList[1] + inputList[2], continuousStairs = 2)
    if inputList[0] > inputList[1] :
        result.append(inputList[0] + inputList[2])
        continuousStairs = 1
    else:
        result.append(inputList[1] + inputList[2])
        continuousStairs = 2


    #
    for i in range(3, totalStairs):
        if continuousStairs == 2:
            result.append(inputList[i] + result[i-2])
            continuousStairs = 1
        else:
            if result[i-1] < result[i-2]: 
                continuousStairs = continuousStairs + 1
            else:
                continuousStairs = 1
            result.append( inputList[i] + (result[i-1] if result[i-1] >= result[i-2] else result[i-2]) )

    return result[totalStairs - 1]


totalStairs = input()
inputList = []
for i in range(0, totalStairs):
    inputList.append(input())

print(climbUp(inputList))
