#! /usr/bin/env python3
import bisect

N, Q = map(int, input().split())
A = list(map(int, input().split()))
B = sorted(A)
while Q > 0:
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    ans = bisect.bisect_left(B, A[x]) - bisect.bisect_right(B, A[y])
    print(max(ans, 0))
    Q -= 1
