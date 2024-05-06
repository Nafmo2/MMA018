#! /usr/bin/env python3
N, P, Q = map(int, input().split())
A = list(map(int, input().split()))
A.sort()
ans = 0
for i in range(N):
    for j in range(i + 1, N):
        for k in range(j + 1, N):
            for l in range(k + 1, N):
                if (
                    10**A[i]%P
                    + 9**A[j]%P
                    + 7**A[k]%P
                    + 5**A[l]%P
                ) % P == Q:
                    ans += 1
print(ans)
