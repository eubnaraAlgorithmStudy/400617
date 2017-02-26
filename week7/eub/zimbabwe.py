#-*- coding: utf-8


# 현재 numCand[]를 보고 index를 알아낸다.
def getIndex():
    




def calAllCases(unconditionalJump, curIdx, EndIdx, leftNumCandidate, strCompletedNum):
    numOfCases = 0
    # EndIdx까지 숫자가 완성된 경우
    if(curIdx == EndIdx+1):
        # 값이 같은 경우 제외
        # m의 배수일 때만 경우의 수를 늘림
        if(strEggVal != strCompletedNum[0:EndIdx+1] and int(strCompletedNum[0:EndIdx+1]) % m == 0):
            return 1
        return 0

    for i in range (0, 10):
        if(leftNumCandidate[i] > 0):
            if(unconditionalJump == True or i < int(strEggVal[curIdx])):
                strCompletedNum = strCompletedNum[0:curIdx] + str(i)
                leftNumCandidate[i]-=1
                numOfCases += calAllCases(True, curIdx+1, EndIdx, leftNumCandidate, strCompletedNum)
                leftNumCandidate[i]+=1
            elif(i == int(strEggVal[curIdx])):
                # strCompletedNum[curIdx] = str(i)
                strCompletedNum = strCompletedNum[0:curIdx] + str(i)
                leftNumCandidate[i]-=1
                numOfCases += calAllCases(False, curIdx+1, EndIdx, leftNumCandidate, strCompletedNum)
                leftNumCandidate[i]+=1
            else:
                break;
    return numOfCases

# num of testcases
c = input()



for testcase in range(0, c):
    # e: current price of egg
    # m: previous price of egg / previous price of candy
    line = raw_input()

    e = int(line.split()[0])
    m = int(line.split()[1])
    leftNumCandidate = []
    for i in range(0, 10):
        leftNumCandidate.append(0)

    # 현재 계란 가격 값을 str으로 변환하여 숫자후보를 하나씩 입력한다.
    strEggVal = str(e)
    for i in range(0, len(strEggVal)):
        leftNumCandidate[int(strEggVal[i])]+=1



    strCompletedNum = 'xxxxxxxxxxxxxxx'
    result = calAllCases(False, 0, len(strEggVal)-1, leftNumCandidate, strCompletedNum) % 1000000007
    print(result)
