def distance (coord1, coord2):
    result = abs(coord1[0] - coord2[0])
    result += abs(coord1[1] - coord2[1])
    return result

def calMinDist(cop1, cop2, incidentCoordLists, curIdx, length, chosenCar):
    result = 0
    if(curIdx >= length):
        return result

    chosenCar.append(1)
    dist_cop1 = calMinDist(incidentCoordLists[curIdx], cop2, incidentCoordLists, curIdx + 1, length, chosenCar) + distance(cop1, incidentCoordLists[curIdx])

    chosenCar[curIdx] = 2
    dist_cop2 = calMinDist(cop1, incidentCoordLists[curIdx], incidentCoordLists, curIdx + 1, length, chosenCar) + distance(cop2, incidentCoordLists[curIdx])


    if(dist_cop1 < dist_cop2):
        chosenCar[curIdx] = 1
        result = dist_cop1
    else:
        chosenCar[curIdx] = 2
        result = dist_cop2

    return result

n = input()
w = input()
incidentCoordLists = []
chosenCar = []
for i in range(0, w):
    coordList = map(int, raw_input().split())
    incidentCoordLists.append(coordList)
print(calMinDist([1,1], [n, n], incidentCoordLists, 0, len(incidentCoordLists), chosenCar))
for i in range(0, w):
    print(chosenCar[i])
