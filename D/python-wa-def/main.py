#! /usr/bin/env python3
def mpow(x, n, m):
    ans = 1
    while n:
        if n % 2:
            ans = ans * x % m
        x = x * x % m
        n >>= 1
    return ans
N, P, Q = map(int, input().split())
A = list(map(int, input().split()))
A.sort()
ans = 0
for i in range(N):
    for j in range(i + 1, N):
        for k in range(j + 1, N):
            for l in range(k + 1, N):
                if (
                    mpow(10, A[i], P)
                    + mpow(9, A[j], P)
                    + mpow(7, A[k], P)
                    + mpow(5, A[l], P)
                ) % P == Q:
                    ans += 1
print(ans)
