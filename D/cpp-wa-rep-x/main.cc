#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int N, P, Q;
long long mpow(long long x, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % P;
    x = x * x % P;
    n >>= 1;
  }
  return res;
}
int main() {
  cin >> N >> P >> Q;
  vector<int> A(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        for (int l = 0; l < N; l++) {
          int res = 0;
          res = (res + mpow(10, A[i])) % P;
          res = (res + mpow(9, A[j])) % P;
          res = (res + mpow(7, A[k])) % P;
          res = (res + mpow(5, A[l])) % P;
          if (res == Q && i<j&&j<k&&k<l) {
            ans++;
          }
        }
      }
    }
  }
  cout << ans << endl;
}
