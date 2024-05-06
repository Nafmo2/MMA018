#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int N, P, Q;
long long mpow(long long x, long long n) {
  long long res = 1;
  while (n > 0) {
    res = res * x % P;
    n --;
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
    for (int j = i + 1; j < N; j++) {
      for (int k = j + 1; k < N; k++) {
        for (int l = k + 1; l < N; l++) {
          int res = 0;
          res = (res + mpow(10, A[i])) % P;
          res = (res + mpow(9, A[j])) % P;
          res = (res + mpow(7, A[k])) % P;
          res = (res + mpow(5, A[l])) % P;
          if (res == Q) {
            ans++;
          }
        }
      }
    }
  }
  cout << ans << endl;
}
