n = input()

cur = [0]
for i in range(1, n+1):
    temp = map(int, raw_input().split(' '))
    for j in range(0, i):
        if j is 0:
            temp[j] += cur[j]
        elif j is i-1:
            temp[j] += cur[j-1]
        else:
            temp[j] += max(cur[j-1], cur[j])
    cur = temp

print max(cur)
