

height = []
for i in range(0, 9):
    height.append(input())
height.sort(reverse = True)
isAnswer = False

def dfs(idx, cnt, sum):
    global isAnswer
    if (idx == 9):
        if (cnt == 7 and sum == 100):
            isAnswer = True
        else:
            return
    for i in range(idx, 9):
        sum += height[i]
        dfs(i+1, cnt+1, sum)
        if (isAnswer):
            print height[i]
            return
        sum -= height[i]

dfs(0, 0, 0)
