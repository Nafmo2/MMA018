#! /usr/bin/env python3
MOD = 998244353
N, M, K = map(int, input().split())
dp = [[0 for i in range(1 << N)] for j in range(M)]
ans = 0
for i in range(1 << N):
    dp[0][i] = 1
for i in range(M - 1):
    for bit in range(1 << N):
        for next in range(1 << N):
            if bin(bit & next).count("1") >= K:
                dp[i + 1][next] += dp[i][bit]
print(sum(dp[M-1])%MOD)
