#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const long long INF = 0x1fffffffffffffff;

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<array<long long, 3>> E;
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    E.push_back({a - 1, b - 1, A[b - 1] - c});
  }
  vector<long long> cost(N, -INF);
  cost[0] = A[0];
  for (int i = 0; i < N - 1; i++) {
    for (auto [from, to, t] : E) {
      if (cost[from] == -INF) continue;
      if (cost[to] < cost[from] + t) {
        cost[to] = cost[from] + t;
      }
    }
  }
  vector<bool> update(N);
  for (int i = 0; i < N; i++) {
    for (auto [from, to, t] : E) {
      if (cost[from] == -INF) continue;
      if (cost[to] < cost[from] + t) {
        update[to] = true;
      }
      if (update[from]) update[to] = true;
    }
  }
  for (int i = 0; i < N; i++) {
    if (update[i]) cost[i] = INF;
  }
  if(cost[N-1] == INF)
    cout<<"inf"<<endl;
  else
    cout<<cost[N-1]<<endl;
}
