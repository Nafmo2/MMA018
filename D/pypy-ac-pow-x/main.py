#! /usr/bin/env pypy3
N, P, Q = map(int, input().split())
A = list(map(int, input().split()))
A.sort()
ans = 0
for i in range(N):
    for j in range(N):
        for k in range(N):
            for l in range(N):
                if not i<j<k<l:
                    continue
                if (
                    pow(10, A[i], P)
                    + pow(9, A[j], P)
                    + pow(7, A[k], P)
                    + pow(5, A[l], P)
                ) % P == Q:
                    ans += 1
print(ans)
