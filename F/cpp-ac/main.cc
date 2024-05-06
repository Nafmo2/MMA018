#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
int main() {
  mint ans = 0;
  int N, M, K;
  cin >> N >> M >> K;
  vector dp(M, vector(1<<N, (mint)0));
  for (int bit = 0; bit < (1 << N); bit++) {
    dp[0][bit] = 1;
  }
  for (int i = 0; i < M - 1; i++) {
    for (int bit = 0; bit < (1 << N); bit++) {
      for (int next = 0; next < (1 << N); next++) {
        int cnt = __builtin_popcount(bit & next);
        if (cnt >= K) {
          dp[i + 1][next] += dp[i][bit];
        }
      }
    }
  }
  for (int bit = 0; bit < (1 << N); bit++) {
    ans += dp[M - 1][bit];
  }
  cout << ans.val() << endl;
}
