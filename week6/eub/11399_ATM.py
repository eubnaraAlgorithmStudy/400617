def series(len, inputList):
    inputList.sort()
    sumList = [inputList[0]]
    result = inputList[0];
    for i in range(1, leng):
        sumList.append(sumList[i-1] + inputList[i])
        result += sumList[i]
    return result

leng = input()
inputStr = raw_input()
inputList = inputStr.split()
inputList = map(int, inputList)
print(series(leng, inputList))
