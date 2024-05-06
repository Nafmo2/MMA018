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
  sort(B.begin(), B.end());
  while (Q--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    int r = lower_bound(B.begin(), B.end(), A[x]) - B.begin() ;
    int l = upper_bound(B.begin(), B.end(), A[y]) - B.begin();
    cout<< max(r-l,0) << endl;
  }

}
