

def fib(n):
    if n <= 0:
        return -1
    if n <= 2:
        return 1
    a = 1
    b = 1
    for i in range(3, n+1):
        a = a + b
        a, b = b, a
    return b


while(1):
    num = input()
    print fib(num)
