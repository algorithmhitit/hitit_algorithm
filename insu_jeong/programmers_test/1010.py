# This file is python test file
a = (int)(input())
answer = 1
for i in range(a) :
    answer = 1
    n, m = map(int, input().split())
    if n < m :
        for x in range(m-n):
            answer *= (m-x)
            answer = answer / (1+x)
    else :
        for x in range(n-m):
            answer *= (n-x)
            answer = answer / (1+x)
    print(int(answer))

