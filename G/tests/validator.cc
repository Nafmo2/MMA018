#include <bits/stdc++.h>

#include "testlib.h"
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
using ll = long long;

const int MIN_N = 2;
const int MAX_N = 2500;
const int MIN_M = 1;
const int MAX_M = 5000;
const int MIN_A = 1;
const int MAX_A = 1000000000;
const int MIN_C = 1;
const int MAX_C = 1000000000;

int main(int argc, char** argv) {
  registerValidation(argc, argv);
  ll N = inf.readInt(MIN_N, MAX_N, "N");
  inf.readSpace();
  ll M = inf.readInt(MIN_M, min(MAX_M, int(N * (N - 1))), "M");
  ensuref(M <= N * (N - 1), "M <= N * (N-1) is not satisfied");
  inf.readEoln();
  vector<ll> A(N);
  REP(i, N) {
    A[i] = inf.readInt(MIN_A, MAX_A, "A");
    if (i != N - 1)
      inf.readSpace();
    else
      inf.readEoln();
  }
  set<pair<int, int>> edges;
  vector G(N, vector<int>(0));

  REP(i, M) {
    ll a, b, c;
    a = inf.readInt(1, N, "a");
    inf.readSpace();
    b = inf.readInt(1, N, "b");
    inf.readSpace();
    c = inf.readInt(MIN_C, MAX_C, "c");
    inf.readEoln();
    ensuref(a != b, "Contain self-loop");
    ensuref(edges.count({a, b}) == 0, format("{}-th edges already exists", i).c_str());
    edges.insert({a, b});
    G[a - 1].push_back(b - 1);
  }
  ensure(A.size() == N);
  ensure(edges.size() == M);
  stack<int> S;
  vector<bool> visit(N, false);
  S.push(0);
  visit[0] = true;
  while (!S.empty()) {
    int now = S.top();
    S.pop();
    for (auto x : G[now]) {
      if (!visit[x]) {
        visit[x] = true;
        S.push(x);
      }
    }
  }
  ensuref(visit[N - 1], "Not Found 1 to N path");

  inf.readEof();
  return 0;
}
