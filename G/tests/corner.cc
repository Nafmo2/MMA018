#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const long long INF = 0x1fffffffffffffff;
#define REP(i, n) for (int i = 0; i < n; i++)

const int MIN_N = 2500;
const int MAX_N = 2500;
const int MIN_M = 1;
const int MAX_M = 5000;
const int MIN_A = 1;
const int MAX_A = 1000000000;
const int MIN_C = 1;
const int MAX_C = 1000000000;
int main() {
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  vector<int> ar(MAX_N - 2);
  vector<int> path;
  vector<pair<int, int>> edges;
  iota(ar.begin(), ar.end(), 1);
  std::shuffle(ar.begin(), ar.end(), engine);
  ar.insert(ar.begin(), 0);
  ar.push_back(MAX_N - 1);
  REP(i, MAX_N) {
    if (i == 0) {
      edges.emplace_back(0, 3);
    } else if (i == 1) {
      edges.emplace_back(2, MAX_N - 2);
      edges.emplace_back(1, 2);
      edges.emplace_back(2, 1);
      edges.emplace_back(0, 1);
    } else if (i == MAX_N - 1 || i < 3) {
    } else {
      edges.emplace_back(i, i + 1);
    }
  }
  std::shuffle(edges.begin(), edges.end(), engine);

  cout << MAX_N << " " << edges.size() << endl;
  REP(i, MAX_N) {
    cout << MAX_A;
    if (i != MAX_N - 1) {
      cout << " ";
    } else {
      cout << "\n";
    }
  }
  REP(i, edges.size()) {
    auto [x, y] = edges[i];
    ll cost = 2;
    if (x == 1 && y == 2 || x == 2 && y == 1 || x == 0 && y == 1 ||
        x == 2 && y == MAX_N - 2) {
      cost = MAX_A - 1;
    }
    cout << ar[x] + 1 << " " << ar[y] + 1 << " " << cost << endl;
  }
}
