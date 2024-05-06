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
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      for (int k = j + 1; k < N; k++) {
        for (int l = k + 1; l < N; l++) {
          modint x=10,y=9,z=7,w=5;
          int res = (x.pow(A[i]) + y.pow(A[j]) + z.pow(A[k]) + w.pow(A[l])).val();
          if(res==Q){
            ans++;
          }
        }
      }
    }
  }
  cout<<ans<<endl;
}
