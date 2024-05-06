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

const int MIN_N = 1;
const int MAX_N = 100;
const int MIN_M = 1;
const int MAX_M = 100;
const int MIN_A = 1;
const int MAX_A = 1000000000;
const int MIN_B = 1;
const int MAX_B = 1000000000;
const int MIN_C = 1;
const int MAX_C = 100;

void makecase(std::ostream& os, int testcase_idx) {
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  int N = rnd.next(MIN_N, MAX_N);
  int M = rnd.next(MIN_M, MAX_M);
  os << N << ' ' << M << '\n';

  REP(i, N) {
    int a = rnd.next(MIN_A, MAX_A);
    os << a;
    if (i != N - 1)
      os << ' ';
    else
      os << '\n';
  }

  REP(i, M) {
    int b = rnd.next(MIN_B, MAX_B);
    os << b;
    if (i != M - 1)
      os << ' ';
    else
      os << '\n';
  }

  REP(i, M) {
    vector<int> C;
    set<int> kinds;
    int K = rnd.next(1, N);
    os << K << " ";
    ensuref(1 <= K && K <= N, format("{}-th case unsatisfied 1<=K<=N").c_str());
    while (kinds.size() != K) {
      int c = rnd.next(1, N);
      kinds.insert(c);
    }
    for (auto x : kinds) {
      os << x;
      if (x != *kinds.rbegin())
        os << " ";
      else
        os << "\n";
    }
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
  makecase_yukicoder(format("04_max_%02d", t + 1).c_str(), t);
#endif
  return 0;
}
