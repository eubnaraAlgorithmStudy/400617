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
    
    nested list,
    [idx][연속유무]
    연속유무:
        0: 불연속
        1: 연속
'''

def climbUp(inputList):
    # 연속된 3개의 계단을 방지위한 변수
    result = []
    totalStairs = len(inputList)
    # basecase
    if totalStairs <= 2:
        return inputList[0] if totalStairs == 1 else (inputList[0] + inputList[1])

    # 불연속 / 연속 순으로 집어넣는다.
    # 2칸 전에서 왔을 때, 1칸 전에서 왔을 때
    # 2칸 전에서 올 때는 2칸 전의 불연속/연속인 경우에서 모두 올 수 있지만, 여기는 basecase이므로 0을 넣어둔다.
    result.append([])
    # can't jump from -2, 2칸 전에서 오는 불연속인 경우
    result[0].append(0 + inputList[0])
    # can't jump from -1, 1칸 전에서 와서 연속인 경우
    result[0].append(0 + inputList[0])
    

    result.append([])
    result[1].append(0 + inputList[1])
    result[1].append(inputList[0] + inputList[1])


    result.append([])
    result[2].append( (result[0][0] if result[0][0] > result[0][1] else result[0][1] ) + inputList[2])
    result[2].append( result[1][0] + inputList[2] )


    #
    for i in range(3, totalStairs):
        result.append([])
        # 불연속
        result[i].append( (result[i-2][0] if result[i-2][0] > result[i-2][1] else result[i-2][1] ) + inputList[i])

        # 연속
        result[i].append( result[i-1][0] + inputList[i] )
    lastIdx = totalStairs - 1
    return result[lastIdx][0] if result[lastIdx][0] > result[lastIdx][1] else result[lastIdx][1]

totalStairs = input()
inputList = []
for i in range(0, totalStairs):
    inputList.append(input())

print(climbUp(inputList))
