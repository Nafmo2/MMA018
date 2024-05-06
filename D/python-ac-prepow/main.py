#! /usr/bin/env python3
N, P, Q = map(int, input().split())
A = list(map(int, input().split()))
A.sort()
ans = 0
p10 = [1]
p9 = [1]
p7 = [1]
p5 = [1]
for i in range(max(A)):
    p10.append(p10[i] * 10 % P)
    p9.append(p9[i] * 9 % P)
    p7.append(p7[i] * 7 % P)
    p5.append(p5[i] * 5 % P)
for i in range(N):
    for j in range(i + 1, N):
        for k in range(j + 1, N):
            for l in range(k + 1, N):
                if (p10[A[i]] + p9[A[j]] + p7[A[k]] + p5[A[l]]) % P == Q:
                    ans += 1
print(ans)
