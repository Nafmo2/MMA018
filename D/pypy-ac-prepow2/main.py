#! /usr/bin/env pypy3
N, P, Q = map(int, input().split())
A = list(map(int, input().split()))
A.append(0)
A.sort()
ans = 0
p10 = {}
p9 = {}
p7 = {}
p5 = {}
p10[0]=1
p9 [0]=1
p7 [0]=1
p5 [0]=1
for i in range(N):
    p10[A[i+1]] = (p10[A[i]]*pow(10, A[i+1]-A[i], P))%P
    p9[A[i+1]] =  (p9[A[i]] *pow(9, A[i+1]-A[i], P))%P
    p7[A[i+1]] =  (p7[A[i]] *pow(7, A[i+1]-A[i], P))%P
    p5[A[i+1]] =  (p5[A[i]] *pow(5, A[i+1]-A[i], P))%P
for i in range(1,N):
    for j in range(i + 1, N):
        for k in range(j + 1, N):
            for l in range(k + 1, N):
                if (p10[A[i]] + p9[A[j]] + p7[A[k]] + p5[A[l]]) % P == Q:
                    ans += 1
print(ans)
