#! /usr/bin/env pypy3
INF = 0x1FFFFFFFFFFFFFFF
N, M = map(int, input().split())
A = list(map(int, input().split()))
E = [0 for i in range(M)]
d = [-INF for i in range(N)]
update = [False for i in range(N)]
for i in range(M):
    a, b, c = map(int, input().split())
    E[i] = (a - 1, b - 1, A[b - 1] - c)
d[0] = A[0]
for i in range(N - 1):
    for s, t, cost in E:
        if d[s] == -INF:
            continue
        if d[t] < d[s] + cost:
            d[t] = d[s] + cost
for i in range(N):
    for s, t, cost in E:
        if d[s] == -INF:
            continue
        if d[t] < d[s] + cost:
            update[t] = True
        if update[s]:
            update[t] = True
for i in range(N):
    if update[i]:
        d[i] = INF
ans = "inf" if d[N-1] == INF else d[N-1]
print(ans)
