#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
int main() {
  int ans = 0;
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  auto B = A;
  sort(B.rbegin(), B.rend());
  map<int, int> M;
  vector S(B.size() + 1, 0);
  B.erase(unique(B.begin(), B.end()), B.end());
  for (int i = 1; auto x : B) {
    M[x] = i;
    i++;
  }
  for (auto x : A) {
    S[M[x]]++;
  }
  for (int i = 0; i < S.size() - 1; i++) {
    S[i + 1] += S[i];
  }
  while (Q--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    cout << max(S[M[A[y]] - 1] - S[M[A[x]]], 0) << endl;
  }
}
