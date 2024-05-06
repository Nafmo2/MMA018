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

const int MIN_N = 4;
const int MAX_N = 200;
const int MIN_A = 1;
const int MAX_A = 10000000;
const int MIN_P = 2;
const int MAX_P = 1000000000;

void makecase(std::ostream& os, int testcase_idx) {
  int N = rnd.next(MIN_N, MAX_N);
  int P, Q;
  do {
    P = rnd.next(MIN_P, MAX_P);
    Q = rnd.next(MIN_P, MAX_P);
  } while (Q >= P);

  os << N << ' ' << P << ' ' << Q << '\n';
  set<int> S;
  for (int i = 0; i < N; i++) {
    int A = 0;
    do {
      A = rnd.next(MIN_A, MAX_A);
    } while (S.find(A) != S.end());
    S.insert(A);
    os << A;
    if (i != N - 1)
      os << ' ';
    else
      os << '\n';
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
