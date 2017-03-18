# https://www.acmicpc.net/problem/1463

N = input()

ans = [0, 1, 1, 1]

if N <= 3:
    print ans[N]
    exit(0)

for i in range(4, N + 1):
    minCount = 987654321
    if i % 3 == 0:
        minCount = ans[i / 3] + 1
    if i % 2 == 0:
        if ans[i / 2] + 1 < minCount:
            minCount = ans[i / 2] + 1
    if ans[i - 1] + 1 < minCount:
        minCount = ans[i - 1] + 1
    ans.append(minCount)
print ans[N]
