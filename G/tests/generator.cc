#include <bits/stdc++.h>

#include "testlib.h"
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

// begin templates
void makecase(std::ostream&, int);
void setseed(int testcase_idx) {
  // これだとテストケースを予測されやすいので seed
  // を加工するなどする必要があるかもしれない
  // long long seed = testcase_idx;
  random_device gen;
  long long seed = testcase_idx * gen();
  rnd.setSeed(seed);
}
void makecase_rime(const std::string& filename, int testcase_idx) {
  setseed(testcase_idx);
  std::ofstream ofs(filename);
  makecase(ofs, testcase_idx);
  ofs.close();
}
void makecase_yukicoder(const std::string& filename, int testcase_idx) {
  setseed(testcase_idx);
  makecase(std::cout, testcase_idx);
  std::cerr << filename << std::endl;
}
// end templates

const int MIN_N = 2;
const int MAX_N = 2500;
const int MIN_M = 1;
const int MAX_M = 5000;
const int MIN_A = 1;
const int MAX_A = 1000000000;
const int MIN_C = 0;
const int MAX_C = 1000000000;

void makecase(std::ostream& os, int testcase_idx) {
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  int N = rnd.next(MIN_N, MAX_N);
  int M = rnd.next(MIN_M, min(MAX_M, int(N * (N - 1))));
  os << N << ' ' << M << '\n';
  REP(i, N) {
    int a = rnd.next(MIN_A, MAX_A);
    os << a;
    if (i != N - 1)
      os << ' ';
    else
      os << '\n';
  }
  // ar = 1 と N 以外をhop個だけ選ぶ
  vector<int> ar(N - 1);
  vector<int> path;
  set<pair<int, int>> edges;
  iota(ar.begin(), ar.end(), 1);
  std::shuffle(ar.begin(), ar.end(), engine);
  int prev = 0;
  path.push_back(0);
  REP(i, N - 1) {
    if (edges.size() == M - 1) {
      path.push_back(N - 1);
      edges.insert({prev, N - 1});
      break;
    }
    path.push_back(ar[i]);
    edges.insert({prev, ar[i]});
    prev = ar[i];
    if (ar[i] == N - 1) break;
  }
  while (edges.size() != M) {
    int a = rnd.next(0, N - 1);
    int b = rnd.next(0, N - 1);
    if (a != b && edges.count({a, b}) == 0) {
      edges.insert({a, b});
    }
  }
  vector<pair<int, int>> E;
  for (auto [x, y] : edges) {
    E.emplace_back(x, y);
  }
  shuffle(E.begin(), E.end(), engine);
  REP(i, M) {
    auto [x, y] = E[i];
    int c = rnd.next(MIN_C, MAX_C);
    os << x + 1 << ' ' << y + 1 << ' ' << c << '\n';
  }
}

int main(int argc, char** argv) {
  registerGen(argc, argv, 1);
#ifdef IS_NOT_YUKICODER
  int case_num = 10;
  for (int t = 0; t < case_num; t++) {
    makecase_rime(format("03_random_%02d_r.in", t + 1).c_str(), t);
  }
#else
  int t;
  std::cin >> t;
  // to 0-origin
  --t;
  makecase_yukicoder(format("03_random_%02d", t + 1).c_str(), t);
#endif
  return 0;
}
