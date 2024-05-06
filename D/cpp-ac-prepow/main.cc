#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
int main() {
  int ans = 0;
  int N, P, Q;
  cin >> N >> P >> Q;
  modint::set_mod(P);
  vector<int> A(N, 0);
  int Amax = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  Amax = A[N - 1];
  vector<modint> p10, p9, p7, p5;
  p10.push_back(1);
  p9.push_back(1);
  p7.push_back(1);
  p5.push_back(1);
  for (int i = 0; i < Amax; i++) {
    p10.push_back(p10[i] * 10);
    p9.push_back(p9[i] * 9);
    p7.push_back(p7[i] * 7);
    p5.push_back(p5[i] * 5);
  }
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      for (int k = j + 1; k < N; k++) {
        for (int l = k + 1; l < N; l++) {
          int res = (p10[A[i]] + p9[A[j]] + p7[A[k]] + p5[A[l]]).val();
          if (res == Q) {
            ans++;
          }
        }
      }
    }
  }
  cout << ans << endl;
}
