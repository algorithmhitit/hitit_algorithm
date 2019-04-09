## 201614885 이호준
## 2579 계단 오르기
## https://www.acmicpc.net/problem/2579

## 3번째 항까지 구한 후 점화식 도출하여 문제 해결 (max 내장 함수 개꿀)

import sys
n = int(input())
st = []

for i in range(n):
    st.append(int(sys.stdin.readline().rstrip()))

sum = []
sum.append(st[0])
sum.append(st[1]+st[0])
sum.append(max(st[2]+st[0], st[2]+st[1]))

for i in range(3, n):
    sum.append(max(st[i]+sum[i-2], st[i]+st[i-1]+sum[i-3]))

print(sum[n-1])
